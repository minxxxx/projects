import React from 'react'

class LargeImage extends React.Component {
    render() {
        return (
            <img src={this.props.data.image} alt="" className="large-image"/>
        );
    }
}

export default LargeImage;