import React from 'react';
import {NavLink} from 'react-router-dom';
import {connect} from 'react-redux';
import * as actions from 'actions';
import reactHistory from 'reactHistory';

class Header extends React.Component {
	constructor() {
		super();

		this.handleLogout = this.handleLogout.bind(this);
	}

	handleLogout() {
		var {dispatch, user} = this.props;

		console.log(user);

		if (user.length != 0) {
			dispatch(actions.startLogoutUser());
		} else {
			reactHistory.push('/Login');
		}
	}

    render() {
		var {user} = this.props;

		if (user.length == 0) {
			user = 'Login';
		} else {
			user = 'Logout ' + user;
		}
        return (
            <div className="header divider-border">
                <NavLink exact to='/' activeStyle={{fontWeight: 'bold'}} className="nav-btn">BIB</NavLink>
                <NavLink to="/Search" activeStyle={{fontWeight: 'bold'}} className="nav-btn">Search</NavLink>
                <NavLink to="/Dashboard" activeStyle={{fontWeight: 'bold'}} className="nav-btn">Dashboard</NavLink>
                <NavLink to="/DesignerDashboard" activeStyle={{fontWeight: 'bold'}} className="nav-btn">Designer</NavLink>
                <NavLink to="/MakerDashboard" activeStyle={{fontWeight: 'bold'}} className="nav-btn">Maker</NavLink>
                <div className="expander"/>
                <div className="nav-btn" onClick={this.handleLogout}>{user}</div>
            </div>
        );
    }
}

//<NavLink to='/Login' activeStyle={{fontWeight: 'bold'}} className="nav-btn" isActive={this.handleLogout}>{user}</NavLink>

export default connect(
	(state) => {
		return {
			user: state.user
		}
	})(Header);
