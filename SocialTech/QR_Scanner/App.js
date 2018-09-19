import React, { Component } from 'react';
import { Provider } from 'react-redux';
import { createStore, applyMiddleware, combineReducers, compose } from 'redux';
import thunkMiddleware from 'redux-thunk';
import { createLogger } from 'redux-logger';
import reducer from './app/reducers';
import AppContainer from './app/containers/AppContainer';
import { MenuContext } from 'react-native-menu';
import { Root } from 'native-base';

const loggerMiddleware = createLogger({ predicate: (getState, action) => __DEV__ });

function configureStore(initialState) { 
  const enhancer = compose(
    applyMiddleware(
      thunkMiddleware,
      loggerMiddleware
    ),
  );
  return (createStore(reducer, initialState, enhancer));
}

const store = configureStore({});

const App = () => (
  <Provider store={store}>
    <Root>
      <MenuContext style={{flex: 1}}>
        <AppContainer />
      </MenuContext>
    </Root>
  </Provider>
);

export default App;