
var Patient = require('./PatientModel.js');

function PatientResponse() {
	this.status = false;
	this.message = null;
	this.patient = new Patient();
}

module.exports = PatientResponse;