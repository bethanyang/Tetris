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
void printGrid(int arr[20][10]);
void displayGraph(int arr[20][10]);
int main()
{
	//Variable Declarations
	int randColor = 0;
	bool keepGoing = true;       // keep running while this is true
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
	Shapes currentShape(4, grid);


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
	uniform_int_distribution<int> randomInt(1, 6);
	randColor = randomInt(generator);
	cout << randColor << endl;


	// Main Loop - Keep running until user quits (while keepGoing is true)
	while (keepGoing) {
		delay(500);
		displayGraph(grid, currentShape.getColor());
		if (currentShape.set(grid)) {
			randColor = randomInt(generator);
			currentShape = Shapes(4, grid);
		}
		currentShape.fall(grid);
		for (int r = 19; r >= 0; r--) {
			if (currentShape.canClear(grid, r)) {
				currentShape.clearLine(grid, r);
			}
		}
		if (currentShape.gameOver(grid)) {
			keepGoing = false;
		}
		if (kbhit()) {
			keyPressed = getch();
			if (keyPressed == 'q' || keyPressed == 'Q' || keyPressed == 0x1b) {  // q - quit, 0x1b is ESC key
				keepGoing = false;
			}
			if (keyPressed == 'g') {
				if (currentShape.updateLeftHorizontalPosition(grid, keyPressed)) {
					currentShape.moveHorizontal(grid, keyPressed);
				}
				printGrid(grid);
			}
			if (keyPressed == 'j') {
				cout << "pressed j" << endl;
				if (currentShape.updateRightHorizontalPosition(grid, keyPressed)) {
					currentShape.moveHorizontal(grid, keyPressed);
				}
				printGrid(grid);
			}

		}
		cout << "new grid";
		printGrid(grid);
	}
// end while keepGoing
	//for testing what is inside of the grid
	closegraph(); // shut down the graphics window
	//printGrid(grid);
	return 0;

}


void printGrid(int arr[20][10]) {
	for (int r = 0; r < 20; r++) {
		for (int c = 0; c < 10; c++) {
			cout << arr[r][c];
		}
		cout << endl;
	}
}
void displayGraph(int arr[20][10], int color) {
	//creates grid 
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, 1);
	//line

	for (int r = 40; r < 800; r += 40) {
		line(0, r, 400, r);
	}
	line(0, 800, 400, 800);

	for (int c = 40; c < 400; c += 40) {
		line(c, 0, c, 800);
	}
	line(400, 0, 400, 800);
}
