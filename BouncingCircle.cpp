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
void displayGraph(int arr[20][10], int color);
void showScore(int score);
void gameOver(int arr[20][10], int score, bool &pA, bool &kG);

int main()
{
	//Variable Declarations
	int randColor = 0;
	bool keepGoing = true;       // keep running while this is true
	char keyPressed;
	int score = 0;
	bool playAgain = true;
	//declaring array for grid
	int grid[20][10];

	// Open a graphics window size 400 pixels wide x 800 pixels high
	initwindow(413, 870);
	//putting 0 in every place which represents an empty slot
	for (int r = 0; r < 20; r++) {
		for (int c = 0; c < 10; c++) {
			grid[r][c] = 0;
		}
	}



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
	//declaring current shape 
	Shapes currentShape(randColor, grid);

	int delayPace = 500;
	do {
		// Main Loop - Keep running until user quits (while keepGoing is true)
		while (keepGoing) {
			delay(delayPace);
			if (currentShape.set(grid, score)) {
				delayPace = 500;
				randColor = randomInt(generator);
				currentShape = Shapes(randColor, grid);
			}
			currentShape.fall(grid);
			displayGraph(grid, currentShape.getColor());
			showScore(score);
			for (int r = 19; r >= 0; r--) {
				if (currentShape.canClear(grid, r)) {
					currentShape.clearLine(grid, r);
					score += 90;
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
					if (currentShape.updateRightHorizontalPosition(grid, keyPressed)) {
						currentShape.moveHorizontal(grid, keyPressed);
					}
					printGrid(grid);
				}
				if (keyPressed == ' ') {
					delayPace = 10;
				}
				displayGraph(grid, currentShape.getColor());

			}

			printGrid(grid);
		}
		gameOver(grid, score, playAgain, keepGoing);
	} while (playAgain);
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

void showScore(int score) {
	// Draw score on the screen
	char s[20];
	sprintf_s(s, "Score: %d", score);

	setcolor(WHITE);
	outtextxy(20, 820, &s[0]);

}

void displayGraph(int arr[20][10], int color) {
	//sees what color is the shape
	string COLOR;
	switch (color) {
	case 1:
		COLOR = "YELLOW";
		break;

	case 2:
		COLOR = "CYAN";
		break;

	case 3:
		COLOR = "BROWN";
		break;

	case 4:
		COLOR = "BLUE";
		break;

	case 5:
		COLOR = "GREEN";
		break;

	case 6:
		COLOR = "RED";
	}

	//bar(amount from the left, start point from top, second amount from left, where the bottom is 

	for (int r = 0; r < 20; r++) {
		for (int c = 0; c < 10; c++) {
			if (arr[r][c] == 2) {
				setcolor(color);
				setfillstyle(SOLID_FILL, color);
				bar(40 * c, 40 * r, 40 + (40 * c), 40 + (40 * r));
			}
			else if (arr[r][c] == 1) {
				setcolor(LIGHTGRAY);
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				bar(40 * c, 40 * r, 40 + (40 * c), 40 + (40 * r));
			}
			else {
				setcolor(BLACK);
				setfillstyle(SOLID_FILL, BLACK);
				bar(40 * c, 40 * r, 40 + (40 * c), 40 + (40 * r));

			}
		}
	}
	//bar(40*4, 40*2, 40 + 160, 40 + 80);
	//creates grid 
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, 1);
	for (int r = 40; r < 800; r += 40) {
		line(0, r, 400, r);
	}
	line(0, 800, 400, 800);

	for (int c = 40; c < 400; c += 40) {
		line(c, 0, c, 800);
	}
	line(400, 0, 400, 800);

}

void gameOver(int arr[20][10], int score, bool &pA, bool &kG){
	
	setcolor(BLUE);
	setfillstyle(SOLID_FILL, BLUE);
	bar(0, 0, 413, 870);
	
	//413 by 870
	settextjustify(CENTER_TEXT, TOP_TEXT);
	setcolor(WHITE);
//prints score
	char s[30];
	sprintf_s(s, "Score: %d", score);

	setcolor(WHITE);
	outtextxy(206, 200, &s[0]);
	//prints game over 
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
	outtextxy(206, 300, (char*)"GAME OVER!");

	//print choose p or choose x
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(206, 450, (char*)"Press 'p' to play again");

	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(206, 550, (char*)"Press 'x' to exit");
	char keyPressed;

	if (kbhit()) {
		keyPressed = getch();
		if (keyPressed == 'p') {
			for (int r = 0; r < 20; r++) {
				for (int c = 0; c < 10; c++) {
					arr[r][c] = 0;
				}
			}
			pA = true;
			kG = true;

		}
	}
		//else if(keyPressed == 'x'){


	// show the score
	// click p to play again click x to exit
	// //if p grid 
	//if yes create empty grid and restart
	/*
	for (int r = 0; r < 20; r++) {
		for (int c = 0; c < 10; c++) {
			if (arr[r][c] == 2) {
				
		}
	}*/


}
