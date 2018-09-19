import React from 'react';

import Body from "Body";
import HDivider from "HDivider";
import CenterContainer from "CenterContainer";
import Intro from "Intro";
import RoundBtnGroup from "RoundBtnGroup";
import FeatureGroup from "FeatureGroup";
import IconTextBox from "IconTextBox";

// let array = {
//     "name": "body",
//     "data": "",
//     "children": [{
//         "name": "hdivider",
//         "data": {"style": "45%"},
//         "children": [{
//             "name": "centercontainer",
//             "data": "",
//             "children": [ {
//                 "name": "intro",
//                 "data": {"title": "Bringing People and Makers together.",
//                     "text": "We are changing the way that you go at getting " +
//                     "what you need by connecting customers to makers who have " +
//                     "the skill and tools to create what you need."}
//             }
//             ]
//         }, {
//             "name": "centercontainer",
//             "data": "",
//             "children": [{
//                 "name": "roundbtngroup",
//                 "data": {"buttons": ["View Products", "Register as Maker/Designer"], "links": ["Test", "RegisterMaker"]}
//             }]
//         }]
//     }, {
//         "name": "hdivider",
//         "data": {"style": "38%"},
//         "children": [{
//             "name": "FeatureGroup",
//             "data": {"title": "Feature Design", "images": ["", "", "", ""]}
//         }]
//     }, {
//         "name": "hdivider",
//         "data": {"style": "17%"},
//         "children": [{
//             "name": "icontextbox",
//             "data": {"images": ["", "", ""], "text": ["Choose your design and order",
//                 "Review generated quotes", "Request from your preferred Maker"]}
//         }]
//     }]
// };

class Home extends React.Component {
    render() {
        return (
            <Body>
            <HDivider data={{"style": "45%"}}>
                <CenterContainer>
                    <Intro data={{"title": "Bringing People and Makers together.", "text": "We are changing the way that you go at getting what you need by connecting customers to makers who have the skill and tools to create what you need."}}/>
                </CenterContainer>
                <CenterContainer>
                    <RoundBtnGroup data={{"buttons": ["View Products", "Register as Maker/Designer"], "links": ["Search", "RegisterMaker"]}}/>
                </CenterContainer>
            </HDivider>
            <HDivider data={{"style": "38%"}}>
                <FeatureGroup data={{"title": "Feature Designs", "images": ["icons/table.jpg", "icons/vape.jpg", "icons/chess.jpg", "icons/cover.jpg"], links: ["ProductView", "", "", ""]}}/>
            </HDivider>
            <HDivider data={{"style": "17%"}}>
                <IconTextBox data={{"images": ["icons/shop.png", "icons/list.png", "icons/build.png"], "text": ["Choose your design and order", "Review generated quotes", "Request from your preferred Maker"]}}/>
            </HDivider>
            </Body>
        );
    }
}

export default Home;