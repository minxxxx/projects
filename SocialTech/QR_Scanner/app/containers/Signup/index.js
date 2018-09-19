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

export default class Signup extends Component<{}> {
    constructor(props) {
        super(props);
        this.state = {
            hpcsaNumber: '',
            email: '',
            username: '',
            password: '',

            confirmPwd: '',
            validPwd: false
        }
    }

    sendSignup() {
        if (!this.state.validPwd) {
            Alert.alert('Password do not match.');
            return;
        }

        var params = {
            hpcsaNumber: this.state.hpcsaNumber,
            username: this.state.username,
            email: this.state.email,
            password: this.state.password
        }
        this.props.signup(params);
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
                        <Title>Sign Up</Title>
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
                            <Input onChangeText={(value) => {
                                this.setState({ email: value });
                            }}/>
                        </Item>
                        <Item stackedLabel>
                            <Label>Username:</Label>
                            <Input onChangeText={(value) => {
                                this.setState({ username: value });
                            }}/>
                        </Item>
                        <Item stackedLabel>
                            <Label>Password:</Label>
                            <Input secureTextEntry={true}
                                onChangeText={(value) => {
                                     var same = this.state.validPwd;
                                     if (this.state.confirmPwd !== value)
                                         same = false
                                     else
                                         same = true;
                                     this.setState({password: value, validPwd: same });
                                }}/>
                        </Item>
                        <Item stackedLabel error={!this.state.validPwd} success={this.state.validPwd}>
                            <Label>Confirm Password:</Label>
                            <Input secureTextEntry={true}
                                onChangeText={(value) => {
                                    var same = this.state.validPwd;
                                    if (this.state.password !== value)
                                        same = false
                                    else
                                        same = true;
                                    this.setState({confirmPwd: value, validPwd: same });
                                }}/>
                        </Item>
                    </Form>
                    <View style={styles.btn_main_container}>
                        <View style={styles.btn_container}>                            
                        </View>
                        <View style={styles.btn_container}>
                            <Button primary full
                                style={styles.btn}
                                onPress={() => { this.sendSignup() }}>
                                <Text>Sign Up</Text>
                            </Button> 
                        </View>
                    </View>
                </Content>
            </Container>
        );
    }
}