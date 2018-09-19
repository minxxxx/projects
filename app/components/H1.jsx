import React from 'react'

class H1 extends React.Component {
    render() {
        return (
            <div className="h1">
                {this.props.data.text}
            </div>
        );
    }
}

export default H1;