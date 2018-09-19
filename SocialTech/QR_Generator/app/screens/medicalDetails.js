import React, { Component } from 'react';
import { 
	StyleSheet, View, Alert, AsyncStorage
} from 'react-native';
import { 
	Container, Header, Content, Footer,
	Left, Body, Title, Button, Label,
	Text, Icon,	Form, Item, Input,
	Picker, InputGroup, FooterTab,
	Right
} from 'native-base';
import { Actions } from 'react-native-router-flux';
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

export default class MedicalDetails extends Component {
	constructor(props) {
		super(props);
		this.state = {
			patient: props.patient,

			validMedicalAid: true,
			validMedicalAidNumber: true,
			validAllergies: true,
			validHistory: true,
			validChronicMedication: true,
        }
	}

	validate() {
		if (!this.state.validMedicalAid) {
			Alert.alert('Medical Aid: Invalid "|" content.');
			return (false);
		}
		if (!this.state.validMedicalAidNumber) {
			Alert.alert('Medical Aid Number: Invalid "|" content.');
			return (false);
		}
		if (!this.state.validAllergies) {
			Alert.alert('Allergies: Invalid "|" content.');
			return (false);
		}
		if (!this.state.validHistory) {
			Alert.alert('History: Invalid "|" content.');
			return (false);
		} 
		if (!this.state.validChronicMedication) {
			Alert.alert('Chronic Medication: Invalid "|" content.');
			return (false);
		}

		return (true);
	}

	async setSentEmails() {
        try {
			console.log('RESET TO ZERO');
            await AsyncStorage.setItem('@Settings:EmailsSent', '0');
        } catch (error) {
            console.log('Failed to save QR Image.');
        }  
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
						<Title>Medical Info</Title>
					</Body>
					<Right />
				</Header>
				<Content>
					<Form>
						<Item floatingLabel error={ !this.state.validMedicalAid }>
							<Label>Medical Aid</Label>
							<Input maxLength={124} 
								onChangeText={(value) => { 
									if (value.indexOf(CONSTS.SPLITTER) > -1)
										this.setState({ validMedicalAid: false });
									else
										this.setState({ validMedicalAid: true });
									this.state.patient.medicalAid = value; 
								}}/>
						</Item>
						<Item floatingLabel error={ !this.state.validMedicalAidNumber }>
							<Label>Medical Aid Number</Label>
							<Input maxLength={20}
								onChangeText={(value) => {
									if (value.indexOf(CONSTS.SPLITTER) > -1)
										this.setState({ validMedicalAidNumber: false });
									else
										this.setState({ validMedicalAidNumber: true });
									this.state.patient.medicalAidNumber = value;
								}}/>
						</Item>
						<InputGroup borderType='regular' error={ !this.state.validAllergies }>
                            <Input style={{
                                marginTop: 5,
                                width: 200, height: 200
                            }}  multiline={true} placeholder='Type your allergies here'
                            maxLength={850}
                            onChangeText={(value) => {
									if (value.indexOf(CONSTS.SPLITTER) > -1)
										this.setState({ validAllergies: false });
									else
										this.setState({ validAllergies: true });
                                this.state.patient.allergies = value;
                            }}/>
                        </InputGroup>                        
						<InputGroup borderType='regular' error={ !this.state.validHistory }>
                            <Input style={{
                                marginTop: 5,
                                width: 200, height: 200
                            }}  multiline={true} placeholder='Type your medical history here'
                            maxLength={850}
                            onChangeText={(value) => {
									if (value.indexOf(CONSTS.SPLITTER) > -1)
										this.setState({ validHistory: false });
									else
										this.setState({ validHistory: true });
									this.state.patient.history = value;
                            }}/>
                        </InputGroup>                        
						<InputGroup borderType='regular' error={ !this.state.validChronicMedication }>
                            <Input style={{
                                marginTop: 5,
                                width: 200, height: 200
                            }}  multiline={true} placeholder='Type any chronic medication here'
                            maxLength={800}
                            onChangeText={(value) => {
									if (value.indexOf(CONSTS.SPLITTER) > -1)
										this.setState({ validChronicMedication: false });
									else
										this.setState({ validChronicMedication: true });
                                this.state.patient.chronicMedication = value;
                            }}/>
                        </InputGroup>                     
					</Form>
			  	</Content>
				<Footer>
					<FooterTab>
						<Button onPress={() => { Actions.pop(); }}>
							<Text>Back</Text>
						</Button>
						<Button onPress={() => {
								if (this.validate()) {
									Actions.CreateQR(this.state); 
									this.setSentEmails();
								}
							}}>
							<Text>Finish</Text>
						</Button>
					</FooterTab>
				</Footer>
			</Container>
		);
	}
}