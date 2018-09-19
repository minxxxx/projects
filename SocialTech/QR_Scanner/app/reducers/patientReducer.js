import createReducer from '../lib/createReducer';
import * as types from '../actions/types';

export const patients = createReducer({ patientHistoryCount: 0, patientHistory: [], selectedPatient: -1 }, 
{
    [types.ADD_PATIENT_HISTORY](state, action) {
        var newState = {
            patientHistory: state.patientHistory,
            patientHistoryCount: state.patientHistoryCount,
            selectedPatient: state.selectedPatient
        };
        for (var i = 0; i < newState.patientHistoryCount; i++) {
            //Check on the ID Number
            if (newState.patientHistory[i].idNumber == action.patient.idNumber) {
                newState.selectedPatient = i;
                return (newState);
            }
            //Check on the First and Last Name.
            if (newState.patientHistory[i].firstName == action.patient.firstName 
                && newState.patientHistory[i].lastName == action.patient.lastName) {
                newState.selectedPatient = i;
                return (newState);
            }
        }
        newState.patientHistory.push(action.patient);
        newState.patientHistoryCount += 1;
        newState.selectedPatient = newState.patientHistory.length - 1;
        return (newState);
    },
    [types.SET_SELECTED_PATIENT](state, action) {
        var newState = {
            patientHistory: state.patientHistory,
            patientHistoryCount: state.patientHistoryCount,
            selectedPatient: action.index
        };
        return (newState);
    },
    [types.CLEAR_PATIENT_HISTORY](state) {
        var newState = {
            patientHistory: [],
            patientHistoryCount: 0,
            selectedPatient: -1
        }
        return (newState);
    }
})