var Hospital    = require('../models/HospitalModel');

exports.getHospitals = function(req, res) {
    Hospital.find({}, { _id: 0, Password: 0 }, (err, hospitals) => {
        if (hospitals) {
            res.json(hospitals);
            return ;
        }
        res.json({});
    }).limit(5);
}