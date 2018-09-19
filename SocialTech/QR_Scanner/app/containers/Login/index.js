import React, { Component } from 'react';
import * as types from '../../actions/types';
import {
   Container, Header, Left, Body, Right, Title,
   Content, View, Form, Item, Label, Input,
   Button, Text, CheckBox, ListItem
} from 'native-base';
import {
    AsyncStorage
} from 'react-native'
import { styles } from './style';

export default class Login extends Component<{}> {
    constructor(props) {
        super(props);
        this.state = {
            username: 'oexall',
            password: '',
            remember: false
        }
        this.getRememberMe();
    }

    async getRememberMe() {
        try {
            var remembered = await AsyncStorage.getItem('@Settings:RememberMe');
            var state = remembered == 'true' ? true : false;
            var username = null;
            if (state) {
                username = await AsyncStorage.getItem('@Settings:Username');
            }
            this.setState({
                remember: state,
                username: username
            });
        } catch (e) {
            console.log('Failed to get setting');
        }
    }

    async setRememberMe() {
        try {
            await AsyncStorage.setItem('@Settings:RememberMe', this.state.remember.toString());
            if (this.state.remember) {
                await AsyncStorage.setItem('@Settings:Username', this.state.username);
            } else {
                await AsyncStorage.removeItem('@Settings:Username');
            }
        } catch (e) {
            console.log('Failed to save setting');
        }
    }

    login() {
        this.props.login({
            username: this.state.username,
            password: this.state.password,
            token: 'nGwembcqXjFT4uKTN0v0AAafpclPXIQMFexN4Yq9PTcTA4'
        });
        this.setRememberMe();
    }

    render() {
        return (
            <Container>
                <Header>
                    <Left/>
                    <Body>
                        <Title>Login</Title>
                    </Body>
                    <Right/>
                </Header>
                <Content>
                    <Form>
                        <Item stackedLabel>
                            <Label>Username:</Label>
                            <Input autoCapitalize='none' value={this.state.username}
                                onChangeText={(value) => { this.setState({username: value}) }}/>
                        </Item>
                        <Item stackedLabel>
                            <Label>Password:</Label>
                            <Input secureTextEntry={true}
                                onChangeText={(value) => {this.setState({password: value}) }}/>
                        </Item>
                        <ListItem>
                            <CheckBox checked={this.state.remember}
                                onPress={() => { this.setState({remember: !this.state.remember }) }}/>
                            <Body>
                                <Text>Remember Me?</Text>
                            </Body>
                        </ListItem>
                    </Form>
                    <View style={styles.btn_main_container}>
                        <View style={styles.btn_container}>
                            <Button primary bordered full
                                style={styles.btn}
                                onPress={() => { this.props.navigate(types.NAVIGATION_SIGNUP) }}>
                                <Text>Sign-up</Text>
                            </Button>
                        </View>
                        <View style={styles.btn_container}>
                            <Button primary full
                                style={styles.btn}
                                onPress={() => { 
                                    this.login();
                                }}>
                                <Text>Login</Text>
                            </Button> 
                        </View>
                    </View>
                    <Button primary full
                        style={styles.btn}
                        onPress={() => this.props.navigate(types.NAVIGATION_FORGOT_PASSWORD) }>
                        <Text>Forgot Password</Text>
                    </Button>
                </Content>
            </Container>
        );
    }
}