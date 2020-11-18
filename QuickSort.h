#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class QuickSort
{
private:
    sf::RenderWindow window;
    sf::RectangleShape recn[10];
    sf::RectangleShape outlineBox;
    sf::RectangleShape height[];
    sf::Font font;
    sf::Text infoText;
    sf::Text text1;
    sf::Text text2;

public:
    QuickSort();
    void setData(int height[]);
    int partition(int[],int,int);
    void quicksort(int[],int,int);
    void draw(sf::RenderWindow&);// For drawing in screen
};
