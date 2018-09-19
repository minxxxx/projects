import React from 'react'

class P1 extends React.Component {
    render() {
        return (
            <div className="p1">
                {this.props.data.text}
            </div>
        );
    }
}

export default P1;