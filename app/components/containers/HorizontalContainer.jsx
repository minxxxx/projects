import React from 'react'

class HorizontalContainer extends React.Component {
    render() {
        return (
            <div className="horizontal-container">
                {this.props.children}
            </div>
        );
    }
}

export default HorizontalContainer;