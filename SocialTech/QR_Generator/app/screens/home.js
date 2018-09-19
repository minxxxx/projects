import React, { Component } from 'react';
import { 
	StyleSheet, 
	View, 
	Image,
	AsyncStorage 
} from 'react-native';
import { 
	Container, 
	Header, 
	Content,
	Body, 
	Right, 
	Title,
	Button,
	Text,
	Icon
} from 'native-base';
import { Actions } from 'react-native-router-flux';

const styles = StyleSheet.create({
	btn_container: {
		flex: 1,
		alignContent: 'space-between',
		margin: 5
	},
	btn: {
		margin: 5
	}
});

export default class Home extends Component {
	constructor() {
		super();
		this.state = {
			qrCode: null
		}
		this.getQRQode();
	}

	async getQRQode() {
		try {
			const value = await AsyncStorage.getItem('@Images:QR');
			this.setState({
				qrCode: value
			});
		} catch (error) {
			// Error retrieving data
			console.log(error);
		}
	}

	renderQRImage() {
		if (this.state.qrCode) {
			return (
				<Image source={{uri: this.state.qrCode}} style={{ width: 360, height: 360 }} />
			);
		}
	}

	renderEmailButton() {
		if (this.state.qrCode) {
			return (
				<Button full style={styles.btn}
					onPress={() => { Actions.EmailQR(); }}>
					<Text>E-mail QR Code</Text>
				</Button>
			);
		}
	}

	render() {
		return (
			<Container>
				<Header>
					<Body>
						<Title>QR-Generator</Title>
					</Body>
					<Right>
					</Right>
				</Header>
				<Content>
					<View style={{flex: 1, alignItems: 'center'}}>
						{ this.renderQRImage() }
					</View>
					<View style={styles.btn_container}>
						<Button full style={styles.btn}
							onPress={() => { Actions.Disclaimer(); }}>
							<Text>Create QR Code</Text>
						</Button>
						{ this.renderEmailButton() }
					</View>
				</Content>
			</Container>
		);
	}
}