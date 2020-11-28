#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
class QuickSort
{
public:
    QuickSort();
    void setData(int height[]);
    bool sort();
    void draw(sf::RenderWindow&);// For drawing in screen
private:
    sf::RectangleShape recn[10];
    sf::Font font;
    sf::RectangleShape outlineBox1;
    sf::RectangleShape outlineBox2;
    void equateRectangle(sf::RectangleShape*,sf::RectangleShape*);
};
