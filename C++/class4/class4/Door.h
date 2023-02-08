#pragma once
#define MAXLEN 20
#include <iostream>
using namespace std;

class Door
{
private:

	float height;
	int price;
	char color[MAXLEN];

public:
	//Methods
	void unlock();
	void lock();
	void addHeight(float addition);
	void print();
	
	//Constructor
	Door(int newPrice, float newHeight, const char newColor[MAXLEN]);
	Door();

	//Getters inline formate

	int getPrice() { return price; }
	float getHeight() { return height; }
	char* getColor() { return color; }

	//Setters

	void setPrice(int newPrice);

};

