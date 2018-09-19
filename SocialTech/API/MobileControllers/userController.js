var User                = require('../models/UserModel');
var loginResponseModel  = require('../models/LoginResponseModel.js');
var bcrypt              = require('bcrypt-nodejs');
var nodemailer          = require('nodemailer');
var smtpTransport       = require('nodemailer-smtp-transport');

/**REQUIRED BODY FOR REQUEST:
 * hpcsaNumber: Number
 * username: String
 * password: String
 * hpscaNumber: String
 * email: String
 * 
 * FORMAT: json or form data
 * 
 * RETURNS: {
 *      status: Boolean,
 *      username: String,
 *      error: String
 * }
 */
exports.newUser = function(req, res) {
    var user = new User({
        HPCSANumber: req.body.hpcsaNumber,
        Email: req.body.email,
        Username: req.body.username,
        Password: req.body.password,
        JoinDate: new Date()
    });

    /**CHECK THE HPCSA NUMBER HERE! IMPORTANT */

    user.save(function(err) {
        var resp = new loginResponseModel();
        if (err && err.code == 11000) {
            resp.status = false;
            resp.username = null;
            resp.error = 'HPCSA Number or Username already exists.';
            res.json(resp);
            return ;
        } else if (err) {
            resp.status = false;
            resp.username = null;
            resp.error = err;
            res.json(resp);
            return ;
        }
        resp.status = true;
        resp.username = user.Username;
        resp.error = null;
        res.json(resp);
        return ;
    });
}

/**REQUIRED BODY FOR REQUEST:
 * oldUsername: String
 * hpcsaNumber: Number
 * username: String
 * passwordChanged: Boolean
 * password: String
 * hpscaNumber: String
 * email: String
 * 
 * FORMAT: json or form data
 * 
 * RETURNS: {
 *      status: Boolean,
 *      username: String,
 *      error: String
 * }
 */
exports.updateUser = function (req, res) {
    var resp = new loginResponseModel();
    User.findOne({ Username: req.body.oldUsername }).exec()
        .then(function (user) {
            if (user) {
                if (req.body.passwordChanged)
                    updateUserWithPassword(req, res, user, resp);
                else
                    updateUserWithoutPassword(req, res, user, resp);
            } else {
                resp.status = false;
                resp.error = 'Could not find user with provided username';
                res.json(resp);
            }
        })
        .catch(function (err) {
            resp.status = false;
            resp.username = null;
            resp.error = err;
            res.json(resp);
            return ;
        });
}

function updateUserWithPassword(req, res, user, resp) {
    bcrypt.genSalt(5, function (err, salt) {
        bcrypt.hash(req.body.password, salt, null, function (err, hash) {
            User.update({ _id : user._id },
                {
                    Username: req.body.username,
                    HPCSANumber: req.body.hpcsaNumber,
                    Email: req.body.email,
                    Password: hash
                }, function (err, num, raw) {
                    if (err) {
                        resp.status = false;
                        resp.username = null;
                        resp.error = 'Failed to Update user.';
                        res.json(resp);
                        return ;
                    } else {
                        resp.status = true;
                        resp.username = req.body.username;
                        resp.user = user;
                        resp.error = null;
                        res.json(resp);
                        return ;
                    }
                });
        });
    });
}

function updateUserWithoutPassword(req, res, user, resp) {
    User.update({ _id : user._id },
        {
            Username: req.body.username,
            HPCSANumber: req.body.hpcsaNumber,
            Email: req.body.email
        }, function (err, num, raw) {
            if (err) {
                resp.status = false;
                resp.username = null;
                resp.error = 'Failed to Update user.';
                res.json(resp);
                return ;
            } else {
                resp.status = true;
                resp.username = req.body.username;
                resp.user = user;
                resp.error = null;
                res.json(resp);
                return ;
            }
        });
}

/**REQUIRED BODY FOR REQUEST:
 * hpcsaNumber: Number
 * username: String
 * 
 * FORMAT: json or form data
 * 
 * RETURNS: {
 *      status: Boolean,
 *      username: String,
 *      error: String
 * }
 */
