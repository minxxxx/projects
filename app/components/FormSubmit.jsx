import React from 'react'

class FormSubmit extends React.Component {
    render() {
        return (
            <button type="submit" className="switch-button">
                {this.props.data.text}
            </button>
        );
    }
}

export default FormSubmit;