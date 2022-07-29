- # [Digital Differential Analyzer (DDA) Algorithm](https://github.com/sthsuyash/C-projects/blob/main/Computer_Graphics/Scan_Conversion_Algorithm/DDA.cpp)

    - Step 1:
        - Get the input of two end points (x0 , y0 ) and (x1 , y1 ).

    - Step 2:
        - Calculate the differences between two end points.
        - dx = x1 - x0
        - dy = y1 - y0

    - Step 3:
        - Based on the calculated difference in Step 2, you need to identify the number of steps to put pixel.
        - If dx > dy then you need more steps in x coordinate;
        - otherwise in y coordinate.

        ```C
            if (dx > dy)
                Steps = absolute(dx);
            else
                Steps = absolute(dy);
        ```

    - Step 4:
        - Calculate the increment in x coordinate and y coordinate.
        ```C
        Xincrement = dx / (float) steps;
        Yincrement = dy / (float) steps;
        ```

    - Step 5:
        - Put the pixel by successfully incrementing x and y coordinates accordingly and complete the drawing of the line.

        ```C
            for(int v=0; v < Steps; v++) {
                x = x + Xincrement;
                y = y + Yincrement;
                putpixel(x,y);
            }
        ```
<br/><br/>
- # [Bresenham's Line Drawing Algorithm](https://github.com/sthsuyash/C-projects/blob/main/Computer_Graphics/Scan_Conversion_Algorithm/Bresenham.cpp)


Given coordinate of two points A(x1, y1) and B(x2, y2).
The task to find all the intermediate points required for drawing line AB on the computer screen of pixels.
Note that every pixel has integer coordinates.

Below are some assumptions to keep algorithm simple.
 - We draw line from left to right.
 - x1 < x2 and y1< y2
 - Slope of the line is between 0 and 1. We draw a line from lower left to upper right.

<br/><br/>
`Table to check the next point from previous`
| <p align="center">When m < 1</p>                                                                                                                                                                                                                                                                                                                                                | <p align="center">When m > 1 </p>                                                                                                                                                                                                                                                                                                                                           |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| <p align="center">P<sub>o</sub> = 2dy-dx </p>                                                                                                                                                                                                                                                                                                                                   | <p align="center">P<sub>o</sub> = 2dx-dy </p>                                                                                                                                                                                                                                                                                                                               |
| <table><tr><td>**When P < 0**</td><td>**When P > 0**</td></tr><tr><td>x<sub>i+1</sub> = x<sub>i</sub> + 1</td><td>x<sub>i+1</sub> = x<sub>i</sub> + 1</td></tr><tr><td>y<sub>i+1</sub> = y<sub>i</sub></td><td>y<sub>i+1</sub> = y<sub>i</sub> + 1</td></tr><tr><td>P<sub>i+1</sub> = P<sub>i</sub> + 2dy</td><td>P<sub>i+1</sub> = P<sub>i</sub> + 2dy - 2dx</td></tr></table> | <table><tr><td>**When P < 0**</td><td>**When P > 0**</td></tr><tr><td>x<sub>i+1</sub> = x<sub>i</sub></td><td>x<sub>i+1</sub> = x<sub>i</sub> + 1</td></tr><tr><td>y<sub>i+1</sub> = y<sub>i</sub> + 1</td><td>y<sub>i+1</sub> = y<sub>i</sub></td></tr><tr><td>P<sub>i+1</sub> = P<sub>i</sub> + 2dx</td><td>P<sub>i+1</sub> = P<sub>i</sub> + 2dx - 2dy</td></tr></table> |
