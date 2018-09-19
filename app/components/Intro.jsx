import React from 'react'

import H1 from 'H1'
import Paragraph from 'Paragraph'

class Intro extends React.Component {
    render() {

        return (
            <div>
                <H1 data={{"text": this.props.data.title}}/>
                <Paragraph data={{"text": this.props.data.text}}/>
            </div>
        );
    }
}

export default Intro;