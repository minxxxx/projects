import React, { Component } from 'react';
import * as types from '../../actions/types';
import { AsyncStorage } from 'react-native';
import {
   Container, Header, Left, Body, Right, Title,
   Content, View, Form, Item, Label, Input,
   Button, Text, Icon, InputGroup, ActionSheet
} from 'native-base';

export default class PatientDetails extends Component<{}> {
    constructor(props) {
        super(props);
    }    
    
    render() {
        return (
            <Container>
                <Header>
                    <Left>
                        <Button transparent
                            onPress={() => {                                 
                                if (this.props.navigationState.previousRoute === 'PatientHistory')
                                    this.props.navigate(types.NAVIGATION_PATIENT_HISTORY);
                                else 
                                    this.props.navigate(types.NAVIGATION_SCAN_ID);
                            }}>
                            <Icon name='arrow-back' />
                        </Button>
                    </Left>
                    <Body>
                        <Title>Patient Details</Title>
                    </Body>
                    <Right>
                        <Button transparent onPress={() => {
                            this.props.getHospitals();
                            this.props.navigate(types.NAVIGATION_HOSPITAL_LIST);
                        }}>
                            <Text>Hosp.</Text>
                        </Button>
                    </Right>
                </Header>
                <Content>
                <Form>
                    <Item stackedLabel>
                        <Label>Initial:</Label>
                        <Input value={ this.props.patients.patientHistory[this.props.patients.selectedPatient].initial }/>
                    </Item>
                    <Item stackedLabel>
                        <Label>First Name:</Label>
                        <Input value={ this.props.patients.patientHistory[this.props.patients.selectedPatient].firstName }/>
                    </Item>
                    <Item stackedLabel last>
                        <Label>Last Name:</Label>
                        <Input value={ this.props.patients.patientHistory[this.props.patients.selectedPatient].lastName }/>
                    </Item>
                    <Item stackedLabel last>
                        <Label>ID Number:</Label>
                        <Input value={ this.props.patients.patientHistory[this.props.patients.selectedPatient].idNumber }/>
                    </Item>
                    <Item stackedLabel last>
                        <Label>Date of Birth:</Label>
                        <Input value={ this.props.patients.patientHistory[this.props.patients.selectedPatient].dateOfBirth }/>
                    </Item>
                    <Item stackedLabel last>
                        <Label>Gender:</Label>
                        <Input value={ this.props.patients.patientHistory[this.props.patients.selectedPatient].gender }/>
                    </Item>
                    <Item stackedLabel last>
                        <Label>Race:</Label>
                        <Input value={ this.props.patients.patientHistory[this.props.patients.selectedPatient].race }/>
                    </Item>
                    <Item stackedLabel last>
                        <Label>Blood Type:</Label>
                        <Input value={ this.props.patients.patientHistory[this.props.patients.selectedPatient].bloodType }
                            onChangeText={(value) => {
                                this.props.patients.patientHistory[this.props.patients.selectedPatient].bloodType = value;
                            }}/>
                    </Item>
                    <Item stackedLabel last>
                        <Label>Next of Kin:</Label>
                        <Input value={ 
                            this.props.patients.patientHistory[this.props.patients.selectedPatient].nextOfKinFirstName 
                            + ' ' +
                            this.props.patients.patientHistory[this.props.patients.selectedPatient].nextOfKinLastName 
                        }/>
                    </Item>
                    <Item stackedLabel last>
                        <Label>Contact Number:</Label>
                        <Input value={ this.props.patients.patientHistory[this.props.patients.selectedPatient].nextOfKinCellNumber }/>
                    </Item>
                    <Item stackedLabel last>
                        <Label>Medical Aid:</Label>
                        <Input value={ this.props.patients.patientHistory[this.props.patients.selectedPatient].medicalAid }/>
                    </Item>
                    <Item stackedLabel last>
                        <Label>Medical Aid Number:</Label>
                        <Input value={ this.props.patients.patientHistory[this.props.patients.selectedPatient].medicalAidNumber }/>
                    </Item>
                    <Item stackedLabel last>
                        <Label>Allergies:</Label>
                        <Input style={{ marginTop: 5 }}  multiline={true}
                            value={ this.props.patients.patientHistory[this.props.patients.selectedPatient].allergies}
                            onChangeText={(value) => {
                                this.props.patients.patientHistory[this.props.patients.selectedPatient].allergies = value;
                            }}
                        />
                    </Item>
                    <Item stackedLabel last>
                        <Label>Medical History:</Label>
                        <Input style={{ marginTop: 5 }}  multiline={true}
                            value={ this.props.patients.patientHistory[this.props.patients.selectedPatient].history }
                            onChangeText={(value) => {
                                this.props.patients.patientHistory[this.props.patients.selectedPatient].history = value;
                            }}
                        />
                    </Item>
                    <Item stackedLabel last>
                        <Label>Chronic Medication:</Label>
                        <Input style={{ marginTop: 5 }}  multiline={true}
                            value={ this.props.patients.patientHistory[this.props.patients.selectedPatient].chronicMedication }
                            onChangeText={(value) => {
                                this.props.patients.patientHistory[this.props.patients.selectedPatient].chronicMedication = value;
                            }}
                        />
                    </Item>
                </Form>
                </Content>
            </Container>
        );
    }
}