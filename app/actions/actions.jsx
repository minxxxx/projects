import moment from 'moment';
import firebase, {firebaseItem, firebaseRef, firebaseAuth, googleProvider, facebookProvider, twitterProvider} from 'app/firebase';
import reactHistory from 'reactHistory';

export var startAddItem = () => {
	console.log('Adding item to firebase')
}

export var addItem = (item) => {
	return {
		type: 'ADD_ITEM',
		item
	}
}

//user management

export var startRegisterUser = (username, password1, password2) => {
	console.log('Adding user to firebase.');
	if (password1 != password2) {
		alert("Passwords do not match.");
	} else {
		return (dispatch, getState) => {
			var userRef = firebaseAuth.createUserWithEmailAndPassword(username, password1);

			return userRef.then(() => {
				console.log('User has been added to firebase!');
				reactHistory.push('/login')
			}, (e) => {
				alert('Error: ' + e.message);
				console.log('Error when adding user:', e.message);
			});
		}
	}
}

export var loginUser = (username) => {
	return {
		type: 'LOGIN_USER',
		username
	}
}

export var initUser = () => {
	return (dispatch) => {
		firebaseAuth.onAuthStateChanged((user) => {
			if (user) {
				//user loggin in
				console.log('user in');
				var username = user.email;
				dispatch(loginUser(username.substr(0, username.indexOf('@'))));
			} else {
				//not logged in
				console.log('user out');
				dispatch(logoutUser());
			}
		});
	}
}

export var startLoginUser = (username, password) => {
	console.log('Logging in user:', username);
	return (dispatch, getState) => {
		var signInRef = firebaseAuth.signInWithEmailAndPassword(username, password);

		return signInRef.then(() => {
			console.log('Sign in successfull');
			dispatch(stopLoading());
			dispatch(loginUser(username.substr(0, username.indexOf('@'))));
			reactHistory.push('/');
		}, (e) => {
			alert('Error: ' + e.message);
			dispatch(stopLoading());
			console.error('Error signing in user:', e.message);
		});
	}
}

export var googleLogin = () => {
	return () => {
		var googleRef = firebaseAuth.signInWithPopup(googleProvider);

		return googleRef.then(() => {
			reactHistory.push('/');
			console.log('Sign in successfull');
		}, (e) => {
			console.error("Error with Google login:", e.message);
			alert('Error: ' + e.message);
		});
	}
}

export var facebookLogin = () => {
	return () => {
		var facebookRef = firebaseAuth.signInWithPopup(facebookProvider);

		return facebookRef.then(() => {
			reactHistory.push('/');
			console.log('Sign in successfull');
		}, (e) => {
			console.error("Error with Facebook login:", e.message);
			alert('Error: ' + e.message);
		});
	}
}

export var twitterLogin = () => {
	return () => {
		var twitterRef = firebaseAuth.signInWithPopup(twitterProvider);

		return twitterRef.then(() => {
			reactHistory.push('/');
			console.log('Sign in successfull');
		}, (e) => {
			console.error("Error with Twitter login:", e.message);
			alert('Error: ' + e.message);
		});
	}
}

export var logoutUser = () => {
	return {
		type: 'LOGOUT_USER'
	}
}

export var startLogoutUser = () => {
	return (dispatch) => {
		return firebaseAuth.signOut().then(() => {
			console.log('Logging Out user.');
			dispatch(logoutUser());
			reactHistory.push('/Login');
		}, (e) => {
			alert('Error: ' + e.message)
		})
	}
}

//loading

export var startLoading = () => {
	return {
		type: 'START_LOAD'
	}
}

export var stopLoading = () => {
	return {
		type: 'STOP_LOAD'
	}
}
