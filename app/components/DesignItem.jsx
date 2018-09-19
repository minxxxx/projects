import React from 'react'

class DesignItem extends React.Component {
    render() {
        let stars = new Array(this.props.data.count).fill("");
        return (
            <div className="design-item">
                <img src={this.props.data.image} alt="" className="design-image"/>
                <div className="design-title">{this.props.data.title}</div>
                <div className="design-star-container">
                    {stars.map((star, index) => (
                        <img key={index} src="icons/star.png" alt="" className="design-star"/>
                    ))}
                </div>
                <div className="design-amount">{this.props.data.amount}</div>
            </div>
        );
    }
}

export default DesignItem;