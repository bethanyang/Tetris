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

	void updatePosition(int arr[20][10]);
	int getColor();
	void colorOne(int arr[20][10]);
	int colorTwo(int arr[20][10]);

private:
	//integer that corresponds to color
	int color_;
	//how many squares the shape occupies
	int positionLength_;
	//each map will have a specific shape 
	//it should keep changing until the shape is set
	int** coordinates_ = nullptr;
	/*int color;

	Shapes(int x) {
		color = x;
		//generate a random shape and then give it a color
	}
	void setInitialPosition(int& a[][]) {
		cout << "taco";
	}*/

};


#endif SHAPES_H 