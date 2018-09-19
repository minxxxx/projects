import React from 'react'

import ListContainer from 'ListContainer'
import TwoItem from 'TwoItem'

let Items = ({left, right}) => (
    <ListContainer>
        {left.map((l, index) => (
            <TwoItem key={index} data={{left: l, right: right[index]}}/>
        ))}
    </ListContainer>
);

class TwoListGroup extends React.Component {
    render() {
        return (
            <Items left={this.props.data.left} right={this.props.data.right} />
        );
    }
}

export default TwoListGroup;