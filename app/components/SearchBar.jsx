import React from 'react'

class SearchBar extends React.Component {
    render() {
        return (
            <div className="search-container">
                <div className="search-title">{this.props.data.title}:</div>
                <input type="text" className="search-bar"/>
            </div>
        );
    }
}

export default SearchBar;