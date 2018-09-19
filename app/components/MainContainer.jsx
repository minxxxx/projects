import React from 'react';
import {Router, Route} from 'react-router-dom';
import {connect} from 'react-redux';

import Background from "Background";
import Header from 'Header';
import CustomerLogin from 'CustomerLogin';
import CustomerRegister from 'CustomerRegister';
import Customize from 'Customize';
import Dashboard from "Dashboard";
import Home from 'Home';
import MakerDashboard from 'MakerDashboard';
import PickMaker from 'PickMaker';
import ProductView from 'ProductView';
import RegisterMaker from 'RegisterMaker';
import RegisterDesigner from 'RegisterDesigner';
import DesignerDashboard from 'DesignerDashboard';
import NewDesign from "NewDesign";
import Search from 'Search';
import Loader from 'Loader';

import reactHistory from 'reactHistory'

class MainContainer extends React.Component {
	render() {
		var {loading} = this.props;

		return (
			<Router history={reactHistory}>
				<div>
					{loading ? <Loader/> : null}
					<Header status='Register/Login'/>
                    <Background data={{image: "icons/workstation.jpg"}}/>
					<Route exact path="/" component={Home}/>
					<Route path="/RegisterMaker" component={RegisterMaker}/>
					<Route path="/RegisterDesigner" component={RegisterDesigner}/>
					<Route path="/MakerDashboard" component={MakerDashboard}/>
					<Route path="/Dashboard" component={Dashboard}/>
					<Route path="/PickMaker" component={PickMaker}/>
					<Route path="/ProductView" component={ProductView}/>
					<Route path="/Login" component={CustomerLogin}/>
					<Route path="/Register" component={CustomerRegister}/>
					<Route path="/DesignerDashboard" component={DesignerDashboard}/>
					<Route path="/NewDesign" component={NewDesign}/>
					<Route path="/Search" component={Search}/>
					<Route path="/Customize" component={Customize}/>
					<div className="footer divider-border"/>
				</div>
			</Router>
		)
	}
}

export default connect(
	(state) => {
		return {
			loading: state.loading
		}
})(MainContainer);
