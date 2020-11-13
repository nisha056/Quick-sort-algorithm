#include "Visualizer.h"

Visualizer::Visualizer():window(sf::VideoMode(1000,900),"Visualizer")
{

}

void Visualizer::run()
{
    std::cout << "Running \n";
	while (window.isOpen()) {
		handleUserInput();
		update();
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
      if (event.key.code == sf::Keyboard::Enter)
        {
             Q.sort(height);
             Q.setData(height);
       }
        if (event.key.code == sf::Keyboard::S)
        {
            Q.setData(height);

       }
    }
    }
}

void Visualizer::update()
{
}

void Visualizer::render()
{
    window.clear(sf::Color::White);

    Q.draw(window);

    window.display();
}
