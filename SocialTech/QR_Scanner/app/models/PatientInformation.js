
function PatientInformation() {
    this.firstName = null;
    this.lastName = null;
    this.initial = null;
    this.idNumber = null;
    this.dateOfBirth = null;
    this.gender = null;
    this.race = null;
    this.bloodType = null;

    this.nextOfKinFirstName = null;
    this.nextOfKinLastName = null;
    this.nextOfKinCellNumber = null;

    this.medicalAid = null;
    this.medicalAidNumber = null;

    this.allergies = null;
    this.history = null;
    this.chronicMedication = null;
};

module.exports = PatientInformation;