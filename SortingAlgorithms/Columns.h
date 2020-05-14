#pragma once
#include <vector>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <random>

using namespace std;

class Columns{
public:
	int number;

	Columns(int size) : number(size) {}

	static sf::RectangleShape drawColumn(int height, int pos) {
		float h=(float)height, p=(float)pos;
		sf::RectangleShape rectangle(sf::Vector2f(5, h));
		rectangle.setPosition(p*5, 960-h);
		return rectangle;
	}
};