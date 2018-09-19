import React, {Component} from 'react';
import QRCodeiOS from '../../native_imports/native_imports';
import { Image, AsyncStorage } from 'react-native';
import {
    View, Text
} from 'native-base';
import AesCrypto from 'react-native-aes-kit';

class QRCode extends Component {
    async getQRBase64(encryptedText) {
        try {
            var QRCodeBase64 = await QRCodeiOS.createQRCode(encryptedText);
            this.setState({
                uri: 'data:image/png;base64,' + QRCodeBase64,
                showQR: true
            });
            await AsyncStorage.setItem('@Images:QR', 'data:image/png;base64,' + QRCodeBase64);
        } catch (e) {
            console.log(e);
        }
    }

    getQR() {
        const plaintxt = this.state.value;
        const secretKey = '1234567890123456';
        const iv = '1112131415161718';

        AesCrypto.encrypt(plaintxt, secretKey, iv).then((cipher) => {
            console.log("TOKEN: " + cipher);// return a string type cipher            
            this.getQRBase64(cipher);
        }).catch(err=>{
            console.log(err);
        });
    }

    constructor(props) {
        super(props);
        this.state = {
            value: props.value,
            width: props.width,
            height: props.height,
            key: "1234567890123456",
            uri: "",
            showQR: false
        }
       this.getQR();       
    }

    renderQRCode() {
        if (this.state.showQR) {
            return (
                <Image source={{uri: this.state.uri }} style={{width: this.state.width, height: this.state.height}}/>
            );
        }
    }
    
    render() {
        return (
            <View>
                { this.renderQRCode() }
            </View> 
        )
    }
}

QRCode.defaultProps = {
    width: 200,
    height: 200,
    value: "Fooled Ya!"
}

module.exports = QRCode;