import React from 'react'

import Body from "Body";
import CenterContainer from "CenterContainer";
import H2 from "H2";
import P1 from "P1";
import DesignListGroup from "DesignListGroup";

// let array = {
//     name: "body",
//     data: "",
//     children: [{
//         name: "CenterContainer",
//         data: {styles: {minHeight: "100%"}},
//         children: [{
//             name: "ModalContainer",
//             data: "",
//             children: [{
//                 name: "h2",
//                 data: {text: "Select a Maker to create your selected design."}
//             }, {
//                 name: "p1",
//                 data: {text:"Select a maker from the list of live quotes below."}
//             }, {
//                 name: "DesignListGroup",
//                 data: {images: ["icons/gallery.png", "icons/gallery.png"], titles: ["Maker 1", "Maker 2"],
//                     counts: [2, 4], amounts: ["R200", "R250"]}
//             }]
//         }]
//     }]
// };

class PickMaker extends React.Component {
    render() {
        return (
            <Body>
            <CenterContainer data={{styles: {minHeight: "100%"}}}>
                <H2 data={{text: "Select a Maker to create your selected design."}}/>
                <P1 data={{text:"Select a maker from the list of live quotes below."}}/>
                <DesignListGroup data={{images: ["icons/profile1.png", "icons/profile2.png"], titles: ["Maker 1", "Maker 2"], counts: [2, 4], amounts: ["R200", "R250"]}}/>
            </CenterContainer>
            </Body>
        );
    }
}

export default PickMaker;