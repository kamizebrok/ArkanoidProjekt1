#pragma once
#include<SFML\Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

#define maxmain 4
class Menu
{
public:		
	Menu(float w, float h);

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int MenuKlik() {
		return MenuWybrane;
	}
	~Menu();

private:
	int MenuWybrane;
	Font font;
	Text mainMenu[maxmain];
};

