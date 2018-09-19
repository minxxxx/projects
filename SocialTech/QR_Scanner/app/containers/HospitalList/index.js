import React, { Component } from 'react';
import * as types from '../../actions/types';
import {
   Container, Header, Left, Body, Right, Title,
   Content, View, Form, Item, Label, Input,
   Button, Text, CheckBox, ListItem, Icon,
   List, ActionSheet
} from 'native-base';
import {
    AsyncStorage
} from 'react-native';
import openMap from '../../lib/openMaps';

var BUTTONS = [ 'Send Information', 'Route To', 'Cancel' ];

export default class HospitalList extends Component<{}> {
    constructor(props) {
        super(props);
        this.state = {
            nativeNavigation: true
        };
        this.getSettings();
    }

    async getSettings() {
        try {
            var strNativeNavigation = await AsyncStorage.getItem('@Settings:nativeNavigation');
            if (strNativeNavigation) {
                this.setState({
                    nativeNavigation: (strNativeNavigation == 'true') ? true : false
                });
            }
        } catch (e) {
            console.error('An error occured getting the user settings', e);
        }
    }

    render() {
        return (
            <Container>
            <Header>
                <Left>
                    <Button transparent
                        onPress={() => {
                            this.props.navigate(types.NAVIGATION_PATIENT_DETAILS);
                        }}>
                        <Icon name='arrow-back' />
                    </Button>
                </Left>
                <Body>
                    <Title>Hospitals</Title>
                </Body>
                <Right>
                </Right>
            </Header>
            <Content>
                <List dataArray={this.props.hospitals.list}
                    renderRow={(hosp) =>
                    <ListItem button={true} onPress={() => {
                        ActionSheet.show({
                            options: BUTTONS,
                            cancelButtonIndex: 2,
                            title: hosp.FullName
                        },
                        (buttonIndex) => {
                            if (buttonIndex == 0) {
                                this.props.sendInboundPatient(
                                    this.props.patients.patientHistory[this.props.patients.selectedPatient],
                                    hosp
                                );
                            } else if (buttonIndex == 1) {
                                this.props.sendInboundPatient(
                                    this.props.patients.patientHistory[this.props.patients.selectedPatient],
                                    hosp
                                );
                                openMap({
                                    latitude: this.props.hospitals.list[0].Latitude,
                                    longitude: this.props.hospitals.list[0].Longitude,
                                    zoomLevel: 20
                                });
                            }
                        });
                    }}>
                        <Body>
                            <Text>{ hosp.FullName}</Text>
                            <Text note>{hosp.StreetAddress}, {hosp.City}</Text>
                        </Body>
                        <Right>
                        </Right>
                    </ListItem>
                }>
          </List>
            </Content>
        </Container>
        );
    }
}