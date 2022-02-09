#include "Opcje.h"
Opcje::Opcje(float w, float h)
{
	if (!font.loadFromFile("Fonts/AlexandriaFLF.ttf")) {
		cout << "Czcionka nie dziala";
	}
	trudnosc[0].setFont(font);
	trudnosc[0].setFillColor(Color::White);
	trudnosc[0].setString("Easy");
	trudnosc[0].setCharacterSize(40);
	trudnosc[0].setPosition(150, 200);

	trudnosc[1].setFont(font);
	trudnosc[1].setFillColor(Color::White);
	trudnosc[1].setString("Normal");
	trudnosc[1].setCharacterSize(40);
	trudnosc[1].setPosition(400, 200);

	trudnosc[2].setFont(font);
	trudnosc[2].setFillColor(Color::White);
	trudnosc[2].setString("Hard");
	trudnosc[2].setCharacterSize(40);
	trudnosc[2].setPosition(650, 200);

	OpcjaWybrana = 0;
}
Opcje::~Opcje()
{
}

void Opcje::draw(RenderWindow& window) {
	for (int i = 0; i < trudnosci; i++) {
		window.draw(trudnosc[i]);
	}
}

void Opcje::MoveLeft() {
	if (OpcjaWybrana >= 0) {
		trudnosc[OpcjaWybrana].setFillColor(Color::White);

		OpcjaWybrana--;
		if (OpcjaWybrana == -1) {
			OpcjaWybrana = 2;
		}
		trudnosc[OpcjaWybrana].setFillColor(Color::Blue);
	}
}

void Opcje::MoveRight() {
	if (OpcjaWybrana + 1 <= trudnosci) {
		trudnosc[OpcjaWybrana].setFillColor(Color::White);
		OpcjaWybrana++;
		if (OpcjaWybrana == 3) {
			OpcjaWybrana = 0;
		}
		trudnosc[OpcjaWybrana].setFillColor(Color::Blue);
	}
}