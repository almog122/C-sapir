#pragma once
#include <iostream>
#include <cassert>
#include "List.h"
#define DEF_COLOR "Black"
#define DEF_NUM_HOLES 3
#define DEF_DIAMETER 2.2f
#define MIN_NUM_HOLES 2
#define MAX_NUM_HOLES 4
#define MIN_DIAMETER 0.5f
#define MAX_DIAMETER 10
using namespace std;

class Button
{
private:
	char* color;
	int num_holes;
	float diameter;

public:

	//Constructor and dystoryer
	Button(const char* color = DEF_COLOR, int num_holes = 3, float diameter = 2.2);
	~Button();

	//Copy constructor

	Button(const Button &other);

	//Setters

	void set_color(const char* color);
	void set_num_holes(int num_holes);
	void set_diameter(float diameter);

	//Getters

	char* get_color() const { return color;}
	int get_num_holes() const { return num_holes; }
	float get_diameter() const { return diameter; }

	//Other functions

	void print() const;
	float  is_bigger(const Button& other);
	bool is_equal(const Button& other);
};

