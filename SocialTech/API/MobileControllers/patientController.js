var PatientResponse = require('../models/PatientResponseModel.js');

exports.getPatientById = function(req, res) {
	var patientResp = new PatientResponse();

	if (!req.body.id || req.body == undefined) {
		patientResp.status = false;
		patientResp.message = 'No ID Number provided.'
		res.json(patientResp);
		return ;
	}
	console.log('Looking for Patient with Id: %s', req.body.id);

	/**Do some form of call here to get the data.**/

	patientResp.status = true;
	patientResp.message = null;
	patientResp.patient.initial = "Mr."
	patientResp.patient.firstName = 'Nathan';
	patientResp.patient.lastName = 'Doe';
	patientResp.patient.idNumber = "0000000000000";
	patientResp.patient.dateOfBirth = "1994-06-06";
	patientResp.patient.gender = "Male";
	patientResp.patient.race = "Coulered";

	patientResp.patient.nextOfKinFirstName = "Anikin";
	patientResp.patient.nextOfKinLastName = "Skywalker";
	patientResp.patient.nextOfKinCellNumber = "012 345 6789";
	
	patientResp.patient.medicalAid = "Bonitas";
	patientResp.patient.medicalAid = "00001 ABC";
	patientResp.patient.allergies = "Allergic to bee sting";
	patientResp.patient.history = "None";
	patientResp.patient.chronicMedication = "Chronic Asthma";
	res.json(patientResp);
}