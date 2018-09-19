import createReducer from '../lib/createReducer';
import * as types from '../actions/types';

export const hospitals = createReducer({selected: -1, list: [] },
{
    [types.SET_HOSPITALS](state, action) {
        var newState = {
            selected: -1,
            list: action.hospitals
        };
        return (newState);
    },
    [types.SET_SELECTED_HOSPITAL](state, action) {
        var newState = {
            selected: action.index,
            list: state.list
        };
        return (newState);
    }
})