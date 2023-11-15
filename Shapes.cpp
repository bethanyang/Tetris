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
void Shapes::clearLine(int arr[20][10], int row) {
	for (int c = 0; c < 10; c++) {
		arr[row][c] = 0;
	}

	//0,0
	//1,0


	for (int r = row; r >= 1; r--) {
		for (int c = 0; c < 10; c++) {
			arr[r][c] = arr[r - 1][c];

		}
	}

}
bool Shapes::canClear(int arr[20][10], int row) {
	bool clear = false;
	int posX, posY;
	for (int c = 0; c < 10; c++) {
		if (arr[row][c] == 1) {
			clear = true;
		}
		else {
			return false;
		}
	}
	return clear;
}
bool Shapes::gameOver(int arr[20][10]) {
	int posX, posY;
	bool done = false;
	for (int i = 0; i < 4; i++) {
		posX = coordinates_[i][1];
		posY = coordinates_[i][0];
		if (posY - 1 == -1) {
			done = true;
		}
	}
	return done;
}
int Shapes::getColor() {
	return this->color_;
}
//set shape into 1s 
bool Shapes::set(int arr[20][10], int &s) {
	bool isSet = false;
	int posX, posY;
	for (int i = 0; i < 4; i++) {
		posX = coordinates_[i][1];
		posY = coordinates_[i][0];
		if (posY + 1 == 20 || arr[posY + 1][posX] == 1) {
			isSet = true;
		}
	}
	if (isSet) {
		for (int i = 0; i < 4; i++) {
			posX = coordinates_[i][1];
			posY = coordinates_[i][0];
			arr[posY][posX] = 1;
		}
		s += 10;
	}
	//look at coordinates 
	//set those coordinates in the grid to 1
	//if its on last row or there 1 under 
	return isSet;
}

//makes the shape fall by one box 
void Shapes::fall(int arr[20][10]) {
	// get y value in the coordinates 
	//check to see if that y value under grid is 0 or itself if true everything moves down a box
	//update coordinates to reflect that 
	int temp; //gonna start crying really quick
	bool ableToMove = true;
	int posX, posY;
	for (int i = 0; i < 4; i++) {
		posX = coordinates_[i][1];
		posY = coordinates_[i][0];
		if (posY + 1 < 20) {
			if (arr[posY + 1][posX] == 0 || arr[posY + 1][posX] == 2) {
				ableToMove = true;
			}
			else {
				return;
			};
		}
		else {
			return;
		}
	}
	for (int i = 3; i >= 0; i--) {
		posX = coordinates_[i][1];
		posY = coordinates_[i][0];
		arr[posY][posX] = 0;
		arr[posY + 1][posX] = 2;
	}
	//changes coordinates of the object 
	for (int r = 0; r < positionLength_; r++) {
		coordinates_[r][0] = coordinates_[r][0] + 1;
	}
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
			}
			else {
				return false;
			}

		}
		else {
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
			}
			else {
				return false;
			}

		}
		else {
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

	this->coordinates_[0][0] = 0;
	this->coordinates_[0][1] = 4;

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

	

}

void Shapes::colorTwo(int arr[20][10]) {
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
	this->coordinates_[2][1] = 4;

	this->coordinates_[3][0] = 2;
	this->coordinates_[3][1] = 5;
	/*
	0, 5
	1, 5
	2, 5
	2, 4
	*/

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
}
