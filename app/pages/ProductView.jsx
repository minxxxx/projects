import React from 'react'

import Body from "Body";
import CenterContainer from "CenterContainer";
import FillContainer from "FillContainer";
import FillNone from "FillNone";
import Fill from "Fill";
import LargeImage from "LargeImage";
import H1 from "H1";
import SwitchButtonGroup from "SwitchButtonGroup";
import Paragraph from "Paragraph";

// let array = {
//     name: "body",
//     data: "",
//     children: [{
//         name: ""
//     }]
// };

class ProductView extends React.Component {
    render() {
        return (
            <Body>
            <CenterContainer data={{styles: {minHeight: "100%"}}}>
                <FillContainer>
                    <FillNone>
                        <CenterContainer>
                            <LargeImage data={{image: "icons/table.jpg"}}/>
                        </CenterContainer>
                    </FillNone>
                    <Fill>
                        <H1 data={{text: "Table"}}/>
                        <Paragraph data={{text: "Description <br> Text more text and you know the story <br> Length: 1800mm <br> Width: 1800mm <br> Height: 1200mm"}}/>
                        <Paragraph data={{text: "Design Cost: R42"}}/>
                        <CenterContainer>
                            <SwitchButtonGroup data={{buttons: ["Customize", "Request Quotes"], links: ["Customize", "PickMaker"]}}/>
                        </CenterContainer>
                    </Fill>
                </FillContainer>
            </CenterContainer>
            </Body>
        );
    }
}

export default ProductView;