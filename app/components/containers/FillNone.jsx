import React from 'react'

class FillNone extends React.Component {
    render() {
        return (
            <div className="fill-none">
                {this.props.children}
            </div>
        );
    }
}

export default FillNone;