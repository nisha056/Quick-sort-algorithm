#include "Visualizer.h"


Visualizer::Visualizer():window(sf::VideoMode(800,600),"Visualizer"),

setDataButton("Set",sf::Vector2f(100,50),20,sf::Color::Green,sf::Color::Black),
sortButton("Sort",sf::Vector2f(100,50),20,sf::Color::Green,sf::Color::Black)
{
    if(!font.loadFromFile("DejaVuSans.ttf"))
    {
        //error
    }
    setDataButton.setPosition(sf::Vector2f(350,25));
    setDataButton.setFont(font);
    sortButton.setPosition(sf::Vector2f(475,25));
    sortButton.setFont(font);
    }



void Visualizer::run()
{
    std::cout << "Running \n";
	while (window.isOpen()) {
		handleUserInput();
		render();
	}
}

void Visualizer::handleUserInput()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed){
            window.close();
        }
        else if (event.type == sf::Event::EventType::MouseMoved)
        {
            if(setDataButton.isMouseOver(window))
            {
                setDataButton.setBackColor(sf::Color::Red);

            }
           else
            {
                setDataButton.setBackColor(sf::Color::Green);
            }

            if(sortButton.isMouseOver(window))
            {
                sortButton.setBackColor(sf::Color::Red);
            }
            else
            {
                sortButton.setBackColor(sf::Color::Green);
            }
        }
        else if (event.type == sf::Event::EventType::MouseButtonPressed)
        {
              if (setDataButton.isMouseOver(window))
              {
                  Q.setData(height);
              }
              else if (sortButton.isMouseOver(window))
              {
                  Q.quicksort(height,0,9);
              }
          }
     }
}
void Visualizer::render()
{
    window.clear(sf::Color::White);
    setDataButton.drawTo(window);
    sortButton.drawTo(window);
    Q.draw(window);

    window.display();
}
