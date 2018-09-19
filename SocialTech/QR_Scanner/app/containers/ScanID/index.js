import React, { Component } from 'react';
import * as types from '../../actions/types';
import {
   Container, Content, View, Form, Item, Label, Input,
   Button, Text, Footer, FooterTab, Icon
} from 'native-base';
import { styles } from './style';
import Menu, { MenuOptions, MenuOption, MenuTrigger } from 'react-native-menu';
import TopHeader from '../../components/TopHeader';

export default class ScanID extends Component<{}> {
    constructor(props) {
        super(props);
        this.state = {
            idNumber: ''
        }
    }

    render() {
        return (
            <Container>
                <TopHeader {...this.props} title='Scan' />
                <Content>
                    <Form>
                        <Item floatingLabel>
                            <Label>ID Number:</Label>
                            <Input maxLength={13} keyboardType='numeric'
                            onChangeText={(value) => { this.setState({idNumber: value})}}/>
                        </Item>
                    </Form>
                    <Button style={styles.btn} full
                        onPress={() => {
                            this.props.addFromIDNumber(this.state.idNumber);
                        }}>
                        <Text>Submit</Text>
                    </Button>
                </Content>
                <Footer>
                <FooterTab>
                    <Button active>
                        <Text>ID Number</Text>
                    </Button>
                    <Button onPress={() => { this.props.navigate(types.NAVIGATION_SCAN_QR) }}>
                        <Text>Camera</Text>
                    </Button>
                </FooterTab>
                </Footer>
            </Container>
        );
    }
}