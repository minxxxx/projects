//Packages
import React from 'react'
import ReactDOM from 'react-dom'
import {Provider} from 'react-redux';

//Pages
import MainContainer from 'MainContainer';

//Redux
var store = require('configureStore').configure();

//Styles
import 'style-loader!css-loader!sass-loader!BaseCss'

ReactDOM.render((
		<Provider store={store}>
			<MainContainer/>
		</Provider>
    ),
    document.getElementById('app')
);
