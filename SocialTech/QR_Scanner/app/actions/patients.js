import * as types from './types';
import API from '../lib/api';
import * as navigationActions from './navigation'
import * as NotificationActions from './notification';
import CONSTANTS from '../constants';

var patientInformation = require('../models/PatientInformation');

function findFromAPI(id) {

}

function getInitial(initial) {
    switch (initial) {
        case "1": return 'Mrs.';
        case "2": return 'Ms.';
        case "0":
        default: return 'Mr.';
    }
}

function getRace(race) {
    switch (race) {
        case "0": return 'White';
        case "1": return 'Black';
        case "2": return 'Indian';
        case "3": return 'Coloured';
        case "4":
        default: return 'Other';
    }
}

function getBloodType(blood) {
    switch (blood) {
        case "0": return 'Not Sure';
        case "1": return 'A+';
        case "2": return 'A-';
        case "3": return 'B+';
        case "4": return 'B-';
        case "5": return 'AB+';
        case "6": return 'AB-';
        case "7": return 'O+';
        case "8": return 'O-';
        default: return 'Not Sure';
    }
}

export function addFromQRCode(data) {
    var patient = new  patientInformation();
    var rawData = data.split('|');

    patient.firstName   = rawData[0];
    patient.lastName    = rawData[1];
    patient.initial     = getInitial(rawData[2]);
    patient.idNumber    = rawData[3];
    patient.dateOfBirth = rawData[4];
    patient.gender      = rawData[5] === 'M' ? 'Male' : 'Female';
    patient.race        = getRace(rawData[6]);
    patient.bloodType   = getBloodType(rawData[7]);

    patient.nextOfKinFirstName  = rawData[8];
    patient.nextOfKinLastName   = rawData[9];
    patient.nextOfKinCellNumber = rawData[10];

    patient.medicalAid          = rawData[11];
    patient.medicalAidNumber    = rawData[12];

    patient.allergies           = rawData[13];
    patient.history             = rawData[14];
    patient.chronicMedication   = rawData[15];
    return {
        type: types.ADD_PATIENT_HISTORY,
        patient
    }
}

export function addPatient(patient) {
    return {
        type: types.ADD_PATIENT_HISTORY,
        patient
    }
}

export function addFromIDNumber(idNumber) {
    return (dispatch, getState) => {
        if (CONSTANTS.USE_API) {
            /* PRODUCTION */
            API.post(CONSTANTS.API_ENDPOINTS.PATIENT, { id: idNumber}, getState().loggedIn.token)
            .then((resp) => {
                let json = JSON.parse(resp._bodyText);
                dispatch(addPatient(json.patient));
                dispatch(navigationActions.navigateToScene(getState(), 'PatientDetails', types.NAVIGATION_PATIENT_DETAILS));
            })
            .catch((err) => {
                console.log(err);
            });
        } else {
            /* DEBUG & MVP */
            var patient = new patientInformation();
            patient.firstName = 'John';
            patient.lastName = 'Doe';
            patient.initial = 'Mr.';
            patient.idNumber = '0000000000000';
            patient.dateOfBirth = '25-01-1990'
            patient.gender = 'Male';
            patient.race = 'White';
            patient.bloodType = 'O+';
        
            patient.nextOfKinFirstName = 'Jane';
            patient.nextOfKinLastName = 'Doe';
            patient.nextOfKinCellNumber = '012 345 6789';
        
            patient.medicalAid = 'Discovery Health';
            patient.medicalAidNumber = '9876543210';
        
            patient.allergies = 'Bee stings';
            patient.history = 'Knee cap operation.';
            patient.chronicMedication = 'None';
            var json = {
                status: true,
                patient: patient,
                error: null
            };
            if (idNumber !== '0000000000000') {
                dispatch(NotificationActions.setNotificationState(true, 'No Patient Details found. Please Scan QR Code.'));
            } else {
                dispatch(addPatient(json.patient));
                dispatch(navigationActions.navigateToScene(getState(), 'PatientDetails', types.NAVIGATION_PATIENT_DETAILS));
            }
        }
    }   
}

export function clearAllPatients() {
    return {
        type: types.CLEAR_PATIENT_HISTORY,
    }
}

export function setSelectedPatient(index) {
    return {
        type: types.SET_SELECTED_PATIENT,
        index
    }
}