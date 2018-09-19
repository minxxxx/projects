import React from 'react'

const Test = ({array}) => (
    <div>
        {array.map((ar, id) => (
            <h1 key={id}>{ar}</h1>
        ))}
    </div>
);

const array = ["This is a test.", "Testing one two."];

const Comp = Test

class About extends React.Component {
    render() {
        return (
            <div className={"body"}>
                <Comp array={array}/>
            </div>
        );
    }
}

export default About;