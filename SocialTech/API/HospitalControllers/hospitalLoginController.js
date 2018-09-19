var loginResponseModel  = require('../models/LoginResponseModel');
var Hospital            = require('../models/HospitalModel');
var Token               = require('../models/TokenModel');
var secret              = require('../config/secret');
var jwt                 = require('jwt-simple');

function expiresIn(hours) {
    var d = new Date();
    return (d.setHours(d.getHours()+ hours));
}

function genToken() {
    var expires = expiresIn(24);
    var token = jwt.encode({
        expires: expires
    }, secret.specialHospitalToken());
    return ({
        token: token,
        expires: expires
    });
}

exports.login = function (req, res) {
    console.log('HospitalLoginRequest: Received New');
    var resp = new loginResponseModel();

    var code = req.body.code || '';
    var password = req.body.password || '';
    var special = req.body.token || '';

    if (code == '' || password == '') {
        resp.status = false;
        resp.error = 'Invalid credentials';
        res.json(resp);
        return ;
    }
    if (special == '' || special !== secret.specialHospitalToken()) {
        resp.status = false;
        resp.error = 'Unauthorized access.';
        res.json(resp);
        return ;
    }

    Hospital.findOne({ Code: code }).exec()
        .then(function (hospital) {
            if (!hospital) {
                resp.status = false;
                resp.error = 'Invalid hospital code or password';
                res.json(resp);
                return ;
            }
            hospital.verifyPassword(password, (err, isMatch) => {
                if (!err && isMatch) {
                    resp.status = true;
                    resp.username = code;
                    resp.token = genToken();

                    var nToken = new Token({
                        UserId: code,
                        For: 'Hospital',
                        Token: resp.token.token,
                        Expire: resp.token.expires
                    });
                    nToken.save((err) => {
                        if (err) {
                            console.log('Failed to save Token.');
                        }
                    });
                    res.json(resp);
                } else {
                    resp.status = false;
                    resp.error = 'Invalid hospital code or password.';
                    res.json(resp);
                }
            });
        });
}

exports.logout = function (req, res) {
    console.log('HospitalLogoutRequest: Received New.');
    Hospital.findOne({ Code: req.body.code }).exec()
    .then((hospt) => {
        if (!hospt) {
            res.json({ status: false });
            return ;
        }

        Token.findOne({ UserId: hospt.Code }).exec()
        .then((token) => {
            if (!token) {
                res.json({ status: true });
                return ;
            }
            
            Token.remove({ _id: token._id }, function (err) {
                if (err) {
                    console.log(err);
                    res.json({ status: true });
                }
                res.json({ status: true });
            })
        })
    });
}