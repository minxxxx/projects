import React, { Component } from 'react';
import { 
	StyleSheet, View, Alert
} from 'react-native';
import { 
	Container, Header, Content, Footer,
	Left, Body, Title, Button, Label,
	Text, Icon,	Form, Item, Input,
	Picker, FooterTab, Right
} from 'native-base';
import { Actions } from 'react-native-router-flux';
import DatePicker from 'react-native-datepicker'
import PatientInformation from '../models/PatientInformation';
import DropDown from '../components/DropDown/dropdown'
import CONSTS from '../constants';

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

export default class NextOfKin extends Component {
	constructor(props) {
		super(props);
		this.state = {
			patient: props.patient,

			validNokFirstName: true,
			validNokLastName: true,
			validNokCellphone: true
        }
	}

	validate() {
		if (!this.state.validNokFirstName) {
			Alert.alert('First Name: Invalid "|" content.');
			return (false);
		}

		if (!this.state.validNokLastName) {
			Alert.alert('Last Name: Invalid "|" content.');
			return (false);
		}

		if (this.state.patient.nextOfKinCellNumber != null && this.state.patient.nextOfKinCellNumber.length > 0) {
			if (isNaN(this.state.patient.nextOfKinCellNumber)) {
				Alert.alert('Cell Number: Numbers Only.')
				return (false);
			}
			if (!this.state.validNokCellphone) {
				Alert.alert('Cell Number: Invalid "|" content.');
				return (false);
			}
		}
		return (true);
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
						<Title>Next of Kin
                        </Title>
					</Body>
					<Right />
				</Header>
				<Content>
					<Form>
						<Item stackedLabel error={!this.state.validNokFirstName}>
							<Label>First Name</Label>
							<Input maxLength={125} 
								onChangeText={(value) => { 
									if (value.indexOf(CONSTS.SPLITTER) > -1)
										this.setState({ validNokFirstName: false });
									else
										this.setState({ validNokFirstName: true });
									this.state.patient.nextOfKinFirstName = value; 
								}}/>
						</Item>
						<Item stackedLabel error={!this.state.validNokLastName}>
							<Label>Last Name</Label>
							<Input maxLength={125}
								onChangeText={(value) => {
									if (value.indexOf(CONSTS.SPLITTER) > -1)
										this.setState({ validNokLastName: false });
									else
										this.setState({ validNokLastName: true });
									this.state.patient.nextOfKinLastName = value;
								}}/>
						</Item>
						<Item stackedLabel error={!this.state.validNokCellphone}>
							<Label>Cell Number</Label>
							<Input maxLength={12} keyboardType='numeric'
								onChangeText={(value) => {
									if (value.indexOf(CONSTS.SPLITTER) > -1)
										this.setState({ validNokCellphone: false });
									else
										this.setState({ validNokCellphone: true });
									this.state.patient.nextOfKinCellNumber = value;
								}}/>
						</Item>	                        
					</Form>
			  	</Content>
				<Footer>
					<FooterTab>
						<Button onPress={() => { Actions.pop(); }}>
							<Text>Back</Text>
						</Button>
						<Button onPress={() => { 
								if (this.validate())
									Actions.MedicalDetails(this.state); 
							}}>
							<Text>Next</Text>
						</Button>
					</FooterTab>
				</Footer>
			</Container>
		);
	}
}