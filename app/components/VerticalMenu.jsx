import React from 'react'

let MenuItems = ({tabs}) => (
    <div className="vertical-tab-menu">
        {tabs.map((tab, index) => (
            <div key={index} className="vertical-tab">{tab}</div>
        ))}
    </div>
);

class VerticalMenu extends React.Component {
    render() {
        return (
            <MenuItems tabs={this.props.data.tabs} />
        );
    }
}

export default VerticalMenu;