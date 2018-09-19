import React from 'react'

import Body from "Body";
import CenterContainer from "CenterContainer";
import H1 from "H1";
import SwitchButtonGroup from "SwitchButtonGroup";
import FillContainer from "FillContainer";
import FillNone from "FillNone";
import Fill from "Fill";
import VerticalMenu from "VerticalMenu";
import ImageGroup from "ImageGroup";

// let array = {
//     name:"body",
//     data:"",
//     children: [{
//         name: "CenterContainer",
//         data:"",
//         children: [{
//             name:"H1",
//             data:{text: "Maker Dashboard"}
//         }, {
//             name:"SwitchButtonGroup",
//             data:{buttons: ["Account Info", "Designs", "Orders"], links: ["", "", "Dashboard"]}
//         }, {
//             name:"FillContainer",
//             data:"",
//             children: [{
//                 name:"FillNone",
//                 data:"",
//                 children: [{
//                     name:"VerticalMenu",
//                     data:{tabs: ["New", "Improved", "Decline"]}
//                 }]
//             }, {
//                 name:"Fill",
//                 data:"",
//                 children:[{
//                     name:"ImageGroup",
//                     data:{images: ["", "", "", "", "", "", "", "", "", "", "", "", ""]}
//                 }]
//             }]
//         }]
//     }]
// };

class MakerDashboard extends React.Component {
    render() {
        return (
            <Body>
            <CenterContainer>
                <H1 data={{text: "Maker Dashboard"}}/>
                <SwitchButtonGroup data={{buttons: ["Account Info", "Designs", "Orders"], links: ["", "", "Dashboard"]}}/>
                <FillContainer>
                    <FillNone>
                        <VerticalMenu data={{tabs: ["New", "Improved", "Declined"]}}/>
                    </FillNone>
                    <Fill>
                        <ImageGroup data={{images: ["icons/table.jpg" ,"icons/robot.jpg", "icons/cover.jpg"], links: ["ProductView"]}}/>
                    </Fill>
                </FillContainer>
            </CenterContainer>
            </Body>
        );
    }
}

export default MakerDashboard;