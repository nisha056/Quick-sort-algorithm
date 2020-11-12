#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class QuickSort
{
public:
    QuickSort();
    void setData(int height[]);
    void sort(int[]);
    void quicksort(int[],int,int);
    int partition(int[],int,int);
    void draw(sf::RenderWindow&); // For drawing in screen
private:
    sf::RectangleShape recn[10];
    sf::RectangleShape outlineBox;
    sf::RectangleShape height[];
    sf::Font font;
    sf::Text infoText;
};
