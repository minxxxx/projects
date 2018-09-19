import React from 'react'
import Body from "Body";
import CenterContainer from "CenterContainer";
import P1 from "P1";
import DesignFormBuilder from "DesignFormBuilder";

class Customize extends React.Component {
    render() {
        return (
            <Body>
            <CenterContainer data={{styles: {minHeight: "100%"}}}>
                <P1 data={{text: "Please specify how you would like the design to be customized."}}/>
                <DesignFormBuilder data={{"types": ["Input", "Input", "Input", "InputArea"], "names": ["Length", "Width", "Height", "Other"], "submitName": "Submit", "links": [], "linkNames": []}}/>
            </CenterContainer>
            </Body>
        );
    }
}

export default Customize;