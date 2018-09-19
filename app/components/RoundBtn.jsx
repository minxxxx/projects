import React from 'react'
import {Link} from 'react-router-dom'

class HorizontalContainer extends React.Component {
    render() {
        return (
            <Link to={"/" + this.props.data.link} className="round-btn full-border len42">
                {this.props.data.text}
            </Link>
        );
    }
}

export default HorizontalContainer;