#pragma once
#include<SFML\Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

#define slowa_omnie 4
class Omnie
{
public:
	Omnie(float w, float h);
	void draw(RenderWindow& window);

	~Omnie();

private:
	Font font;
	Text slowa[slowa_omnie];
};

