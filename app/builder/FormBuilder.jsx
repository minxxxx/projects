import React from 'react'

import SwitchButtonContainer from 'SwitchButtonContainer'

import FormPasswordInput from 'FormPasswordInput'
import FormSubmit from 'FormSubmit'
import FormTextInput from 'FormTextInput'
import FormTextArea from 'FormTextArea'
import SwitchButton from 'SwitchButton'

let formFactory = function (type) {
    switch (type.toLowerCase()) {
        case "textinput":
           return FormTextInput;
        case "textarea":
            return FormTextArea;
        case "passwordinput":
            return FormPasswordInput;
        default:
            throw "Form Component does not exist: " + type;
    }
};

let FormGen = ({comps, names, submitName, links, linkNames}) => (
    <form action="" className="form">
        {comps.map((Comp, index) =>(
            <div key={index}>
                <div className="form-label">{names[index]}:</div>
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

class FormBuilder extends React.Component {
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

export default FormBuilder;
