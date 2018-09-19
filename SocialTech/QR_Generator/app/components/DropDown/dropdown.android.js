import React, { Component } from 'react';
import { Container, Content, Picker, Text } from 'native-base';


class DropDown extends Component {

    constructor(props) {
        super(props);
        this.state = {
            selectedItem: undefined,
            selected1: 'key1',
            results: {
                items: []
            }
        }
    }

    onValueChange (value) {
        this.setState({
            selected1 : value
        });
        this.props.onSelectedChanged(value);
    }

    render() {
        return (
            <Picker style={{margin: 8}}
                iosHeader={this.props.title}
                mode="dropdown"
                placeholder={this.props.title}
                selectedValue={this.state.selected1}
                onValueChange={this.onValueChange.bind(this)}>
                {
                    this.props.list.map((name, i) => {
                        return <Picker.Item key={i} label={name} value={name}/>
                    })
                }
            </Picker>
        );
    }
}

DropDown.defaultProps = {
    title: "Select"
};

export default DropDown;