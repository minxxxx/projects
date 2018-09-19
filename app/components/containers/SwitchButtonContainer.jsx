import React from 'react'

class SwitchButtonContainer extends React.Component {
    render() {
        return (
            <div className="switch-button-container full-border">
                {this.props.children}
            </div>
        );
    }
}

export default SwitchButtonContainer;