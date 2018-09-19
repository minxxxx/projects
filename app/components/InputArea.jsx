import React from 'react'

class InputArea extends React.Component {
    render() {
        return (
            <textarea name={this.props.data.name} className="input-area"/>
        );
    }
}

export default InputArea;