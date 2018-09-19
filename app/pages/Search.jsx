import React from 'react';
import Body from "Body";
import CenterContainer from "CenterContainer";
import FillContainer from "FillContainer";
import FillNone from "FillNone";
import Fill from "Fill";
import ImageGroup from "ImageGroup";
import VerticalMenu from "VerticalMenu";
import SearchBar from "SearchBar";

class Search extends React.Component {
    render() {
        return (
            <Body>
            <CenterContainer>
                <div style={{width: "calc(50 * var(--unit))", padding: "calc(1 * var(--unit))"}}>
                    <SearchBar data={{title: "Search"}}/>
                </div>
                <FillContainer>
                    <FillNone>
                        <VerticalMenu data={{tabs: ["Tables", "Vape", "HouseHold", "Sport", "Games", "Figures", "Phone Covers"]}}/>
                    </FillNone>
                    <Fill>
                        <ImageGroup data={{images: ["icons/table.jpg", "icons/vape.jpg", "icons/stool.jpg", "icons/house.jpg", "icons/ping-pong.jpg", "icons/box.jpg", "icons/chess.jpg", "icons/platter.jpg", "icons/cover.jpg", "icons/clips.jpg", "icons/robot.jpg"], links: ["ProductView"]}}/>
                    </Fill>
                </FillContainer>
            </CenterContainer>
            </Body>
        );
    }
}

export default Search;