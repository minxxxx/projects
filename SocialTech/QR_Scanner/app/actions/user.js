import * as types from './types';
import API from '../lib/api';
import * as NavigationActions from './navigation';
import * as NotificationActions from './notification';
import * as AuthActions from './auth';
import CONSTANTS from '../constants';

export function signup(newUser) {
    return (dispatch, getState) => {
        API.post(CONSTANTS.API_ENDPOINTS.USER, newUser)
        .then((resp) => {
            let json = JSON.parse(resp._bodyText);
            if (json.status) {
                dispatch(NavigationActions.navigateToScene(getState(), 'Login', types.NAVIGATION_LOGIN));
            } else {
                dispatch(NotificationActions.setNotificationState(true, json.error));
            }
        })
        .catch((ex) => {
            console.log(ex);
        });
    };
}

export function updateUser(updatedUser, oldUser) {
    var body = {
        oldUsername: oldUser.Username,
        hpcsaNumber: updatedUser.hpcsaNumber,
        username: updatedUser.username,
        passwordChanged: updatedUser.passwordChanged,
        password: updatedUser.password, 
        email: updatedUser.email
    };

    return (dispatch, getState) => {
        var authToken = getState().loggedIn.token;
        API.put(CONSTANTS.API_ENDPOINTS.USER, body, authToken)
        .then((resp) => {
            if (resp.status == false) {
                dispatch(NotificationActions.setNotificationState(true, resp.error));
            } else {
                dispatch(NotificationActions.setNotificationState(true, 'Updated User Info'));
                var json = {
                    status: true,
                    username: updatedUser.username,
                    user: {
                        Username: updatedUser.username,
                        HPCSANumber: updatedUser.hpcsaNumber,
                        Email: updatedUser.email,
                        Password: '',
                    },
                    error: null,
                    token: authToken
                };
                dispatch(AuthActions.setLoggedInState({ state: json }));
            }
        })
        .catch((err) => { 
            console.error('An error occured updating the user', err);
            dispatch(NotificationActions.setNotificationState(true, 'Failed to Update.'));
        });
    };
}

export function forgotPassword(body) {
    return (dispatch, getState) => {
        API.post(CONSTANTS.API_ENDPOINTS.FORGOT_PWD, body, null)
        .then((resp) => {
            let json = JSON.parse(resp._bodyText);
            console.log(json);
            if (json.status == true) {
                dispatch(NotificationActions.setNotificationState(true, 'Reset Password Successful. Check your e-mails for new password.'));
                dispatch(NavigationActions.navigateToScene(getState(), 'Login', types.NAVIGATION_LOGIN));
            } else {
                dispatch(NotificationActions.setNotificationState(true, 'Invalid HPCSA Number or E-mail.'));
            }
        })
        .catch((err) => {
            console.error('An error occured reseting the password', err);
            dispatch(NotificationActions.setNotificationState(true, 'Failed to reset Password.'));
        });
    };
}