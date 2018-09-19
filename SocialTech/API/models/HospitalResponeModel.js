var PatientModel = require('./PatientModel.js');

function HospitalResponseModel() {
    this.code = null;
    this.patient = new PatientModel();
    this.scannedAt = null;
    this.eta = null;
}

module.exports = HospitalResponseModel;