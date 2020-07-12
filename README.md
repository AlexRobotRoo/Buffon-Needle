# Buffon-Needle
***Visualization of a needle-throwing experiments in the console window. The Buffon's needle problem is a classical problem in the theory of geometric probability, which is considered to be the starting point for the development of this theory.***

***The program is realized in MVSE 2015. The type of the project is Visual C++ console application Win32.***

<h2> Problem formulation </h2>
Parallel lines are drawn on the plane, located at a distance 2a from each other. A needle with length 2l<2a is thrown at random on the plane . What is the probability that the needle will cross a straight line?

<h2> Task analysis </h2>
Let's understand what "a needle thrown at random" means here.
The possible positions of the needle (segment) on the plane are completely determined by the position of the middle of the needle and the angle of rotation of the needle relative to any direction. Moreover, these two variables (the position of the center and the angle of rotation) change independently of each other. Denote by xЄ[0,a] the distance from the middle of the needle to the nearest straight line, and by ∂Є[0,∏] the angle between some direction of the straight lines and the needle.
The set of possible needle positions is entirely determined by choosing a random point from the rectangle Ω = [0,∏]Ú[0,a].
The needle intersects the nearest straight line if the coordinates of the randomly selected point satisfy the inequality: x <= l*sin ∂. 
The required probability is equal to P(A) = 2*l/(a*∏). This is theoretical value.

<h2> The aim of the work </h2>
The aim of the work is to determine the relation between the probability value and the number of experiments, and compare the experimental and theoretical probability values.

<h2> Solution description </h2>
 Buffon's Needle.vcxproj
 
This is the main VC++ project file that is created using the application wizard. It contains information about the version of the Visual C++ language used to create the file, as well as information about the platforms, configurations, and features of the project selected using the application wizard.

Buffon's Needle.vcxproj.filters

This is a filter file for VC++ projects created using the application wizard. It contains information about the mapping between files in your project and filters. These mappings are used in the IDE to group files with the same extensions in the same node (for example, CPP files are mapped to the Source files filter).

Buffon's Needle.cpp

This is the main source file of the application.

/////////////////////////////////////////////////////////////////////////////

Other standard files:

StdAfx.h, StdAfx.cpp

These files are used to build a precompiled header (PCH) file named Buffon's Needle.pch and a precompiled type file named StdAfx.obj.

<h2> Description of the "Buffon's Needle.cpp" </h2>
The method 

>struct Out Bros(float xn, float yn, float a, float l, float lines[15])

realizes the generating random needle and the throws it.
It takes drawing field coordinates xn and yn, a(half distance between the lines), l(needle length) and a massive of lines as inputs and returns a structure

>struct Out
>{
>>	float x1;
>>	float y1;
>>	float x2;
>>	float y2;
>>	bool per;
.};

where x1, y1, x2, y2 are coordinates of generated needle and the per is true if there was intersection and false if there wasn't.
In the **main** there is a while cycle and the switch case construction, where the program is handle SPACE bar pushing, until the ESC is pushed. Inside the SPACE bar pushed handler this method is called and based on the returned data th practical probabilty and the number of intersects are changed and printed on the screen.
***The differences between theoretical and practically calculated probabilities are recorded in the "output.txt" file. The recording happens every time a new needle is thrown.***

<h2> Console window description </h2>
There are drown 15 parallel horizontal lines. The randomized needle is placed somewhere in the field with lines, when the SPACE bar is pushed.
In the right part of the screen there is info about number of experiments, number of intersections, the practical and theoretical probabilities.

<h2> Results </h2>
The results are presented with two screenshots. In one of them is console window when program is working and in another is chart, based on output.txt data. That chart shows that with increasing of the number of experiments the practical probability approaches to theoretical value.

