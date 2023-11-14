#include "Shapes.h"
#include <string>
#include <iostream>
#include <map>
#include "graphics.h"

using namespace std;

Shapes::Shapes() {}

Shapes::Shapes(int color, int arr[20][10]) {
	this->color_ = color;
	if (color_ == 1) {
		colorOne(arr);
	}
	else if (color_ == 2) {
		colorTwo(arr);
	}
	else if (color_ == 3) {
		colorThree(arr);
	}
	else if (color_ == 4) {
		colorFour(arr);
	}
	else if (color_ == 5) {
		colorFive(arr);
	}
	else if (color_ == 6) {
		colorSix(arr);
	}
}

int Shapes::getColor() {
	return this->color_;
}
//moves horiontally updates grid and coorindates
void Shapes::moveHorizontal(int arr[20][10], char letterEntered) {
	int temp = 0; //for swapping later
	int shift;
	if (letterEntered == 'g') {
		shift = -1;
	}
	else {
		shift = 1;
	}
	int posX, posY;
	if (letterEntered == 'j') {
		for (int r = 3; r >= 0; r--) {
			posX = coordinates_[r][1];
			posY = coordinates_[r][0];
			//switches current value and value to the left on the grid
			temp = arr[posY][posX];
			//takes current position(x) of each box and moves it to the left one on the grid
			arr[posY][posX] = arr[posY][posX + shift];
			//takes (x) and changes it to 0 i hope this is so tragic
			arr[posY][posX + shift] = temp;
		}
	}
	else if (letterEntered == 'g') {
		for (int r = 0; r < positionLength_; r++) {
			posX = coordinates_[r][1];
			posY = coordinates_[r][0];
			//switches current value and value to the left on the grid
			temp = arr[posY][posX];
			//takes current position(x) of each box and moves it to the left one on the grid
			arr[posY][posX] = arr[posY][posX + shift];
			//takes (x) and changes it to 0 i hope this is so tragic
			arr[posY][posX + shift] = temp;

		}
	}

	//changes coordinates of the object 
	for (int r = 0; r < positionLength_; r++) {
		coordinates_[r][1] = (coordinates_[r][1]) + shift;
	}
	//prints out new coordinates 
	for (int row = 0; row < positionLength_; row++) {
		for (int col = 0; col < 2; col++) {
			cout << coordinates_[row][col];
		}
		cout << endl;
	}

	cout << endl << "finished this trama" << endl;
}

//checks to see if you can move left
bool Shapes::updateLeftHorizontalPosition(int arr[20][10], char letterEntered) {
	bool ableToMove = true;
	int posX, posY;
	//if its g we are moving to the left 
	for (int i = 0; i < positionLength_; i++) {
		posY = coordinates_[i][0];
		posX = coordinates_[i][1];
		if (posX != 0) {
			if (arr[posY][posX - 1] == 0 || arr[posY][posX - 1] == 2) {
				ableToMove = true;
				cout << "inner if " << endl;
			}
			else {
				cout << "first else";
				return false;
			}

		}
		else {
			cout << "second else";
			return false;
		}
	}
	return ableToMove;
}
bool Shapes::updateRightHorizontalPosition(int arr[20][10], char letterEntered) {
	bool ableToMove = true;
	int posX, posY;
	//if its g we are moving to the left 
	for (int i = 0; i < positionLength_; i++) {
		posY = coordinates_[i][0];
		posX = coordinates_[i][1];
		if (posX != 9) {
			if (arr[posY][posX + 1] == 0 || arr[posY][posX + 1] == 2) {
				ableToMove = true;
				cout << "inner if " << endl;
			}
			else {
				cout << "first else";
				return false;
			}

		}
		else {
			cout << "second else";
			return false;
		}
	}
	return ableToMove;
}



	
	//check grid to see if x value -1 of coordinates = 0 
	//if it is move x coordinates to left one which means - 1
	//move grid coordinates r - 1 to equal 2 and change previous positions to 0

	//create bool thats true as long as everything to left is always 0

//Each shape 
void Shapes::colorOne(int arr[20][10]) {
	arr[0][4] = 2;
	arr[0][5] = 2;
	arr[1][4] = 2;
	arr[1][5] = 2;

	this->coordinates_ [0][0] = 0;
	this->coordinates_ [0][1] = 4;

	this->coordinates_[1][0] = 0;
	this->coordinates_[1][1] = 5;

	this->coordinates_[2][0] = 1;
	this->coordinates_[2][1] = 4;

	this->coordinates_[3][0] = 1;
	this->coordinates_[3][1] = 5;
	/*
	0, 4
	0, 5
	1, 4
	1, 5
	*/

	//bar(amount from the left, start point from top, second amount from left, where the bottom is 
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	bar(160, 0, 240, 80);

}

