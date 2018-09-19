import React from 'react'

import RecursivePageBuilder from 'RecursivePageBuilder'

let array = {
    "name": "body",
    "data": "",
    "children": [{
        "name": "centercontainer",
        "data": {"styles": {minHeight: "100%"}},
        "children": [{
            "name": "SwitchButtonGroup",
            "data": {"buttons": ["Maker", "Designer"], "links": ["", ""]}
        }, {
            "name": "h2",
            "data": {"text": "Register to become a Maker"}
        }, {
            "name": "p1",
            "data": {
                "text": "This is some text, for test purposes. The paragraph " +
                "needs to be long ish, so type type type. da da something longer. " +
                "And some more texts da boom ba da pa."
            }
        }, {
            "name": "p1",
            "data": {
                "text": "This is some text, for test purposes. The paragraph " +
                "needs to be long ish, so type type type. da da something longer."
            }
        }, {
            "name": "p1",
            "data": {
                    "text": "This is some text, for test purposes. The paragraph " +
                    "needs to be long ish, so type type type. da da something longer. " +
                    "And some more texts da boom."
            }
        }, {
            "name": "h2",
            "data": {"text": "Details:"}
        }, {
            "name": "ModalContainer",
            "data": "",
            "children": [{
                "name": "p1",
                "data": {text: "Please specify how you would like the design to be customized."}
            }, {
              name: "SearchBar",
              data: {title: "Search"},
            }, {
                "name": "DesignFormBuilder",
                "data": {
                    "types": ["Input", "Input", "Input", "InputArea"], "names": ["Length:", "Width:", "Height:", "Other:"],
                    "submitName": "Submit", "links": [], "linkNames": []
                }
            }]
        }]
    }]
};

class RegisterMaker extends React.Component {
    render() {
        return (
            <RecursivePageBuilder root={array}/>
        );
    }
}

export default RegisterMaker;