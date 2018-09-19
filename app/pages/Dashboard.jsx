import React from 'react'

import Body from "Body";
import CenterContainer from "CenterContainer";
import H1 from 'H1'
import SwitchButtonGroup from "SwitchButtonGroup";
import TwoListGroup from "TwoListGroup";

// let array = {
//     name: "body",
//     data: "",
//     children: [{
//         name: "CenterContainer",
//         data: {styles: {minHeight: "100%"}},
//         children: [{
//             name: "h1",
//             data: {text: "My Dashboard"}
//         }, {
//             name: "SwitchButtonGroup",
//             data: {buttons: ["My Account Info", "Previous Orders", "Active Orders"], links: ["", "", ""]}
//         }, {
//             name: "TwoListGroup",
//             data: {left: ["Lego Piece", "Chair", "Lorem", "Ipsum", "Tabel"], right: ["View Order", "View Order", "View Order", "View Order", "View Order"]}
//         }]
//     }]
// };

class Dashboard extends React.Component {
    render() {
        return (
            <Body>
            <CenterContainer data={{styles: {minHeight: "100%"}}}>
                <H1 data={{text: "My Dashboard"}}/>
                <SwitchButtonGroup data={{buttons: ["My Account Info", "Previous Orders", "Active Orders"], links: ["Dashboard", "Dashboard", "Dashboard"]}}/>
                <TwoListGroup data={{left: ["Lego Piece", "Chair", "Tabel"], right: ["View Order", "View Order", "View Order"]}}/>
            </CenterContainer>
            </Body>
        );
    }
}

export default Dashboard;