import React from 'react'

class ModalContainer extends React.Component {
    render() {
        return (
            <div className="modal-container">
                <div className="modal-box">
                    {this.props.children}
                </div>
            </div>
        );
    }
}

export default ModalContainer;