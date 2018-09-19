import React from 'react'

class InputLabel extends React.Component {
    render() {
        return (
          <div className="input-label">{this.props.data.text}</div>
        );
    }
}

export default InputLabel;