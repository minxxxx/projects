import React from 'react'

class TwoItem extends React.Component {
    render() {
        return (
            <div className="two-item">
                <div className="left-text">{this.props.data.left}</div>
                <div className="right-text">{this.props.data.right}</div>
            </div>
        );
    }
}

export default TwoItem;