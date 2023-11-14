#pragma once
#ifndef SHAPES_H
#define SHAPES_H
#include <map>
#include <iostream> 
using namespace std;

class Shapes
{
	
public:
	Shapes();
	Shapes(int color, int arr[20][10]);


	int getColor();
	bool gameOver(int arr[20][10]);
	bool canClear(int arr[20][10], int row);
	void clearLine(int arr[20][10], int row);
	bool updateLeftHorizontalPosition(int arr[20][10], char letterEntered);
	bool updateRightHorizontalPosition(int arr[20][10], char letterEntered);
	void moveHorizontal(int arr[20][10], char letterEntered);
	bool set(int arr[20][10]);
	void fall(int arr[20][10]);
	void colorOne(int arr[20][10]);
	void colorTwo(int arr[20][10]);
	void colorThree(int arr[20][10]);
	void colorFour(int arr[20][10]);
	void colorFive(int arr[20][10]);
	void colorSix(int arr[20][10]);

private:
	//integer that corresponds to color
	int color_;
	//every shape occupies 4 squares
	int positionLength_ = 4;
	//holds the coordinates that the current shape occupies
	int coordinates_[4][4];

};


#endif SHAPES_H 
