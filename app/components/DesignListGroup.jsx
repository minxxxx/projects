import React from 'react';

import ListContainer from 'ListContainer'
import DesignItem from 'DesignItem'

let Items = ({images, titles, counts, amounts}) => (
    <ListContainer>
        {images.map((image, index) => (
            <DesignItem key={index} data={{image: image, title: titles[index], count: counts[index], amount: amounts[index]}}/>
        ))}
    </ListContainer>
);

class DesignListGroup extends React.Component {
    render() {
        return (
            <Items images={this.props.data.images} titles={this.props.data.titles} counts={this.props.data.counts} amounts={this.props.data.amounts} />
        );
    }
}

export default DesignListGroup