exports.deleteUser = function (req, res) {
    var resp = new loginResponseModel();
    User.findOneAndRemove({
        HPCSANumber: req.body.hpcsaNumber,
        Username: req.body.username
    }).exec()
        .then((user) => {
            if (user) {
                resp.status = true;
                resp.username = user.Username;
                resp.error = null;
                res.json(resp);
            } else {
                resp.status = false;
                resp.username = null;
                resp.error = 'Could not find user with this username & HPCSA number.';
                res.json(resp);
            }
        })
        .catch((err) => {
            resp.status = false;
            resp.username = null;
            resp.error = err;
            res.json(resp);
        });
}

/**REQUIRED BODY FOR REQUEST:
 * username: String
 * 
 * FORMAT: json or form data
 * 
 * RETURNS: {
 *      status: Boolean,
 *      User: {
 *          Username: String
 *          Email: String,
 *          HPCSA Number: Number,
 *      }
 * }
 */
exports.getUser = function (req, res) {
    var resp = {
        status: false,
        User: null,
        error: null
    };
    User.findOne({ Username: req.params.username },
        { 'Username': true, 'Email': true, 'HPCSANumber': true }).exec()
        .then(function (user) {
            if (user) {
                resp.status = true;
                resp.User = user;
                res.json(resp);
            } else {
                resp.error = 'Could not find user.';
                res.json(resp);
            }
        })
        .catch(function (err) {
            resp.status = false;
            resp.error = 'Could not find user.';
            res.json(resp);
        })
}

/**REQUIRED BODY FOR REQUEST:
 * hcpsaNumber: String
 * email: String
 * 
 * FORMAT: json or form data
 * 
 * RETURNS: {
 *      status: Boolean,
 *      err: any
 * }
 */
exports.resetPassword = function (req, res) {
    var resp = {
        status: false,
        err: null,
    };
    console.log('Reset Password Request');
    User.findOne({ HPCSANumber: req.body.hcpsaNumber, Email: req.body.email }).exec()
    .then((user) => {
        if (user) {
            var key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz#@%&";
            var rndPwd = "";
            
            for (var i = 0; i < 8; i++) {
                rndPwd += key.charAt(Math.random() * 66);
            }

            var transporter = nodemailer.createTransport(smtpTransport({
                service: 'gmail',
                auth: {
                    user: 'exallowen@gmail.com',
                    pass: ''
                }
            }));
            var htmlText = 
                `<html>
                    <head></head>
                    <body>
                        <H2>Hello ${user.Username}</H2>
                        <p>You have requested a password reset. Please see below your new password. Please reset this at your earliest convenience.</p>
                        <br />
                        New Password: <b>${rndPwd}</b>
                        <br/>
                        <p>Kind Regards, <br/>ER-QR Staff</p>
                    </body>
                </html>`;
            var mailOptions = {
                from: 'exallowen@gmail.com',
                to: user.Email,
                subject: 'ER-QR Password Reset',
                html: htmlText
            };
            transporter.sendMail(mailOptions, (err, info) => {
                if (err) {
                    console.log(err);
                    resp.status = false;
                    res.json(resp);
                    return ;
                } else { 
                    bcrypt.genSalt(5, function (err, salt) {
                        bcrypt.hash(rndPwd, salt, null, function (err, hash) {
                            User.update({_id: user._id}, { Password: hash }, function (err, num, raw) {
                                if (!err) {
                                    resp.status = true;
                                    res.json(resp);
                                    return ;
                                }
                                else {
                                    resp.status = false;
                                    resp.err = "Failed to reset password.";
        
                                    var errMailOptions = {
                                        from: 'exallowen@gmail.com',
                                        to: user.email,
                                        subject: 'ER-QR Password Reset Failed.',
                                        html: `
                                            <body>
                                                <head></head>
                                                <body>
                                                    <h2>Hello ${user.username}</h2>
                                                    <p>We regret to inform you that the password reset has failed. Sorry for the inconvenience.<p>
                                                    <p>Kind Regards, <br/> ER-QR Staff</p>
                                                </body>
                                            </body>
                                        `
                                    };
                                    transporter.sendMail(errMailOptions);
        
                                    res.json(resp);
                                    return ;
                                }
                            });
                        });
                    });
                }
            });
        } else {
            resp.err = "Could not find user.";
            res.json(resp);
        }
    });
}