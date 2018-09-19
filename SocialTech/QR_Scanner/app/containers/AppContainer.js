import React, { Component } from 'react';
import {
    View,
    Text,
    TouchableHighlight
} from 'react-native';
import { connect } from 'react-redux';
import { bindActionCreators } from 'redux';
import { ActionCreators } from '../actions';
import { Alert } from 'react-native';

import Login from './Login';
import Signup from './Signup';
import ScanID from './ScanID';
import ScanQR from './ScanQR';
import PatientHistory from './PatientHistory';
import PatientDetails from './PatientDetails';
import HospitalList from './HospitalList';
import Profile from './Profile';
import ForgotPassword from './ForgotPassword';

class AppContianer extends Component<{}> {
    constructor(props) {
        super(props);
    }

    showNotification() {
        if (this.props.notification.available) {
            Alert.alert(this.props.notification.message);
            this.props.notification.available = false;
        }
    }

    render() {
        this.showNotification();
        console.log(this.props);
        let Scene = null;
        if (this.props.navigationState.route == 'Login') {
            Scene = Login;
        } else if (this.props.navigationState.route == 'Signup') {
            Scene = Signup;
        } else if (this.props.navigationState.route == 'ScanID') {
            Scene = ScanID;
        } else if (this.props.navigationState.route == 'ScanQR') {
            Scene = ScanQR;
        } else if (this.props.navigationState.route == 'PatientDetails') {
            Scene = PatientDetails;
        } else if (this.props.navigationState.route == 'PatientHistory') {
            Scene = PatientHistory;
        } else if (this.props.navigationState.route == 'HospitalList') {
            Scene = HospitalList;
        } else if (this.props.navigationState.route == 'Profile') {
            Scene = Profile;
        } else if (this.props.navigationState.route == 'ForgotPassword') {
            Scene = ForgotPassword;
        }
        return (
            <Scene {...this.props}/>
        )
    }
}

function mapDispatchToProps(dispatch) {
    return bindActionCreators(ActionCreators, dispatch);
}
export default connect((state) => { 
    return {
        navigationState: state.navigationState,
        notification: state.notification,
        patients: state.patients,
        loggedIn: state.loggedIn,
        hospitals: state.hospitals
    } 
}, mapDispatchToProps)(AppContianer);