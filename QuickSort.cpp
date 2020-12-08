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
	std::cout << " \n Setting Data ... ";
	int width = 30;
	int totWidth = 30 + width;
	double space = 0.3 * totWidth;
	int l = greatest(height);

	for (int i = 0; i < 10; i++)
        {
		float z = (350 / (float)l) * height[i];
		int t = z;
		recn[i].setFillColor(sf::Color::Yellow);
		recn[i].setOutlineColor(sf::Color::Black);
		recn[i].setOutlineThickness(-3);
		recn[i].setSize(sf::Vector2f(40, -(t)));
		recn[i].setPosition(sf::Vector2f(i * 80 + 100, 690));
		totWidth = totWidth + space + width;
		std::cout << comma <<height[i] ;
		comma=",";


}
}

bool QuickSort::sort(int data[],int low,int high)
{
	std::cout << "\n Sorting Data ";
	lastpivot(data,low,high);
	quicksort(data, low, high);
	std::cout<< " \n Finally the sorted heights are : ";
	int width = 30;
    int totWidth = 30 + width;
    double space = 0.3 * totWidth;
    int l = greatest(data);
	for(int i=0;i<10;i++)
    {
	float z = (350 / (float)l) * data[i];
				int t = z;
				recn[i].setFillColor(sf::Color::Yellow);
				recn[i].setOutlineColor(sf::Color::Black);
				recn[i].setOutlineThickness(-3);
				recn[i].setSize(sf::Vector2f(40, -(t)));
				recn[i].setPosition(sf::Vector2f(i * 80 + 100, 690));
				totWidth = totWidth + space + width;
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				std::cout <<data[i]<<comma;
				comma=",";
    }
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	return true;

}
bool QuickSort::quicksort(int height[], int low, int high)
{
    //lastpivot(height,low,high);

	if (low <high)
	{
		int width = 30;
		int totWidth = 30 + width;
		double space = 0.3 * totWidth;
		int l = greatest(height);
		int notation = partition(height, low, high);
		//std::cout << height[notation]; //<<"\tat\t"<<high<<std::endl;
		for (int i = 0; i < 10; i++) {
                //std::cout<< " \n Arranging after the pivot ";
			if (i == notation)
			{
				float z = (350 / (float)l) * height[i];
				int t = z;
				recn[i].setFillColor(sf::Color::Green);
				recn[i].setOutlineColor(sf::Color::Black);
				recn[i].setOutlineThickness(-3);
				recn[i].setSize(sf::Vector2f(40, -(t)));
				recn[i].setPosition(sf::Vector2f(i * 80 + 100, 690));
				totWidth = totWidth + space + width;
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				//std::cout << recn[i].getSize().y << ",";
				std::cout <<height[i]<<comma ;
				comma=",";
			}
			else
			{
			    //std::cout<<" \n Arranging the heights ";
				float z = (350 / (float)l) * height[i];
				int t = z;
				recn[i].setFillColor(sf::Color::Yellow);
				recn[i].setOutlineColor(sf::Color::Black);
				recn[i].setOutlineThickness(-3);
				recn[i].setSize(sf::Vector2f(40, -(t)));
				recn[i].setPosition(sf::Vector2f(i * 80 + 100, 690));
				totWidth = totWidth + space + width;
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				//std::cout << recn[i].getSize().y << ",";
				std::cout <<height[i]<<comma;
				comma=",";
			}
		}
		quicksort(height, low, notation - 1);

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		quicksort(height, notation   , high);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

	}
	return true;
}

int QuickSort::partition(int height[], int low, int high)
{
	std::cout << " \n Finding the pivot and arranging the heights: ";
	// we have taken last element as pivot
	int current = low, pivot = height[high];

	for (int index = low;index < high;index++)
	{
		if (height[index] <= pivot)
		{
		    // swap current and index
			int temp = height[current];
			height[current] = height[index];
			height[index] = temp;


			current++;
		}
	}
	int tem = height[current];
	height[current] = height[high];
	height[high] = tem;
	// changed
	return current;
}


int QuickSort::greatest(int height[])
{
	int maxx = height[0];
	for (int i = 0;i < 10;i++)
	{
		if (height[i] > maxx)
			maxx = height[i];
	}
	return maxx;

}

void QuickSort::draw(sf::RenderWindow& window)
{
	window.draw(outlineBox1);
	window.draw(outlineBox2);
	for (int i = 0; i < 10; i++) {
		window.draw(recn[i]);
	}
}
// to make the last element as pivot
void QuickSort::lastpivot(int data[],int low ,int high)
{
    int width = 30;
		int totWidth = 30 + width;
		double space = 0.3 * totWidth;
		int l = greatest(data);
		//int notation = partition(data, low, high);
		for (int i = 0; i < 10; i++) {
			if (i == high)
			{
				float z = (350 / (float)l) * data[i];
				int t = z;
				recn[i].setFillColor(sf::Color::Green);
				recn[i].setOutlineColor(sf::Color::Black);
				recn[i].setOutlineThickness(-3);
				recn[i].setSize(sf::Vector2f(40, -(t)));
				recn[i].setPosition(sf::Vector2f(i * 80 + 100, 690));
				totWidth = totWidth + space + width;
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
			else
			{
				float z = (350 / (float)l) * data[i];
				int t = z;
				recn[i].setFillColor(sf::Color::Yellow);
				recn[i].setOutlineColor(sf::Color::Black);
				recn[i].setOutlineThickness(-3);
				recn[i].setSize(sf::Vector2f(40, -(t)));
				recn[i].setPosition(sf::Vector2f(i * 80 + 100, 690));
				totWidth = totWidth + space + width;
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
}
}
