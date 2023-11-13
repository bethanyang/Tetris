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
}

void Shapes::updatePosition(int arr[20][10]) {
	
}
int Shapes::getColor() {
	return this->color_;
}

//Each shape 
void Shapes::colorOne(int arr[20][10]) {
	//counter for how many squares it takes up 
	this->positionLength_ = 4;
	
	//creating memor for size of this array
	coordinates_ = new int* [4];
	for (int i = 0; i < 4; ++i) {
		coordinates_[i] = new int[4];
	}
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
	arr[0][4] = 2;
	arr[0][5] = 2;
	arr[1][4] = 2;
	arr[1][5] = 2;
	cout << "done";
	//bar(amount from the left, start point from top, second amount from left, where the bottom is 
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	bar(160, 0, 240, 80);

}

void Shapes::colorTwo(int arr[20][10]) {
	arr[0][5] = 2;
	arr[1][5] = 2;
	arr[2][5] = 2;
	arr[3][5] = 2;
	//bar(amount from the left, start point from top, second amount from left, where the bottom is 
	setcolor(BLUE);
	setfillstyle(SOLID_FILL, BLUE);
	bar(160, 0, 240, 80);

	//counter for how many squares it takes up 
	this->positionLength_ = 4;

	//creating memor for size of this array
	coordinates_ = new int* [4];
	for (int i = 0; i < 4; ++i) {
		coordinates_[i] = new int[4];
	}
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
