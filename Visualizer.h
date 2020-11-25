#pragma once
#include<SFML/Graphics.hpp>
#include "QuickSort.h"
#include "Button.h"

class Visualizer
{
private:
	sf::RenderWindow window;
	Button setDataButton, sortButton;
	sf::Font font;
	QuickSort Q;
	int height[10] = {300,200,500,400,50,60,50,450,270,390};
public:
	Visualizer();
	void run();
	void handleUserInput();
	void render();
};
