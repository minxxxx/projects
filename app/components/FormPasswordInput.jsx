import React from 'react'

class FormPasswordInput extends React.Component {
    render() {
        return (
            <input type="password" className="form-input" name={this.props.data.name}/>
        );
    }
}

export default FormPasswordInput;