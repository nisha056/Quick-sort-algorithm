#pragma once
#include<SFML/Graphics.hpp>
#include "QuickSort.h"
#include "Button.h"
#include<thread>

class Visualizer
{
private:
	sf::RenderWindow window;
	bool isSorting;
	Button setDataButton, sortButton;
	sf::Font font;
	QuickSort Q;
	int data[10] ={400,200,500,100,350,150,450,550,250,300};
public:
	Visualizer();
	void run();
	void handleUserInput();
	void update();
	void render();
	void sort();
};

