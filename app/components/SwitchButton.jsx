import React from 'react'
import {Link} from 'react-router-dom'

class SwitchButton extends React.Component {
    render() {
        return (
            <Link to={"/" + this.props.data.link} className="switch-button">{this.props.data.text}</Link>
        );
    }
}

export default SwitchButton;