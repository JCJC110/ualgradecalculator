# UAL Grades Calculator
#### Video Demo:  <[URL HERE](https://youtu.be/6kmtO6t7ROg)>
#### Description:

A grades calculator that calculates an undergrad student's Degree Classification(First, 2:1, 2:2, 3rd, or fail) based on their grades, for University of the Arts London students.

Takes in 100 credits of course work units from year 2, 120 credits of course work units from year 3, calculates degree classification using the 2 methods in the specifications of the [UAL 15 point grading system document](https://www.arts.ac.uk/__data/assets/pdf_file/0037/343999/UAL-15-Point-Marking-Scale-and-Grade-Calculation-Explainer-PDF-163KB.pdf).
When the student input the number of units they have in each year, the form dynamically generates input forms for them to input their grades and respective credits for the units.
If the student does not input anything for the credit text box, the website will prompt the student again to input credit amount for the unit.
If the student inputs units in Y2 that does not amount to 100 credits worth, or units in Y3 that does not amount to 120 credits worth, the website will prompt the student to enter again, since calculations take in only 100 and 120 credits from Y2 and Y3 respectively.

Logic files contain the calculation logic that was made before it was put into the html file, within the logic file are 2 such logic files, one in C, one in Python, for no particular reason other than that I was more familiar with C, so I wrote a replicate of the C file in Python for practice. I first tested the program on command line before putting that on a web canvas with user input. Taking the C program, it first collects the number of units and respective grades for both Year 2 and Year 3, converting letter grades to numerical values. It then ensures that the total credits for Year 2 and Year 3 match the required 100 and 120 credits respectively. The program calculates weighted average grades for both years, first independently and then using a combined weighted average (30% Year 2 and 70% Year 3) to determine two potential classifications. It finally determines the highest classification from the two calculated scores and prints the corresponding honors classification. Functions are used to convert grades, classify scores, and compare classifications. The convert function translates letter grades into numerical values based on a predefined scale, ensuring consistent evaluation of grades. The classify function determines the degree classification by comparing the numerical score against thresholds, returning a string that describes the honors level (e.g., First Honors, 2:1, etc.). The get_highest_classification function compares two classification scores and returns the classification for the higher score by calling the classify function. Additionally, a comparator function is defined for sorting, although it is not used in the main logic.


After making sure that the logic is functional and sound, I implemented that in index.html, using html and simple, inline javascript. The HTML provides forms where users can input the number of units and their respective grades for Year 2 and Year 3, dynamically generating these forms based on user input. JavaScript manages the conversion of letter grades to numerical values, validates credit totals, and computes weighted averages for each year. It calculates two potential classifications based on predefined criteria and determines the highest classification, mirroring the logic of the original C program. Interactive elements and calculations are handled directly in the browser, providing real-time feedback to users.

I could use flask for the logic, but I was not familiar with Javascript and wanted to use this project as practice, which I would say, as a program itself, it would be bad design to do so, since it makes the code harder to maintain and less reusable. In hindsight, there is also lack of error handling, since the program does not provide detailed feedback as to what goes wrong to users, if it ver does. One thing that I would also improve in the logic, is that I assumed students would have the intuition to only input the best 100 credits worth of course work for Y2, but in reality, students usually have more than 100 credits worth, and they might then assume that they have to input all of their grades, and would then recieve an error message. The next step to the improvement of this program would be to take in all of the students' grades from year 2, then deciphering within the program the best 100 credits worth of scores to use, and continuing with the calculation from there.

grades.css is the css file used to style the index.html page. I experimented with flexbox layouts for centering content and dynamic, interactive button design with smooth transitions and hover effects. The use of glassmorphism with semi-transparent backgrounds and backdrop blur adds a contemporary touch, while animations for background gradients and interactive elements create a visually engaging experience. Learning how to do animations on elements are one of the biggest takeaways from this project, as well as referencing ready made CSS structures online. Design choices such as text shadows and gradient effects contribute to a polished, high-tech look, making the interface both functional and aesthetically pleasing.

Overall, this is a useful application that could make the life of a UAL student a little bit easier by calculating their degree classification for them, the next step, which is a little more complicated, would be to try to expand the logic to predict the degree classification of a student based on only their grades in Y2, which is something I would like to explore how to accomplish. 
