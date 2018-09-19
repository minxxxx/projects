var	passport	= require('passport');
var bearerStrat	= require('passport-http-bearer').Strategy;
var jwt			= require('jwt-simple');

var secret		= require('../config/secret');
var User		= require('../models/UserModel');
var Hospital	= require('../models/HospitalModel');
var Token		= require('../models/TokenModel');

passport.use(new bearerStrat(
	function (accessToken, callback) {
		console.log('Token Authentication Requested.');
		
		if (!accessToken) {
			console.log('Access attempt made without access token.');
			return (callback(null, false));
		}

		Token.findOne({ Token: accessToken }, function (err, token) {
			if (err) return (callback(err));
			if (!token) return (callback(null, false));

			if (token.Expire <= Date.now()) {
				console.log('Token Expired.');
				Token.findByIdAndRemove(token._id, (err, res) => {  
					if (err) console.log('Failed to delete expired token.'); 
				});
				return (callback(null, false));
			}
			if (token.For === 'Paramedic') {
				User.findOne({ _id: token.UserId }, function (err, user) {
					if (err) return (callback(err));
					if (!user) return (callback(null, false));

					callback(null, user);
				});
			} else if (token.For === 'Hospital') {
				Hospital.findOne({ Code: token.UserId }, function(err, hospital) {
					if (err) return (callback(err));
					if (!hospital) return (callback(null, false));

					callback(null, hospital);
				});
			}
		});
	}
));
exports.isAuthenticated = passport.authenticate('bearer', { session: false });