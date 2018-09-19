import React, { Component } from 'react';
import {
    Header, Left, Body, Right, Title, Icon,
    Text
} from 'native-base';
import Menu, { MenuOptions, MenuOption, MenuTrigger } from 'react-native-menu';
import * as types from '../../actions/types';

class TopHeader extends Component<{}> {
    constructor(props) {
        super(props);
    }

    navigate(value) {
        if (value === 'LOGOUT') {
            this.props.logout(this.props.loggedIn.username);
        } else {
            this.props.navigate(value);
        }
    }

    renderSettingsMenu() {
        if (this.props.showSettings) {
            return (
                <Menu onSelect={(value) => this.navigate(value) }>
                    <MenuTrigger>
                        <Icon ios='ios-settings' android="md-settings" style={{fontSize: 20, marginRight: 15}}/>
                    </MenuTrigger>
                    <MenuOptions>
                        <MenuOption value={types.NAVIGATION_PATIENT_HISTORY}>
                            <Text>History</Text>
                        </MenuOption>
                        <MenuOption value={types.NAVIGATION_PROFILE}>
                            <Text>My Profile</Text>
                        </MenuOption>
                        <MenuOption value={'LOGOUT'}>
                            <Text>Logout</Text>
                        </MenuOption>
                    </MenuOptions>
                </Menu>
            );
        }
    }

    render() {
        return (
            <Header>
                <Left>
                </Left>
                <Body>
                    <Title>{this.props.title}</Title>
                </Body>
                <Right>
                    {this.renderSettingsMenu()}
                </Right>
            </Header>
        );
    }
}

TopHeader.defaultProps = {
    title: '',
    showSettings: true
};

export default TopHeader;