#pragma once
#include<SFML\Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

#define trudnosci 3

class Opcje
{
public:
	Opcje(float w, float h);

	void draw(RenderWindow& window);
	void MoveLeft();
	void MoveRight();

	int OpcjeKlik() {
		return OpcjaWybrana;
	}
	~Opcje();
private:
	int OpcjaWybrana;
	Font font;
	Text trudnosc[trudnosci];
};

