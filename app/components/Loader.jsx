import React from 'react'

class Loader extends React.Component {
    render() {
        return (
            <div className="shadow-background">
                <div className="loader">
                    <div className="bounce1"/>
                    <div className="bounce2"/>
                    <div className="bounce3"/>
                </div>
            </div>
        );
    }
}

export default Loader;
