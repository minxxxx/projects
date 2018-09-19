import React from 'react'

class ListContainer extends React.Component {
    render() {
        return (
            <div className="list-container">
                {this.props.children}
            </div>
        );
    }
}

export default ListContainer;