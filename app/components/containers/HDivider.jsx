import React from 'react'

class HDivider extends React.Component {
    render() {
        return (
            <div className="h-divider" style={{minHeight: this.props.data.style}}>
                {this.props.children}
            </div>
        );
    }
}

export default HDivider;
