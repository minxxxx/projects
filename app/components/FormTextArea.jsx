import React from 'react'

class FormTextArea extends React.Component {
    render() {
        return (
            <textarea className="form-area" name={this.props.data.name} rows="5" />
        );
    }
}

export default FormTextArea;