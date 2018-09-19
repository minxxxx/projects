import React from 'react'

import Background from "Background";
import Body from "Body";
import CenterContainer from "CenterContainer";
import H1 from "H1";
import P1 from "P1";
import ApiContainer from "ApiContainer";
import SwitchButtonContainer from 'SwitchButtonContainer';

import {connect} from 'react-redux';
import * as actions from 'actions';
import reactHistory from 'reactHistory';

class CustomerRegister extends React.Component {
	constructor() {
		super();

		this.handleSubmit = this.handleSubmit.bind(this);
	}

	navLogin() {
		reactHistory.push('/Login')
	}

	handleSubmit(e) {
		e.preventDefault();

	    var {dispatch} = this.props;
	    var username = this.refs.username.value;
	    var password1 = this.refs.password1.value;
		var password2 = this.refs.password2.value;

	    if (username.length > 0 && password1.length > 0 && password2.length > 0) {
	     	this.refs.username.value = '';
	      	this.refs.password1.value = '';
			this.refs.password2.value = '';
	      	dispatch(actions.startRegisterUser(username, password1, password2));
	    } else if (username.length == 0) {
	      	this.refs.username.focus();
	  	} else if (password1.length == 0) {
	      	this.refs.password1.focus();
	  	} else {
		  	this.refs.password2.focus();
	  	}
	}

    render() {
        return (
            <Body>
            <CenterContainer data={{styles: {minHeight: "100%"}}}>
				<CenterContainer data={{styles: {flex: "0 0 auto", padding: "calc(2 * var(--unit))", maxWidth: "calc(73 * var(--unit))", backgroundColor: "#FFF", borderRadius: "calc(2 * var(--unit))"}}}>
					<H1 data={{text: "Register"}}/>
					<P1 data={{text: "Please register to create an account."}}/>
					<form onSubmit={this.handleSubmit} className="form">
					  <div>
						<div className="form-label">Email:</div>
						<input className="form-input" type="text" name="Email" ref="username"/>
					  </div>
					  <div>
						<div className="form-label">Password:</div>
						<input type="password" className="form-input" name="Password" ref="password1"/>
					  </div>
					  <div>
						<div className="form-label">Retype Password:</div>
						<input type="password" className="form-input" name="Password" ref="password2"/>
					  </div>
					  <SwitchButtonContainer>
						  <button type="submit" className="switch-button">
							  Submit
						  </button>
						  <button type="button" className="switch-button" onClick={this.navLogin}>
							  Login
						  </button>
					  </SwitchButtonContainer>
					</form>
					<ApiContainer/>
				</CenterContainer>
            </CenterContainer>
            </Body>
        );
    }
}

export default connect()(CustomerRegister);
