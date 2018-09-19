import React, { Component } from 'react';
import { StyleSheet, View, Alert, AsyncStorage } from 'react-native';
import { 
	Container, Header, Content, Left, Body, 
    Right, Title, Button, Text,	Icon, Form,
    Item, Label, Input
} from 'native-base';
import { Actions } from 'react-native-router-flux';
import DeviceInfo from 'react-native-device-info';
import CONSTANTS from '../constants';
import API from '../lib/api.js';

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

export default class EmailQR extends Component {
	constructor() {
		super();
		this.state = {
            email: '',
            qrCode: null,
            sentEmails: 0
		}
        //this.test();
        this.getQRQode();
    }

    async test() {
        await AsyncStorage.setItem('@Settings:EmailsSent', '0');
    }
    
    async getQRQode() {
		try {
            const value = await AsyncStorage.getItem('@Images:QR');
            const sentStr = await AsyncStorage.getItem('@Settings:EmailsSent');

            var sent = parseInt(sentStr);
            if (sent === NaN)
                sent = 0;

			this.setState({
                qrCode: value,
                sentEmails: sent
            });
		} catch (error) {
			// Error retrieving data
			console.log(error);
		}
    }

    async setSentEmails(){
        try {
            await AsyncStorage.setItem('@Settings:EmailsSent', this.state.sentEmails.toString());
        } catch (error) {
            console.log('Failed to save Sent emails.');
        }  
    }
    
    sendEmail() {
        if (this.state.sentEmails >= 5) {
            Alert.alert('Max e-mail sends for this QR-Code has been reached.');
            return ;
        }


        var body = {
            email: this.state.email,
            qrCode64Base: this.state.qrCode,
            token: 'nGwembcqXjFT4uKTN0v0AAafpclPXIQMFexN4Yq9PTcTA4'
        };

        API.post('/emailqr', body, null).then((resp) => {
            var json = JSON.parse(resp._bodyText);
            if (json.status == true) {
                Alert.alert('E-mail sent.');


                this.state.sentEmails = this.state.sentEmails + 1;
                this.setSentEmails();
            } else {
                Alert.alert('Failed to send e-mail.');
                console.log(resp.json);
            }
        });
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
						<Title>E-mail QR</Title>
					</Body>
					<Right/>
				</Header>
				<Content>
                    <Form>
                        <Item stackedLabel>
                            <Label>E-mail:</Label>
                            <Input onChangeText={(value) => {
                                this.setState({ email: value });
                            }}/>
                        </Item>
                        <Text note>* Can only send 5 per QR Code.</Text>
                    </Form>
                    <Button primary full
                        style={styles.btn}
                        onPress={() => { 
                            this.sendEmail(); 
                        }}>
                        <Text>Send</Text>
                    </Button> 
				</Content>
			</Container>
		);
	}
}