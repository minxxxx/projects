var nodemailer      = require('nodemailer');
var smtpTransport   = require('nodemailer-smtp-transport');
var secret          = require('../config/secret');

exports.emailQRCode = function (req, res) {
    console.log("QR-Code E-mail Request.");
    var resp = {
        status: false,
        err: null
    };

    var email = req.body.email || '';
    var qrCode64Base = req.body.qrCode64Base || '';
    var special = req.body.token || '';

    if (qrCode64Base == '' || email == '') {
        resp.status = false;
        resp.err = 'Invalid content.';
        res.json(resp);
        return ;
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
                <H2>Dear User,</H2>
                <p>Please find attached you QR-Code.</p>
                <p>Kind Regards,<br/>ER-QR Staff</p>
            </body>
        </html>`;
    var mailOptions = {
        from: 'exallowen@gmail.com',
        to: email,
        subject: 'ER-QR QR-Code',
        html: htmlText,
        attachments: [{
            path: qrCode64Base
        }]
    };
    transporter.sendMail(mailOptions, (err, info) => {
        if (err) {
            console.log(err);
            resp.status = false;
            resp.err = 'Failed to Send e-mail.';
            res.json(resp);
            return ;
        }
        resp.status = true;
        resp.err = null;
        res.json(resp);
    });
}