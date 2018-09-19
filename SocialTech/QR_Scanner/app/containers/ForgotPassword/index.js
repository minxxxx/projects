import React, { Component } from 'react';
import * as types from '../../actions/types';
import {
   Container, Header, Left, Body, Right, Title,
   Content, View, Form, Item, Label, Input,
   Button, Text, Icon
} from 'native-base';
import {
    Alert
} from 'react-native';
import { styles } from './style';

export default class ForgotPassword extends Component<{}> {
    constructor(props) {
        super(props);
        this.state = {
            hpcsaNumber: '',
            email: ''
        }
    }

    sendForgotPassword() {
        var body = {
            hcpsaNumber: this.state.hpcsaNumber,
            email: this.state.email
        }
        this.props.forgotPassword(body);
    }

    render() {
        return (
            <Container>
                <Header>
                    <Left>
                        <Button transparent
                            onPress={() => { this.props.navigate(types.NAVIGATION_LOGIN) }}>
                            <Icon name='arrow-back' />
                        </Button>
                    </Left>
                    <Body>
                        <Title>Reset Pwd</Title>
                    </Body>
                    <Right/>
                </Header>
                <Content>
                    <Form>
                        <Item stackedLabel>
                            <Label>HPCSA Number:</Label>
                            <Input onChangeText={(value) => {
                                this.setState({ hpcsaNumber: value });
                            }}/>
                        </Item>
                        <Item stackedLabel>
                            <Label>E-mail:</Label>
                            <Input autoCapitalize='none'
                            onChangeText={(value) => {
                                this.setState({ email: value });
                            }}/>
                        </Item>
                    </Form>
                    <Button primary full
                        style={styles.btn}
                        onPress={() => { this.sendForgotPassword() }}>
                        <Text>Submit</Text>
                    </Button> 
                </Content>
            </Container>
        );
    }
}