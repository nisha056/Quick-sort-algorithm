#include <SFML/Graphics.hpp>
#include<iostream>
void drawrectangle();
int n,i,height[15];
int main()
{
    std::cout<<"   **********WELCOME TO OUR PROJECT *********      "<<std::endl;
    std::cout<<" ----------------------------------------------------"<<std::endl;
    std::cout<<"    Enter the number of rectangles you want to be sorted     ";
    std::cin>>n;
    std::cout<<"Enter the heights of rectangle "<<std::endl;
    for(i=0;i<n;i++)
    {
    std::cout<< "Height ";
    std::cin>> height[i];
    }
     drawrectangle();

    return 0;
}
void drawrectangle()
{
    int x=0;
    sf::RenderWindow window(sf::VideoMode(900, 600), " Rectangles ");
    sf::RectangleShape recn[n];
    for(i=0;i<n;i++)
    {
    recn[i].setFillColor(sf::Color::Black);
    recn[i].setSize(sf::Vector2f(50,-(height[i])));
    recn[i].setPosition(x,600);
    x= x+60;
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    window.clear(sf::Color::White);
    for(i=0;i<n;i++)
    {
    window.draw(recn[i]);
    }
    window.display();
    }

}
