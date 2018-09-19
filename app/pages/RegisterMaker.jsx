import React from 'react'

import Body from "Body";
import CenterContainer from "CenterContainer";
import SwitchButtonGroup from "SwitchButtonGroup";
import H2 from "H2";
import P1 from "P1";
import FormBuilder from "FormBuilder";

// let array = {
//     "name": "body",
//     "data": "",
//     "children": [{
//         "name": "centercontainer",
//         "data": {"styles": {minHeight: "100%"}},
//         "children": [{
//             "name": "SwitchButtonGroup",
//             "data": {"buttons": ["Maker", "Designer"], "links": ["PickMaker", ""]}
//         }, {
//             "name": "h2",
//             "data": {"text": "Register to become a Maker"}
//         }, {
//             "name": "p1",
//             "data": {
//                 "text": "This is some text, for test purposes. The paragraph " +
//                 "needs to be long ish, so type type type. da da something longer. " +
//                 "And some more texts da boom ba da pa."
//             }
//         }, {
//             "name": "p1",
//             "data": {
//                 "text": "This is some text, for test purposes. The paragraph " +
//                 "needs to be long ish, so type type type. da da something longer."
//             }
//         }, {
//             "name": "p1",
//             "data": {
//                     "text": "This is some text, for test purposes. The paragraph " +
//                     "needs to be long ish, so type type type. da da something longer. " +
//                     "And some more texts da boom."
//             }
//         }, {
//             "name": "h2",
//             "data": {"text": "Details:"}
//         }, {
//             "name": "FormBuilder",
//             "data": {
//                 "types": ["TextInput", "TextInput", "TextArea"], "names": ["Name", "Email", "Description"],
//                 "submitName": "Submit", "links": ["MakerDashboard"], "linkNames": ["Dashboard-TestOnly"]
//             }
//         }]
//     }]
// };

class RegisterMaker extends React.Component {
    render() {
        return (
            <Body>
            <CenterContainer data={{"styles": {minHeight: "100%"}}}>
                <SwitchButtonGroup data={{"buttons": ["Maker", "Designer"], "links": ["RegisterMaker", "RegisterDesigner"]}}/>
                <H2 data={{"text": "Register to become a Maker"}}/>
                <P1 data={{"text": "Makers are a big part of this platform. They make the designs of our designers as requested by people who want the design."}}/>
                <P1 data={{"text": "If you are proud and passionate about your craftsmanship as a Maker then join this revolutionary platform and make a income out of your passion."}}/>
                <H2 data={{"text": "Details:"}}/>
                <FormBuilder data={{"types": ["TextInput", "TextInput", "TextArea"], "names": ["Name", "Email", "Description"], "submitName": "Submit", "links": [], "linkNames": []}}/>
            </CenterContainer>
            </Body>
        );
    }
}

export default RegisterMaker;