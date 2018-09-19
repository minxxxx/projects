import React from 'react'

class Background extends React.Component {
    render() {
        return (
            <div className="background-img" style={{backgroundImage: "url(" + this.props.data.image + ")"}}/>
        );
    }
}

export default Background;