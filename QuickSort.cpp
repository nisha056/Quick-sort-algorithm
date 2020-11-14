#include "QuickSort.h"

QuickSort::QuickSort()
{
	outlineBox.setSize(sf::Vector2f(900, 800));
	outlineBox.setPosition(sf::Vector2f(50, 50));
	outlineBox.setOutlineColor(sf::Color::Black);
	outlineBox.setOutlineThickness(10);
	outlineBox.setFillColor(sf::Color::Transparent);
	infoText.setCharacterSize(30);
	text1.setCharacterSize(20);
	text2.setCharacterSize(20);
	if (!font.loadFromFile("DejaVuSans.ttf"))
    {
        std::cout<<"kkk";
    }
	infoText.setFont(font);
	infoText.setFillColor(sf::Color::Black);
	infoText.setPosition(sf::Vector2f(50, 50));
	infoText.setString(" Press 'S' to load data ... ");
	text1.setFont(font);
	text1.setFillColor(sf::Color::Blue);
	text1.setPosition(sf::Vector2f(800,50));
	text1.setString(" Pivot");
	text2.setFont(font);
	text2.setFillColor(sf::Color::Green);
	text2.setPosition(sf::Vector2f(800,100));
	text2.setString(" Sorted");


}

void QuickSort::setData(int height[])
{

	//Data Preprocessing
	std::cout << " Setting Height ... ";
	int x=90;
	for (int i = 0; i < 10; i++) {
		recn[i].setFillColor(sf::Color::Yellow);
		recn[i].setOutlineColor(sf::Color::Black);
		recn[i].setOutlineThickness(-3);
		recn[i].setSize(sf::Vector2f(40, -(height[i])));
		recn[i].setPosition(sf::Vector2f(x,720));
		x=x+90;
		std::cout <<-1*( recn[i].getSize().y) << ",";
	}
	std::cout << "\n";

}

    int QuickSort::partition(int height[],int low,int high)
{
    int current=low,pivot=height[high];
    for(int index=low;index<high;index++)
    {
        if(height[index]<= pivot)
        {
            int temp=height[current];
            height[current]=height[index];
            height[index]=temp;
            sf::sleep(sf::milliseconds(100));
            current++;
        }
    }
    int tem=height[current];
    height[current]=height[high];
    height[high]=tem;
    sf::sleep(sf::milliseconds(100));
    return current;
    }
void QuickSort::quicksort(int height[],int low,int high)
{
    std::cout<<"Sorting the data";
    if(low<high)
    {
        sf::sleep(sf::milliseconds(100));
        int notation=partition(height,low,high);
        //sf::sleep(sf::milliseconds(100));

        quicksort(height,low,notation-1);
        //sf::sleep(sf::milliseconds(100));
        quicksort(height,notation+1,high);
    }

}
void QuickSort::sort(int height[])
{
	std::cout << "Sorting Data ";
    quicksort(height,0,9);
}

void QuickSort::draw(sf::RenderWindow& window)
{
	window.draw(outlineBox);
	window.draw(infoText);
	window.draw(text1);
	window.draw(text2);
	for (int i = 0; i < 10; i++) {
		window.draw(recn[i]);
	}

}


