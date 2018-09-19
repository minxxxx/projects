import React, { Component } from 'react';
import * as types from '../../actions/types';
import {
   Container, Header, Left, Body, Right, Title,
   Content, View, Form, Item, Label, Input,
   Button, Text, Icon
} from 'native-base';
import { Alert } from 'react-native';
import { styles } from './style';

export default class Signup extends Component<{}> {
    constructor(props) {
        super(props);
        console.log(this.props.loggedIn);
        this.state = {
            hpcsaNumber: this.props.loggedIn.user.HPCSANumber,
            email: this.props.loggedIn.user.Email,
            username: this.props.loggedIn.user.Username,
            passwordChanged: false,
            password: '',
            confirmPassword: '',
            validPwd: false
        }
    }

    renderConfirmPassword() {
        if (this.state.passwordChanged) {
            return (
                <Item floatingLabel error={!this.state.validPwd} success={this.state.validPwd}>
                <Label>Confirm Password:</Label>
                <Input secureTextEntry={true}
                    onChangeText={(value) => {
                        var same = this.state.validPwd;
                        if (this.state.password !== value)
                            same = false
                        else
                            same = true;
                        this.setState({confirmPassword: value, validPwd: same });
                    }}/>
                </Item>  
            );
        }
    }

    render() {
        return (
            <Container>
                <Header>
                    <Left>
                        <Button transparent
                            onPress={() => { 
                                this.props.navigate(types.NAVIGATION_SCAN_ID);
                             }}>
                            <Icon name='arrow-back' />
                        </Button>
                    </Left>
                    <Body>
                        <Title>Profile</Title>
                    </Body>
                    <Right/>
                </Header>
                <Content>
                    <Form>
                        <Item stackedLabel>
                            <Label>HPCSA Number:</Label>
                            <Input onChangeText={(value) => {
                                this.setState({ hpcsaNumber: value });
                            }} value={ this.state.hpcsaNumber }/>
                        </Item>
                        <Item stackedLabel>
                            <Label>E-mail:</Label>
                            <Input onChangeText={(value) => {
                                this.setState({ email: value });
                            }} value={ this.state.email }/>
                        </Item>
                        <Item stackedLabel>
                            <Label>Username:</Label>
                            <Input onChangeText={(value) => {
                                this.setState({ username: value });
                            }} value={ this.state.username }/>
                        </Item>
                        <Item stackedLabel>
                            <Label>Password:</Label>
                            <Input secureTextEntry={true}
                                onChangeText={(value) => {
                                    if (!this.state.passwordChanged)
                                        this.setState({ passwordChanged : true });
                                    var same = this.state.validPwd;
                                    if (this.state.confirmPassword !== value)
                                        same = false
                                    else
                                        same = true;
                                    this.setState({ password: value });
                                }}/>
                        </Item>
                        { this.renderConfirmPassword() }
                    </Form>
                    <View style={styles.btn_main_container}>
                        <View style={styles.btn_container}>                            
                        </View>
                        <View style={styles.btn_container}>
                            <Button primary full
                                style={styles.btn}
                                onPress={() => {
                                    if (this.state.passwordChanged && !this.state.validPwd) {
                                        Alert.alert('Passwords do not match.');
                                    } else {
                                        this.props.updateUser(this.state, this.props.loggedIn.user);
                                    }
                                  }}>
                                <Text>Update</Text>
                            </Button> 
                        </View>
                    </View>
                </Content>
            </Container>
        );
    }
}