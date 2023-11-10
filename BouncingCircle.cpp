// BouncingCircle.cpp - v3, 2023-08
// Edited by: PUT YOUR NAME HERE, and the DATE
//
// This program illustrates some basic graphics functions, control structures,
// and ways to use variables.
//
// Key Commands:
// G - Toggle Gravity
// T - Toggle Trails
// C - Toggle changing colors
// Q or ESC - Quit
//
// Click mouse to change position of the circle

#include "graphics.h"
#include <iostream>
#include "Shapes.h"
#include <string>
#include <random>
#include <vector>
#include <map>
using namespace std;


//functions
void displayShapes();

int main()
{
	//Variable Declarations
	int randColor = 0;
	bool keepGoing = true;       // keep running while this is true
	vector <Shapes> shape;
	char keyPressed;

	//declaring array for grid
	int grid[20][10];

	// Open a graphics window size 400 pixels wide x 800 pixels high
	initwindow(413, 813);


	//putting 0 in every place which represents an empty slot
	for (int r = 0; r < 20; r++) {
		for (int c = 0; c < 10; c++) {
			grid[r][c] = 0;
		}
	}
	//declaring current shape 
	Shapes newShape(1, grid);


	//random int for construcor color
	/*
	1 = yellow square
	2 = light blue line
	3 = orange l
	4 = backward dark blue l
	5 = green
	6 = red
	
	*/
	random_device generator;
	uniform_int_distribution<int> randomInt(1, 7);
	randColor = randomInt(generator);
	cout << randColor<< endl;


	//declaring each shape object
	
	
	
	//creates grid 
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, 1);
	//line
	
	for (int r = 40; r < 800; r+= 40) {
		line(0, r, 400, r);
	}
	line(0, 800, 400, 800);

	for (int c = 40; c < 400; c += 40) {
		line(c, 0, c, 800);
	}
	line(400, 0, 400, 800);
	


	

	

	




	cout << "meow";
	//for testing what is inside of the grid
	for (int r = 0; r < 20; r++) {
		for (int c = 0; c < 10; c++) {
			cout << grid[r][c];
		}
		cout << endl;
	}
	// Main Loop - Keep running until user quits (while keepGoing is true)
	while (keepGoing) {
		delay(60);



	} // end while keepGoing
	
	closegraph(); // shut down the graphics window
	return 0;
} // end main()



void displayShapes(vector<Shapes> shape) {
	for (int i = 0; i < shape.size(); i++) {
		cout << "meow";
	}
}
