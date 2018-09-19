var loginResponseModel  = require('../models/LoginResponseModel');
var User                = require('../models/UserModel');
var Token               = require('../models/TokenModel');
var secret              = require('../config/secret');
var jwt                 = require('jwt-simple');

function genToken() {
    var expires = expiresIn(12);
    var token = jwt.encode({
        expires: expires
    }, secret.secretToken());
    return ({
        token: token,
        expires: expires
    });
}

function expiresIn(hours) {
    var d = new Date();
    return (d.setHours(d.getHours()+ hours));
}

exports.login = function(req, res) {
    console.log('LoginRequest: Received New.'); //TODO: Remove for PROD.
    var resp = new loginResponseModel();

    var username = req.body.username || '';
    var password = req.body.password || '';
    var special = req.body.token || ''

    if (username == '' || password == '') {
        resp.status = false;
        resp.error = 'Invalid credentials.';
        res.json(resp);
        return ;
    }
    if (special == '' || special !== secret.specialToken()) {
        resp.status = false;
        resp.error = 'Invalid credentials.';
        res.json(resp);
        return ;
    }
    
    User.findOne({ Username: username }).exec()
        .then(function (user) {
            if (!user) {
                resp.status = false;
                resp.error = 'Invalid username or password.';
                res.json(resp);
                return ;
            }

            user.verifyPassword(password, (err, isMatch) => {
                if (!err && isMatch) {
                    resp.status = true;
                    resp.username = user.Username;
                    resp.user = user;
                    resp.token = genToken();

                    var nToken = new Token({
                        UserId: user._id,
                        For: 'Paramedic',
                        Token: resp.token.token,
                        Expire: resp.token.expires
                    });
                    nToken.save((err) => {
                        if (err) {
                            console.log('Failed to save token.');
                        }
                    });

                    res.json(resp);
                } else {
                    resp.status = false;
                    resp.error = 'Invalid username or password.';
                    res.json(resp);
                }
            });
        })
        .catch(function (err) {
            resp.status = false;
            resp.error = 'Invalid username or password.';
            res.json(resp);
        });
};

exports.logout = function (req, res) {
    User.findOne({ Username: req.body.username }).exec()
    .then((user) => {
        if (!user) {
            res.json({ status: false });
            return ;
        }

        Token.findOne({ UserId: user._id }).exec()
        .then((token) => {
            if (!token) {
                res.json({ status: true });
                return ;
            }

            Token.remove({ _id: token._id }, function (err) {
                if (err) {
                    console.log(err);
                    return ;
                }
                res.json({ status: true });
            });
        });
    });
};