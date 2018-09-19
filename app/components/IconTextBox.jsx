import React from 'react'

import BaselineContainer from 'BaselineContainer'
import IconText from 'IconText'


let ImageText = ({images, text}) => (
    <BaselineContainer>
        {images.map((image, index) => (
            <div key={index} className="center-container">
                <IconText data={{"image": image, "text": text[index]}}/>
            </div>
        ))}
    </BaselineContainer>
);

class IconTextBox extends React.Component {
    render() {
        return (
            <ImageText images={this.props.data.images} text={this.props.data.text}/>
        );
    }
}

export default IconTextBox;