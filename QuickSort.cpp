#include "QuickSort.h"

QuickSort::QuickSort()
{
	outlineBox.setSize(sf::Vector2f(900, 800));
	outlineBox.setPosition(sf::Vector2f(50, 50));
	outlineBox.setOutlineColor(sf::Color::Black);
	outlineBox.setOutlineThickness(10);
	outlineBox.setFillColor(sf::Color::Transparent);
	infoText.setCharacterSize(30);
	if (!font.loadFromFile("DejaVuSans.ttf"))
    {
        std::cout<<"kkk";
    }
	infoText.setFont(font);
	infoText.setFillColor(sf::Color::Black);
	infoText.setPosition(sf::Vector2f(50, 50));
	infoText.setString(" Press 'S' to load data ... ");

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
		std::cout << recn[i].getSize().y << ",";
	}
	std::cout << "\n";

}
// last element is taken as pivot

int QuickSort::partition(int height[],int low,int high)
{
    int i=low,pivot=height[high];
    for(int j=low;j<high;j++)
    {
        if(height[j]<= pivot)
        {
            int temp=height[i];
            height[i]=height[j];
            height[j]=temp;
           // height.draw(2,i,j);
            i++;
        }
    }
    int tem=height[i];
    height[i]=height[high];
    height[high]=tem;
    return i;

}
void QuickSort::quicksort(int height[],int low,int high)
{
    //std::cout<<"Sorting the data";
    if(low<high)
    {
        int notation=partition(height,low,high);
        quicksort(height,low,notation-1);
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
	for (int i = 0; i < 10; i++) {
		window.draw(recn[i]);
	}
}
