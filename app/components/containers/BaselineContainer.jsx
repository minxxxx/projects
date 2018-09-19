import React from 'react'

class BaselineContainer extends React.Component {
    render() {
        return(
            <div className="baseline-center">
                {this.props.children}
            </div>
        );
    }
}

export default BaselineContainer;