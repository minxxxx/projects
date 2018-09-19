import React from 'react'

class IconText extends React.Component {
    render() {
        return (
            <div className="icon-text-container">
                <img src={this.props.data.image} alt="" className="icon-text-icon"/>
                    <div className="icon-text-text">{this.props.data.text}</div>
            </div>
        );
    }
}

export default IconText;