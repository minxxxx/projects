import React from 'react'

class Fill extends React.Component {
    render() {
        return (
            <div className="fill">
                {this.props.children}
            </div>
        );
    }
}

export default Fill;