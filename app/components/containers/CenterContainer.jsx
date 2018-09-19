import React from 'react'

class CenterContainer extends React.Component {
    render() {
        return (
            <div className="center-container" style={this.props.data.styles}>
                {this.props.children}
            </div>
        );
    }
}

CenterContainer.defaultProps = {
    data: {styles: {}}
};

export default CenterContainer;