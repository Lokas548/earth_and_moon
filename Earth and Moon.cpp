#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES 
#include <cmath>
#include <iostream>
#include <chrono>
#include <thread>
using namespace sf;
using namespace std;

int eX = 700;
int eY = 500;
int x = 1200;
int y = 500;
int radius = 30;
int xo = 700;
int yo = 500;
int r = 200;
int i = 0;

int main()

{
	int i = 0;
	RenderWindow window(VideoMode(1600, 1000), "Earth and Moon");

	//текстура фона
	Texture background;
	background.loadFromFile("C:\\Users\\Acer\\Desktop\\Earth and Moon\\flappy birds\\sprites\\space.png");
	Sprite ground(background);

	//текстура Земли
	CircleShape earth(100.f);
	Texture Earth;
	Earth.loadFromFile("C:\\Users\\Acer\\Desktop\\Earth and Moon\\flappy birds\\sprites\\earth.png");
	earth.setPosition(eX, eY);
	earth.setTexture(&Earth);

	CircleShape moon;
	Texture Moon;
	Moon.loadFromFile("C:\\Users\\Acer\\Desktop\\Earth and Moon\\flappy birds\\sprites\\moon.png");
	moon.setRadius(radius);
	moon.setTexture(&Moon);
	moon.setPosition(x, y);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		i++;
		x = (xo + 100) + round(r * cos(i * M_PI / 180) - radius / 2);
		y = (yo + 100) + round(r * sin(i * M_PI / 180) - radius / 2);
		moon.setPosition(x, y);
		

		window.draw(ground);
		window.draw(earth);
		window.draw(moon);
		window.display();

		std::this_thread::sleep_for(10ms);
	}
	
}