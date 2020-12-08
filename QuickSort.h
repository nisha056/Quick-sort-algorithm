#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
class QuickSort
{
public:
    QuickSort();
    void setData(int data[]);
    int partition (int[],int,int);
    bool quicksort (int [],int ,int );
    int greatest(int arr[]);
    bool sort(int data[],int ,int);
    void lastpivot(int data[],int,int);
    void draw(sf::RenderWindow&);// For drawing in screen
private:
    sf::RectangleShape recn[10];
    sf::Font font;
    sf::RectangleShape outlineBox1;
    sf::RectangleShape outlineBox2;
    void equateRectangle(sf::RectangleShape*,sf::RectangleShape*);
    std::string comma= "";
   // std::string separate = "";
    //std::string part = "";
};
