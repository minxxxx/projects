import React, { Component } from 'react';
import { StyleSheet, View } from 'react-native';
import { 
	Container, 
	Header, 
	Content,
	Left, 
	Body, 
	Right,
	Title,
	Button,
	Text,
	Icon,
	Footer,
	FooterTab
} from 'native-base';
import { Actions } from 'react-native-router-flux';
import DeviceInfo from 'react-native-device-info';
import CONSTANTS from '../constants';

const styles = StyleSheet.create({
	btn_container: {
		flex: 1,
		alignContent: 'space-between',
		alignItems: 'center',
		margin: 5
	},
	btn: {
		margin: 5
	}
});

export default class Disclaimer extends Component {
	constructor() {
		super();

		//this.renderDisclaimer();
	}

	renderDisclaimer() {
		var disclaimer = CONSTANTS.DISCLAIMERS.EN;
		/*var locale = DeviceInfo.getDeviceLocale;
		if (locale == 'fr')
			disclaimer = CONSTANTS.DISCLAIMERS.FR;*/
		return (
			<Text style={{color: 'gray'}}>
				{disclaimer}
			</Text>
		);
	}

	render() {
		return (
			<Container>
				<Header>
					<Left>
						<Button transparent onPress={() => { Actions.pop(); }}>
							<Icon name='arrow-back' />
						</Button>
					</Left>
					<Body>
						<Title>Disclaimer</Title>
					</Body>
					<Right/>
				</Header>
				<Content>
					<View style={styles.btn_container}>
						{ this.renderDisclaimer() }						
					</View>
				</Content>
				<Footer>
					<FooterTab>
						<Button onPress={() => { Actions.PersonalDetails() }}>
							<Text>I accept the disclaimer</Text>
						</Button>
					</FooterTab>
				</Footer>
			</Container>
		);
	}
}