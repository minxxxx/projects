import React from 'react'

class H2 extends React.Component {
    render() {
        return (
            <div className="h2">
                {this.props.data.text}
            </div>
        );
    }
}

export default H2;