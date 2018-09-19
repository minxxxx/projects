import React from 'react'

class ButtonsContainer extends React.Component {
    render() {
        return (
            <div className="buttons-container">
                {this.props.children}
            </div>
        );
    }
}

export default ButtonsContainer;