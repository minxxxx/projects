import React from 'react'
import {Link} from 'react-router-dom'

function checkLink(links, image, index) {
    let size = links.length;
    if (size > 0 && index < size) {
        return (<Link key={index}to={"/" + links[index]}><img key={index} src={image} alt="" className="image"/></Link>);
    } else {
        return (<img key={index} src={image} alt="" className="image"/>);
    }
}

let Images = ({images, links}) => (
    <div className="image-group">
        {images.map((image, index) => checkLink(links, image, index))}
    </div>
);

class ImageGroup extends React.Component {
    render() {
        return (
            <div className="image-container">
                <div className="image-category-container"></div>
                <Images images={this.props.data.images} links={this.props.data.links}/>
            </div>
        );
    }
}

export default ImageGroup;