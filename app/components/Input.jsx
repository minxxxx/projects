import React from 'react'

class Input extends React.Component {
    render() {
        return (
            <input type="text" placeholder={this.props.data.placeholder} className="input" name={this.props.data.name}/>
        );
    }
}

export default Input;