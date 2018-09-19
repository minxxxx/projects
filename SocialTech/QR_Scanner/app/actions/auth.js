import * as types from './types';
import API from '../lib/api';
import * as NavigationActions from './navigation';
import * as NotificationActions from './notification';
import * as PatientActions from './patients';
import CONSTANTS from '../constants';

export function login(credentials) {    
    return (dispatch, getState) => {
        if (CONSTANTS.USE_API) {
            API.post(CONSTANTS.API_ENDPOINTS.LOGIN, credentials, '')
            .then((resp) => {
                let json = JSON.parse(resp._bodyText);
                dispatch(setLoggedInState({ state: json }));
                if (json.status) {
                    dispatch(NavigationActions.navigateToScene(getState(), 'ScanID', types.NAVIGATION_SCAN_ID));
                } else {
                    dispatch(NotificationActions.setNotificationState(true, 'Invalid username or password.'));
                }
            }).catch((ex) => {
                dispatch(NotificationActions.setNotificationState(true, 'Invalid username or password.'));
            });
        } else {
            var json = {
                status: true,
                username: '0000',
                user: {
                    Username: '0000',
                    HPCSANumber: '000000',
                    Email: 'test@test.co.za',
                    Password: 'hahahahahahahahahahahahahahahahahahahahahahah debug'
                },
                error: null,
                token: {
                    token: '1234567890'
                }
            };
            if (credentials.username === '0000' && credentials.password === '0000') {
                dispatch(setLoggedInState({ state: json }));
                dispatch(NavigationActions.navigateToScene(getState(), 'ScanID', types.NAVIGATION_SCAN_ID));
            } else {
                json.status = false;
                json.username = null;
                json.error = 'Invalid Credentials.';
                dispatch(setLoggedInState({ state: json }));
                dispatch(NotificationActions.setNotificationState(true, 'Invalid username or password.'));
            }
        }       
    }
}

export function logout(username) {
    return (dispatch, getState) => {
        if (CONSTANTS.USE_API) {
            API.post(CONSTANTS.API_ENDPOINTS.LOGOUT, { username: username }, getState().loggedIn.token)
            .then((resp) => {
                let json = JSON.parse(resp._bodyText);
                if (json.status) {
                    dispatch(setLoggedInState({ state: { status: false, username: null, user: null, error: null, token: { token: null } } }));
                    dispatch(PatientActions.clearAllPatients());
                    dispatch(NavigationActions.navigateToScene(getState(), 'Login', types.NAVIGATION_SCAN_ID));
                }
            }).catch((ex) => {
                console.log(ex);
            });
        } else {
            dispatch(setLoggedInState({ state: { status: false, username: null, user: null, error: null, token: { token: null } } }));
            dispatch(PatientActions.clearAllPatients());
            dispatch(NavigationActions.navigateToScene(getState(), 'Login', types.NAVIGATION_SCAN_ID));
        }
    }
}

export function setLoggedInState({ state }) {
    return {
        type: types.SET_LOGIN_STATE,
        state
    };
}