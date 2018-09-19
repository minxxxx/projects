import React from 'react'

import FormSubmit from 'FormSubmit'
import Input from 'Input'
import InputArea from 'InputArea'
import InputLabel from 'InputLabel'
import SwitchButtonContainer from 'SwitchButtonContainer'
import SwitchButton from 'SwitchButton'

let formFactory = function (type) {
    switch (type.toLowerCase()) {
        case "input":
           return Input;
        case "inputarea":
            return InputArea;
        default:
            throw "Form Component does not exist: " + type;
    }
};

let FormGen = ({comps, names, submitName, links, linkNames}) => (
    <form action="" className="form">
        {comps.map((Comp, index) =>(
            <div key={index} className="label-input-container">
                <InputLabel data={{text: names[index]}}/>
                <Comp data={{"name": names[index]}}/>
            </div>
        ))}
        <SwitchButtonContainer>
            <FormSubmit data={{"text": submitName}}/>
            {links.map((link, index) => (
                <SwitchButton key={index} data={{"link": link, "text": linkNames[index]}}/>
            ))}
        </SwitchButtonContainer>
    </form>
);

class DesignFormBuilder extends React.Component {
    render() {
        let components = [];
        this.props.data.types.forEach(function(type) {
            components.push(formFactory(type));
        });
        return (
            <FormGen comps={components} names={this.props.data.names} submitName={this.props.data.submitName}
                     links={this.props.data.links} linkNames={this.props.data.linkNames} />
        );
    }
}

export default DesignFormBuilder;