import createReducer from '../lib/createReducer';
import * as types from '../actions/types';

export const notification = createReducer({ available: false, message: null}, {
    [types.SET_NOTIFICATION](state, action) {
        return ({
            available: action.state.available,
            message: action.state.message
        });
    }
});