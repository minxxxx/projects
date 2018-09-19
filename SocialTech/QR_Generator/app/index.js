import React, { Component } from 'react';
import { View } from 'react-native';
import {
	Router,
	Stack,
	Scene,
	Overlay,
	Modal
} from 'react-native-router-flux';
import CardStackStyleInterpolator from 'react-navigation/src/views/CardStack/CardStackStyleInterpolator';

import Home from './screens/home';
import Disclaimer from './screens/disclaimer';

import PersonalDetails from './screens/personalDetails';
import NextOfKin from './screens/nextOfKin';
import MedicalDetails from './screens/medicalDetails';
import CreateQR from './screens/createQR';
import EmailQR from './screens/emailQR';

const QR_Generator = (props) => {
	return (
		<Router>
			<Overlay>
				<Modal hideNavBar transitionConfig={() => ({ screenInterpolator: CardStackStyleInterpolator.forFadeFromBottomAndroid })}>
					
					<Stack hideNavBar key="root">
						<Scene key="Home" component={Home}/>
						<Scene key="Disclaimer" component={Disclaimer}/>
						<Scene key="PersonalDetails" component={PersonalDetails} />
						<Scene key="NextOfKin" component={NextOfKin} />
						<Scene key="MedicalDetails" component={MedicalDetails} />
						<Scene key="CreateQR" component={CreateQR} />
						<Scene key="EmailQR" component={EmailQR} />
					</Stack>
				</Modal>
			</Overlay>
		</Router>
	);
};

export default QR_Generator;