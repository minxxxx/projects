import React from 'react'

import ButtonsContainer from "ButtonsContainer";
import RoundBtn from 'RoundBtn'

let Buttons = ({buttons, links}) => (
    <ButtonsContainer>
        {buttons.map((button, index) => (
            <RoundBtn key={index} data={{"text": button, "link": links[index]}}/>
        ))}
    </ButtonsContainer>
);

class RoundBtnGroup extends React.Component {
    render() {
        return (
            <Buttons buttons={this.props.data.buttons} links={this.props.data.links}/>
        );
    }
}

export default RoundBtnGroup;