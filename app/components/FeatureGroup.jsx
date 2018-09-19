import React from 'react'
import {Link} from 'react-router-dom'
let Images = ({images, links}) => (
    <div className="feature-body">
        {images.map((image, index) => (
            <Link to={"/" + links[index]} key={index} className="center-container">
                <img src={image} alt="" className="image"/>
            </Link>
        ))}
    </div>
);

class FeatureGroup extends React.Component {
    render() {
        return (
            <div className="feature-container">
                <div className="feature-title-bar">
                    <div className="feature-title">{this.props.data.title}</div>
                </div>
                <Images images={this.props.data.images} links={this.props.data.links}/>
            </div>
        );
    }
}

export default FeatureGroup;