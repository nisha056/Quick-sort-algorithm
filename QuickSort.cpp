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
	float w=0.5*x;
	//int w=(int)r;
	int l=greatest(height);
	for (int i = 0; i < 10; i++) {
            float z=(500/(float)l)*height[i];
    int t=(int)z;
		recn[i].setFillColor(sf::Color::Yellow);
		recn[i].setOutlineColor(sf::Color::Black);
		recn[i].setOutlineThickness(-3);
		recn[i].setSize(sf::Vector2f(40, -(t)));
		recn[i].setPosition(sf::Vector2f(x,720));
		x=x+w;
		//x=x+90;
		std::cout << height[i] << ",";
	}
	std::cout << "\n";

}

int QuickSort::partition(int height[],int low,int high)
{
    std::cout<<"Finding the pivot ";
    int current=low,pivot=height[high];
    for(int index=low;index<high;index++)
    {
        if(height[index]<= pivot)
        {
            int temp=height[current];
            height[current]=height[index];
            height[index]=temp;
            current++;
        }
    }
    int tem=height[current];
    height[current]=height[high];
    height[high]=tem;
    return current;
    }
void QuickSort::quicksort(int height[],int low,int high)
{
    std::cout<<"Sorting the data";
    if(low<high)
    {
        int notation=partition(height,low,high);
        quicksort(height,low,notation-1);
        sf::sleep(sf::milliseconds(500));
        setData(height);
        draw(window);
        window.display();
        quicksort(height,notation+1,high);
        sf::sleep(sf::milliseconds(500));
        setData(height);
        draw(window);
        window.display();
    sf::sleep(sf::milliseconds(300));
    }

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

int QuickSort::greatest( int height[])
{
    int maxx=height[0];
    for(int i=0;i<10;i++)
    {
        if (height[i]>maxx)
            maxx=height[i];
    }
    return maxx;

}
