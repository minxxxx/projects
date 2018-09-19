import * as types from './types';

export function navigate(action) {
    return (dispatch, getState) => {
        if (action == types.NAVIGATION_LOGIN)
            return dispatch(navigateToScene(getState(), 'Login', types.NAVIGATION_LOGIN));
        else if (action == types.NAVIGATION_SIGNUP)
            return dispatch(navigateToScene(getState(), 'Signup', types.NAVIGATION_SIGNUP));
        else if (action == types.NAVIGATION_SCAN_ID)
            return dispatch(navigateToScene(getState(), 'ScanID', types.NAVIGATION_SCAN_ID));
        else if (action == types.NAVIGATION_SCAN_QR)
            return dispatch(navigateToScene(getState(), 'ScanQR', types.NAVIGATION_SCAN_QR));
        else if (action == types.NAVIGATION_PATIENT_HISTORY)
            return dispatch(navigateToScene(getState(), 'PatientHistory', types.NAVIGATION_PATIENT_HISTORY));
        else if (action == types.NAVIGATION_PATIENT_DETAILS)
            return dispatch(navigateToScene(getState(), 'PatientDetails', types.NAVIGATION_PATIENT_DETAILS));
        else if (action == types.NAVIGATION_PROFILE)
            return dispatch(navigateToScene(getState(), 'Profile', types.NAVIGATION_PROFILE));
        else if (action == types.NAVIGATION_HOSPITAL_LIST)
            return dispatch(navigateToScene(getState(), 'HospitalList', types.NAVIGATION_HOSPITAL_LIST));
        else if (action == types.NAVIGATION_FORGOT_PASSWORD)
            return dispatch(navigateToScene(getState(), 'ForgotPassword', types.NAVIGATION_FORGOT_PASSWORD));

        dispatch(navigateToScene(getState(), 'Login', types.NAVIGATION_LOGIN));
    }
}

export function navigateToScene(oldState, scene, type) {
    let state = Object.assign({}, oldState);
    state.route = scene;
    return {
        type: type,
        state
    }
}