import React from 'react'

import SwitchButton from 'SwitchButton'
import SwitchButtonContainer from 'SwitchButtonContainer'

let SwitchButtons = ({buttons, links}) => (
    <SwitchButtonContainer>
        {buttons.map((button, index) => (
            <SwitchButton key={index} data={{"text": button, "link": links[index]}}/>
        ))}
    </SwitchButtonContainer>
);

class SwitchButtonGroup extends React.Component {
    render() {
        return (
            <SwitchButtons buttons={this.props.data.buttons} links={this.props.data.links}/>
        );
    }
}

export default SwitchButtonGroup;