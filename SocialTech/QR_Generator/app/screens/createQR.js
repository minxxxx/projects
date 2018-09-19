import React, { Component } from 'react';
import { 
	StyleSheet, View, Alert
} from 'react-native';
import { 
	Container, Header, Content, Footer,
	Left, Body, Title, Button, Label,
	Text, Icon,	Form, Item, Input,
	Picker, InputGroup
} from 'native-base';
import { Actions } from 'react-native-router-flux';
import QRCode from '../components/QRCode/qrCode';


const styles = StyleSheet.create({
	btn_container: {
		flex: 1,
		alignContent: 'space-between',
		alignItems: 'center',
		margin: 5
	},
	btn: {
		margin: 5
	},
	form: {
		width: 100
	},
	picker: {
		margin: 10
	}
});

export default class CreateQR extends Component {
	constructor(props) {
		super(props);
		this.state = {
			patient: props.patient
        }
        console.log(this.state.patient);
    }

    getInitial(initial) {
        switch (initial) {
            case ("Mr."): return ("0");
            case ("Mrs."): return ("1");
            case ("Ms."): return ("2");
            default: return ("0");
        }
    }

    getGender(gender) {
        switch (gender) {
            case ("Male"): return ("M");
            case ("Female"): return ("F");
            default: return ("M");
        }
    }

    getRace(race) {
        switch (race) {
            case ("White"): return ("0");
            case ("Black"): return ("1");
            case ("Indian"): return ("2");
            case ("Coloured"): return ("3");
            default: return ("4");
            case ("Other"): return ("4");
        }
    }

    getBloodType(bloodType) {
        switch (bloodType) {
            case ("Not Sure"): return ("0");
            case ("A+"): return ("1");
            case ("A-"): return ("2");
            case ("B+"): return ("3");
            case ("B-"): return ("4");
            case ("AB+"): return ("5");
            case ("AB-"): return ("6");
            case ("O+"): return ("7");
            case ("O-"): return ("8");
            default: return (0);
        }
    }

    getDate(date) {
        var strDate = date.getFullYear() + "-";
        var month = date.getMonth() + 1;
        if (month < 10)
            strDate += "0";
        strDate += month;
        if (date.getDate() < 10) {
            strDate += "-0" + date.getDate();
        } else {
            strDate += "-" + date.getDate();
        }
        return (strDate);
    }
    
    /**
     * Erick|Doe|0|00000000000000|1996-08-26|M|0|1|John|Doe|0000000000|BestMed|ATC0001|None|None|None
     */

    buildToken() {
        var split = "|";
        var token = "";

        token += this.state.patient.firstName;
        token += split + this.state.patient.lastName;
        token += split + this.getInitial(this.state.patient.initial);
        token += split + this.state.patient.idNumber;
        token += split + this.getDate(new Date(this.state.patient.dateOfBirth));
        token += split + this.getGender(this.state.patient.gender);
        token += split + this.getRace(this.state.patient.race);
        token += split + this.getBloodType(this.state.patient.bloodType);

        token += split + this.state.patient.nextOfKinFirstName;
        token += split + this.state.patient.nextOfKinLastName;
        token += split + this.state.patient.nextOfKinCellNumber;

        token += split + this.state.patient.medicalAid;
        token += split + this.state.patient.medicalAidNumber;

        token += split + this.state.patient.allergies;
        token += split + this.state.patient.history;
        token += split + this.state.patient.chronicMedication;

        console.log("TOKEN: " + token);
        return (token);
    }

	render() {
		return (
			<Container>
				<Header>
					<Left>
						<Button transparent onPress={() => { Actions.Home(); }}>
							<Icon name='home' />
						</Button>
					</Left>
					<Body>
						<Title>QR Code</Title>
					</Body>
				</Header>
				<Content>
                    <View style={{alignItems: 'center'}}>
                        <QRCode value={this.buildToken()} width={300} height={300}/>
                    </View>
			  	</Content>
			</Container>
		);
	}
}