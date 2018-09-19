import React, { Component } from 'react';
import * as types from '../../actions/types';
import {
   Container, Header, Left, Body, Right, Title,
   Content, View, Button, Text, Icon, List, ListItem
} from 'native-base';
import { styles } from './styles';

export default class PatientHistory extends Component<{}> {
    constructor(props) {
        super(props);
    }
    
    renderList() {
        if (this.props.patients.patientHistoryCount == 0) {
            return (
                <View style={styles.no_items}>
                    <Text style={ styles.no_items_text }>
                        No Patient History
                    </Text>
                </View>
            );
        } else {
            return (
                <List>
                {
                    this.props.patients.patientHistory.map((patient, i) => {
                        return (
                            <ListItem 
                                key={i}
                                onPress={() => {
                                    this.props.setSelectedPatient(i);
                                    this.props.navigate(types.NAVIGATION_PATIENT_DETAILS);
                                }}>
                                <Body>
                                    <Text>{ patient.firstName + ' ' + patient.lastName }</Text>
                                    <Text note>{ patient.medicalAid }</Text>
                                </Body>
                            </ListItem>
                        );
                    })
                }
                </List>
            );
        }
    }

    render() {
        return (
            <Container>
                <Header>
                    <Left>
                        <Button transparent
                            onPress={() => { this.props.navigate(types.NAVIGATION_SCAN_ID) }}>
                            <Icon name='arrow-back' />
                        </Button>
                    </Left>
                    <Body>
                        <Title>History</Title>
                    </Body>
                    <Right/>
                </Header>
                <Content>
                   { this.renderList() }
                </Content>
            </Container>
        );
    }
}