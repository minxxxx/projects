export var itemsReducer = (state = [], action) => {
  switch (action.type) {
    case 'ADD_ITEM':
      return [
        ...state,
        action.item
      ]
    default:
      return state;
  }
}

export var usersReducer = (state = '', action) => {
  switch (action.type) {
    case 'LOGIN_USER':
		return action.username;
	case 'LOGOUT_USER':
		return '';
    default:
    	return state;
  }
}

export var loadReducer = (state = false, action) => {
	switch (action.type) {
		case 'START_LOAD':
			return true;
		case 'STOP_LOAD':
			return false;
		default:
			return state;
	}
}
