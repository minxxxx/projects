import createReducer from '../lib/createReducer';
import * as types from '../actions/types';

export const navigationState = createReducer({ previousRoute: '', route: 'Login' }, {
    [types.NAVIGATION_LOGIN](state, action) {
        return ({
            previousRoute: state.route,
            route: action.state.route
        });
    },
    [types.NAVIGATION_SIGNUP](state, action) {
        return ({
            previousRoute: state.route,
            route: action.state.route
        });return (action.state);
    },
    [types.NAVIGATION_SCAN_ID](state, action) {
        return ({
            previousRoute: state.route,
            route: action.state.route
        });
    },
    [types.NAVIGATION_SCAN_QR](state, action) {
        return ({
            previousRoute: state.route,
            route: action.state.route
        });
    },
    [types.NAVIGATION_PATIENT_HISTORY](state, action) {
        return ({
            previousRoute: state.route,
            route: action.state.route
        });
    },
    [types.NAVIGATION_PATIENT_DETAILS](state, action) {
        return ({
            previousRoute: state.route,
            route: action.state.route
        });
    },
    [types.NAVIGATION_HOSPITAL_LIST](state, action) {
        return ({
            previousRoute: state.route,
            route: action.state.route
        });
    },
    [types.NAVIGATION_PROFILE](state, action) {
        return ({
            previousRoute: state.route,
            route: action.state.route
        });
    },
    [types.NAVIGATION_FORGOT_PASSWORD](state, action) {
        return ({
            previousRoute: state.route,
            route: action.state.route
        });
    }
});