#include "QuickSort.h"

QuickSort::QuickSort()
{
	outlineBox1.setSize(sf::Vector2f(900, 700));
	outlineBox1.setPosition(sf::Vector2f(50, 50));
	outlineBox1.setOutlineColor(sf::Color::Black);
	outlineBox1.setOutlineThickness(10);
	outlineBox1.setFillColor(sf::Color::Transparent);
	outlineBox2.setSize(sf::Vector2f(900, 100));
	outlineBox2.setPosition(sf::Vector2f(50, 50));
	outlineBox2.setOutlineColor(sf::Color::Black);
	outlineBox2.setOutlineThickness(10);
	outlineBox2.setFillColor(sf::Color::Transparent);

}

void QuickSort::setData(int height[])
{

	//Data Preprocessing
	std::cout << " Setting Data ... ";
	for (int i = 0; i < 10; i++) {
		recn[i].setFillColor(sf::Color::Yellow);
		recn[i].setSize(sf::Vector2f(30, -(height[i])));
		recn[i].setPosition(sf::Vector2f(i * 80+100, 690));
		std::cout << recn[i].getSize().y << ",";
	}
	std::cout << "\n";

}

bool QuickSort::sort()
{
	std::cout << "Sorting Data ";
	sf::Vector2f temp;
	for (int i = 0; i < 9; i++) {
		for (int j = 0 ; j < 9; j++) {
			if (recn[j].getSize().y > recn[j + 1].getSize().y) {
				temp = recn[j].getSize();
				recn[j].setSize(recn[j + 1].getSize());
				recn[j + 1].setSize(temp);
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	}
	return true;
}

void QuickSort::draw(sf::RenderWindow& window)
{
	window.draw(outlineBox1);
	window.draw(outlineBox2);
	for (int i = 0; i < 10; i++) {
		window.draw(recn[i]);
	}
}
