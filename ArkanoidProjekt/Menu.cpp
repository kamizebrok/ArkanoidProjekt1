#include "Menu.h"

Menu::Menu(float w, float h)
{
	if (!font.loadFromFile("Fonts/AlexandriaFLF.ttf")) {
		cout << "Czcionka nie dziala";
	}
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("Graj");
	mainMenu[0].setCharacterSize(60);
	mainMenu[0].setPosition(400, 200);

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Opcje");
	mainMenu[1].setCharacterSize(60);
	mainMenu[1].setPosition(400, 300);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("O Mnie");
	mainMenu[2].setCharacterSize(60);
	mainMenu[2].setPosition(400, 400);

	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("Wyjscie");
	mainMenu[3].setCharacterSize(60);
	mainMenu[3].setPosition(400, 500);

	MenuWybrane = -1;
}
Menu::~Menu()
{
}

void Menu::draw(RenderWindow& window) {
	for (int i = 0; i < maxmain; i++) {
		window.draw(mainMenu[i]);
	}
}

void Menu::MoveUp(){
	if (MenuWybrane >= 0) {
		mainMenu[MenuWybrane].setFillColor(Color::White);

		MenuWybrane--;
		if (MenuWybrane == -1) {
			MenuWybrane = 3;
		}
		mainMenu[MenuWybrane].setFillColor(Color::Blue);
	}
}

void Menu::MoveDown() {
	if (MenuWybrane + 1 <= maxmain) {
		mainMenu[MenuWybrane].setFillColor(Color::White);
		MenuWybrane++;
		if (MenuWybrane == 4) {
			MenuWybrane = 0;
		}
		mainMenu[MenuWybrane].setFillColor(Color::Blue);
	}
}