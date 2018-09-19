import React, { Component } from 'react';
import * as types from '../../actions/types';
import {
   Container, Content, Button, Text, Footer, FooterTab,
   View
} from 'native-base';
import {
    Alert
} from 'react-native';
import { styles } from './style';
import TopHeader from '../../components/TopHeader';
import Camera from 'react-native-camera';
import Aes from 'react-native-aes-kit';

const secretKey = '1234567890123456';
const iv = '1112131415161718';

export default class ScanQR extends Component<{}> {
    constructor(props) {
        super(props);
        this.camera = null;
    }

    readQR(data, bounds) {
        Aes.decrypt(data.data, secretKey, iv).then((plainText) => {
            this.props.addFromQRCode(plainText);
            this.props.navigate(types.NAVIGATION_PATIENT_DETAILS);
        })
        .catch((err) => {
            Alert.alert('Not a valid QR code.');
        });
    }

    render() {
        return (
            <Container>
                <TopHeader {...this.props} title='Scan' />
                <Content>
                    <Camera
                        ref={(cam) => {
                            this.camera = cam;
                        }}
                        style={styles.preview}
                        aspect={Camera.constants.Aspect.fill}
                        barCodeTypes={[Camera.constants.BarCodeType.qr]}
                        onBarCodeRead={(data, bounds) => {this.readQR(data, bounds)}}>
                    </Camera>
                </Content>
                <Footer>
                <FooterTab>
                    <Button onPress={() => { this.props.navigate(types.NAVIGATION_SCAN_ID) }}>
                        <Text>ID Number</Text>
                    </Button>
                    <Button active>
                        <Text>Camera</Text>
                    </Button>
                </FooterTab>
                </Footer>
            </Container>
        );
    }
}