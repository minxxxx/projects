import React from 'react'

let Paragraphs = ({texts}) => (
    <div className="p">
        {texts.map((text, index) => (
            <div key={index}>{text}</div>
        ))}
    </div>
);

class Paragraph extends React.Component {
    render() {
        let str = this.props.data.text.split('<br>');
        return (
            <Paragraphs texts={str}/>
        );
    }
}

export default Paragraph;