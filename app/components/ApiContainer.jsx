import React from 'react';
import {connect} from 'react-redux';

import * as actions from 'actions';

class ApiContainer extends React.Component {
	constructor() {
		super();

		this.handleLogin = this.handleLogin.bind(this);
	}

	handleLogin(method) {
		var {dispatch} = this.props;

		switch (method) {
			case 'google':
				dispatch(actions.googleLogin());
				break;
			case 'facebook':
				dispatch(actions.facebookLogin());
				break;
			case 'twitter':
				dispatch(actions.twitterLogin());
				break;
			default:
				console.error('Invalid login API');
		}
	}

    render() {
        return (
            <div className="api-container">
                <div className="api-box">
                    <img src="icons/google_logo.png" alt="" className="api-image" onClick={() => this.handleLogin('google')}/>
                </div>
                <div className="api-box">
                    <img src="icons/facebook_logo.png" alt="" className="api-image" onClick={() => this.handleLogin('facebook')}/>
                </div>
                <div className="api-box">
                    <img src="icons/tweeter_logo.png" alt="" className="api-image" onClick={() => this.handleLogin('twitter')}/>
                </div>
            </div>
        );
    }
}

export default connect()(ApiContainer);
