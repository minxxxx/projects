import React from 'react'

class FillContainer extends React.Component {
    render() {
        return (
            <div className="fill-container">
                {this.props.children}
            </div>
        );
    }
}

export default FillContainer;