void Shapes::colorTwo(int arr[20][10]) {
	cout << "calling color 2";
	arr[0][5] = 2;
	arr[1][5] = 2;
	arr[2][5] = 2;
	arr[3][5] = 2;

	this->coordinates_[0][0] = 0;
	this->coordinates_[0][1] = 5;

	this->coordinates_[1][0] = 1;
	this->coordinates_[1][1] = 5;

	this->coordinates_[2][0] = 2;
	this->coordinates_[2][1] = 5;

	this->coordinates_[3][0] = 3;
	this->coordinates_[3][1] = 5;
	/*
	0, 5
	1, 5
	2, 5
	3, 5
	*/
	//bar(amount from the left, start point from top, second amount from left, where the bottom is 
	setcolor(BLUE);
	setfillstyle(SOLID_FILL, BLUE);
	bar(160, 0, 240, 80);
}

void Shapes::colorThree(int arr[20][10]) {
	arr[0][4] = 2;
	arr[1][4] = 2;
	arr[2][4] = 2;
	arr[2][5] = 2;

	this->coordinates_[0][0] = 0;
	this->coordinates_[0][1] = 4;

	this->coordinates_[1][0] = 1;
	this->coordinates_[1][1] = 4;

	this->coordinates_[2][0] = 2;
	this->coordinates_[2][1] = 4;

	this->coordinates_[3][0] = 2;
	this->coordinates_[3][1] = 5;
	/*
	0, 4
	1, 4
	2, 4
	2, 5
	*/
	//bar(amount from the left, start point from top, second amount from left, where the bottom is 
	setcolor(BLUE);
	setfillstyle(SOLID_FILL, BLUE);
	bar(160, 0, 240, 80);
}

void Shapes::colorFour(int arr[20][10]) {
	arr[0][5] = 2;
	arr[1][5] = 2;
	arr[2][5] = 2;
	arr[2][4] = 2;

	this->coordinates_[0][0] = 0;
	this->coordinates_[0][1] = 5;

	this->coordinates_[1][0] = 1;
	this->coordinates_[1][1] = 5;

	this->coordinates_[2][0] = 2;
	this->coordinates_[2][1] = 5;

	this->coordinates_[3][0] = 2;
	this->coordinates_[3][1] = 4;
	/*
	0, 5
	1, 5
	2, 5
	2, 4
	*/
	//bar(amount from the left, start point from top, second amount from left, where the bottom is 
	setcolor(BLUE);
	setfillstyle(SOLID_FILL, BLUE);
	bar(160, 0, 240, 80);
}

void Shapes::colorFive(int arr[20][10]) {
	arr[0][5] = 2;
	arr[1][4] = 2;
	arr[1][5] = 2;
	arr[2][4] = 2;

	this->coordinates_[0][0] = 0;
	this->coordinates_[0][1] = 5;

	this->coordinates_[1][0] = 1;
	this->coordinates_[1][1] = 4;

	this->coordinates_[2][0] = 1;
	this->coordinates_[2][1] = 5;

	this->coordinates_[3][0] = 2;
	this->coordinates_[3][1] = 4;
	/*
	0, 5
	1, 4
	1, 5
	2, 4
	*/
	//bar(amount from the left, start point from top, second amount from left, where the bottom is 
	setcolor(BLUE);
	setfillstyle(SOLID_FILL, BLUE);
	bar(160, 0, 240, 80);
}
void Shapes::colorSix(int arr[20][10]) {
	arr[0][4] = 2;
	arr[1][4] = 2;
	arr[1][5] = 2;
	arr[2][5] = 2;

	this->coordinates_[0][0] = 0;
	this->coordinates_[0][1] = 4;

	this->coordinates_[1][0] = 1;
	this->coordinates_[1][1] = 4;

	this->coordinates_[2][0] = 1;
	this->coordinates_[2][1] = 5;

	this->coordinates_[3][0] = 2;
	this->coordinates_[3][1] = 5;
	/*
	0, 4
	1, 4
	1, 5
	2, 5
	*/
	//bar(amount from the left, start point from top, second amount from left, where the bottom is 
	setcolor(BLUE);
	setfillstyle(SOLID_FILL, BLUE);
	bar(160, 0, 240, 80);
}


