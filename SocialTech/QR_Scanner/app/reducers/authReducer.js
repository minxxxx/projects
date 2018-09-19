import createReducer from '../lib/createReducer';
import * as types from '../actions/types';

export const loggedIn = createReducer({ loggedIn: false, username: null, user: null, token: null }, {
    [types.SET_LOGIN_STATE](state, action) {
        return ({
            loggedIn: action.state.status,
            username: action.state.username,
            user: action.state.user,
            token: action.state.status ? 
                (action.state.token.token || action.state.token): null
        });
    }
});