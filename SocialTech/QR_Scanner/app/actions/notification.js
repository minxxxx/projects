import * as types from './types';

export function setNotificationState(available, message) {
    let state = {
        available: available,
        message: message
    };
    return {
        type: types.SET_NOTIFICATION,
        state
    }
}