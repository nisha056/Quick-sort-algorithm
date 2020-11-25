#include "QuickSort.h"
  QuickSort::QuickSort()
{
	outlineBox.setSize(sf::Vector2f(700, 450));
	outlineBox.setPosition(sf::Vector2f(50, 100));
	outlineBox.setOutlineColor(sf::Color::Black);
	outlineBox.setOutlineThickness(5);
	outlineBox.setFillColor(sf::Color::Transparent);
	infoText.setCharacterSize(25);
	text1.setCharacterSize(25);
	if (!font.loadFromFile("DejaVuSans.ttf"))
    {
        std::cout<<"Error while loading text!";
    }
	infoText.setFont(font);
	infoText.setFillColor(sf::Color::Black);
	infoText.setPosition(sf::Vector2f(25, 35));
	infoText.setString(" Click on the button ... ");
	text1.setFont(font);
	text1.setFillColor(sf::Color::Blue);
	text1.setPosition(sf::Vector2f(675,35));
	text1.setString(" Pivot");
}

void QuickSort::setData(int height[])
{

	//Data Preprocessing
	//std::cout << " Setting Height ... ";
	int width=30;
	int totWid=30+width;
	float space=0.3*totWid;
	int l=greatest(height);
	for (int i = 0; i < 10; i++)
    {
        float z=(350/(float)l)*height[i];
        int t=(int)z;
		recn[i].setFillColor(sf::Color::Yellow);
		recn[i].setOutlineColor(sf::Color::Black);
		recn[i].setOutlineThickness(-3);
		recn[i].setSize(sf::Vector2f(40, -(t)));
		recn[i].setPosition(sf::Vector2f(totWid,525));
		totWid=totWid+space+width;
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
    //std::cout<<"Sorting the data";
    if(low<high)
    {
        int notation=partition(height,low,high);
        quicksort(height,low,notation-1);
       // sf::sleep(sf::milliseconds(500));
        setData(height);
        draw(window);
        window.display();
        quicksort(height,notation+1,high);
        //sf::sleep(sf::milliseconds(500));
        setData(height);
        draw(window);
        window.display();
   // sf::sleep(sf::milliseconds(300));
    }

}


void QuickSort::draw(sf::RenderWindow& window)
{
	window.draw(outlineBox);
	window.draw(infoText);
	window.draw(text1);
	//window.draw(text2);
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
