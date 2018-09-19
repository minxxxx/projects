import React from 'react'

class FormTextInput extends React.Component {
    render() {
        return (
            <input className="form-input" type="text" name={this.props.data.name}/>
        );
    }
}

export default FormTextInput;