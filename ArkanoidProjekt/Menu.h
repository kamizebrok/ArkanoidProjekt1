#pragma once
#include<SFML\Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

#define maxmain 4
class Menu
{
public:		//dostêp z poza klasy
	Menu(float w, float h);

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int MenuKlik() {
		return MenuWybrane;
	}
	~Menu();

private:	// dostep jedynie wewnatrz
	int MenuWybrane;
	Font font;
	Text mainMenu[maxmain];
};

