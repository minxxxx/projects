import React from 'react';
import {connect} from 'react-redux';

import Background from 'Background';
import Body from "Body";
import CenterContainer from "CenterContainer";
import H1 from "H1";
import Paragraph from "Paragraph";
import ApiContainer from "ApiContainer";
import SwitchButtonContainer from 'SwitchButtonContainer';
import * as actions from 'actions';
import reactHistory from 'reactHistory'

class CustomerLogin extends React.Component {
	constructor() {
		super();

		this.handleSubmit = this.handleSubmit.bind(this);
	}

	handleRegister() {
		reactHistory.push('/register');
	}

	handleSubmit(e) {
		e.preventDefault();

	    var {dispatch} = this.props;
	    var username = this.refs.username.value;
	    var password = this.refs.password.value;

	    if (username.length > 0 && password.length > 0) {
	      this.refs.username.value = '';
	      this.refs.password.value = '';
		  dispatch(actions.startLoading());
	      dispatch(actions.startLoginUser(username, password));
	    } else if (username.length == 0) {
	      this.refs.username.focus();
	    } else {
	      this.refs.password.focus();
	    }
	}

	render() {
        return (
            <Body>
            <CenterContainer data={{styles: {minHeight: "100%"}}}>
				<CenterContainer data={{styles: {flex: "0 0 auto", padding: "calc(2 * var(--unit))", maxWidth: "calc(73 * var(--unit))", backgroundColor: "#FFF", borderRadius: "calc(2 * var(--unit))"}}}>
					<H1 data={{text: "Login"}}/>
                <Paragraph data={{text: "Please login or register to create an account."}}/>
                <form onSubmit={this.handleSubmit} className="form">
                  <div>
                    <div className="form-label">Email:</div>
                    <input className="form-input" type="text" name="Email" ref="username"/>
                  </div>
                  <div>
                    <div className="form-label">Password:</div>
                    <input type="password" className="form-input" name="Password" ref="password"/>
                  </div>
				  <SwitchButtonContainer>
					  <button type="submit" className="switch-button">
						  Login
					  </button>
					  <button type="button" onClick={this.handleRegister} className="switch-button">
						  Register
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

//<FormBuilder data={{"types": ["TextInput", "PasswordInput"], "names": ["Email", "Password"], "submitName": "Login", "links": [""], "linkNames": ["Register"]}}/>

export default connect()(CustomerLogin);
