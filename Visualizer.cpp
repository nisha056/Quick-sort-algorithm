#include "Visualizer.h"

Visualizer::Visualizer():window(sf::VideoMode(1000,900),"Visualizer")
{

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
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::EventType::KeyPressed)
            {
        if (event.key.code == sf::Keyboard::S)
        {
            Q.setData(height);
           

       }
       if (event.key.code == sf::Keyboard::Enter)
        {
            Q.quicksort(height,0,9);

       }
    }
    }
}

void Visualizer::render()
{
    window.clear(sf::Color::White);

    Q.draw(window);

    window.display();
}

