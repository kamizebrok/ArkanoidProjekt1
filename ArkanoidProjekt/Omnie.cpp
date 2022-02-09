#include "Omnie.h"

Omnie::Omnie(float w, float h)
{
	if (!font.loadFromFile("Fonts/AlexandriaFLF.ttf")) {
		cout << "Czcionka nie dziala";
	}
	slowa[0].setFont(font);
	slowa[0].setFillColor(Color::White);
	slowa[0].setString("Nazywam sie Kamil Zebrok i studiuje Informatyke na Politechnice Slaskiej.");
	slowa[0].setCharacterSize(15);
	slowa[0].setPosition(50, 50);

	slowa[1].setFont(font);
	slowa[1].setFillColor(Color::White);
	slowa[1].setString("Jest to projekt na przedmiot Programowanie I i zostal napisany w jezyku C++ z uzyciem biblioteki SFML.");
	slowa[1].setCharacterSize(15);
	slowa[1].setPosition(50, 100);

	slowa[2].setFont(font);
	slowa[2].setFillColor(Color::White);
	slowa[2].setString("Przedmiot ten jest prowadzony przez dr inz. Rafala Brocka.");
	slowa[2].setCharacterSize(15);
	slowa[2].setPosition(50, 150);

	slowa[3].setFont(font);
	slowa[3].setFillColor(Color::White);
	slowa[3].setString("Gra powstala w lutym 2022.");
	slowa[3].setCharacterSize(15);
	slowa[3].setPosition(50, 300);
}
Omnie::~Omnie()
{
}

void Omnie::draw(RenderWindow& window) {
	for (int i = 0; i < slowa_omnie; i++) {
		window.draw(slowa[i]);
	}
}