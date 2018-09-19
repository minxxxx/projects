var mongoose    = require('mongoose');
var bcrypt      = require('bcrypt-nodejs');

var UserSchema = new mongoose.Schema({
    HPCSANumber:    { type: String, required: true, unique: true },
    Email:          { type: String, required: true },
    Username:       { type: String, required: true, unique: true },
    Password:       { type: String, required: true },
    JoinDate:       { type: Date, required: true }
});

UserSchema.pre('save', function (callback) {
    var user = this;

    if (!user.isModified('Password')) return (callback);
    bcrypt.genSalt(5, function (err, salt) {
        if (err) return (callback(err));
        bcrypt.hash(user.Password, salt, null, function (err, hash) {
            if (err) return (callback(err));
            user.Password = hash;
            callback();
        });
    });
});

UserSchema.methods.verifyPassword = function(password, callback) {
    bcrypt.compare(password, this.Password, function (err, isMatch) {
        if (err) return (callback(err));
        callback(null, isMatch);
    });
};

module.exports = mongoose.model('User', UserSchema);