
function PatientInformation() {
    this.firstName = "";
    this.lastName = "";
    this.initial = "";
    this.idNumber = "";
    this.dateOfBirth = "";
    this.gender = "";
    this.race = "";
    this.bloodType = "";

    this.nextOfKinFirstName = "";
    this.nextOfKinLastName = "";
    this.nextOfKinCellNumber = "";

    this.medicalAid = "";
    this.medicalAidNumber = "";

    this.allergies = "";
    this.history = "";
    this.chronicMedication = "";
};

module.exports = PatientInformation;