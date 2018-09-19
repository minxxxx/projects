import React from 'react'
import Body from "Body";
import CenterContainer from "CenterContainer";
import H1 from "H1";
import FormBuilder from "FormBuilder";
import LargeImage from 'LargeImage'

class NewDesign extends React.Component {
    render() {
        return (
            <Body>
            <CenterContainer>
                <H1 data={{text: "New Design"}}/>
                <LargeImage data={{image: ""}}/>
                <FormBuilder data={{types: ["TextInput", "TextInput", "TextInput", "TextArea"], names: ["Length", "Width", "Height", "Description"], submitName: "Submit", links: [], linkNames: []}}/>
            </CenterContainer>
            </Body>
        );
    }
}

export default NewDesign;