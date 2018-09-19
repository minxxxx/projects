var mongoose = require('mongoose');
var bcrypt = require('bcrypt-nodejs');

var HospitalSchema = new mongoose.Schema({
    FullName: { type: String, required: true },
    Code: { type: String, required: true, unique: true },
    Password: { type: String, required: true },
    Longitude: { type: Number },
    Latitude: { type: Number },
    StreetAddress: { type: String, required: true },
    City: { type: String, required: true },
    Province: { type: String, required: true },
    Country: { type: String, required: true, default: 'RSA' }
});

HospitalSchema.pre('save', function (callback) {
    var hospital = this;

    if (!hospital.isModified('Password')) return (callback);
    bcrypt.genSalt(5, function (err, salt) {
        if (err) return (callback(err));
        bcrypt.hash(hospital.Password, salt, null, function (err, hash) {
            if (err) return (callback(err));
            hospital.Password = hash;
            callback();
        });
    });
});

HospitalSchema.methods.verifyPassword = function (password, callback) {
    bcrypt.compare(password, this.Password, function(err, isMatch) {
        if (err) return (callback(err));
        callback(null, isMatch);
    });
};

module.exports = mongoose.model('Hospital', HospitalSchema);