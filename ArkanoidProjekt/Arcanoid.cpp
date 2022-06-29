#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"Ball.h"
#include"Paletka.h"
#include"Bloczek.h"
#include "Menu.h"
#include "Opcje.h"
#include "Omnie.h"
using namespace sf;
using namespace std;


template <class T1, class T2> bool isIntersecting(T1 &A, T2 &B)		// tworzenie szablonu dla klas, zwraca boola
{
	return A.right() >= B.left() && A.left() <= B.right()
		&& A.bottom() >= B.top() && A.top() <= B.bottom();	// prawa krawêdŸ jest dalej od lewej etc.. -> sprawdzamy kolizjê
}

bool czyKolizja(Paletka& paletka, Ball& ball)
{
	if (!isIntersecting(paletka, ball)) {	// isIntersecting -> sprawdzamy czy NIE zachodzi kolizja
		return false;
	}
	ball.moveUp();

	if (ball.getPosition().x < paletka.getPosition().x) {
		ball.moveLeft();
	}
	else if (ball.getPosition().x > paletka.getPosition().x) {
		ball.moveRight();
	}
}

bool czyKolizja(Bloczek& bloczek, Ball& ball) {
	if (!isIntersecting(bloczek, ball)) 
		return false;

	bloczek.niszcz();

	float stykLeft{ ball.right() - bloczek.left() };
	float stykRight{ bloczek.right() - ball.left() };

	float stykTop{ ball.bottom() - bloczek.top() };
	float stykBottom{ bloczek.bottom() - ball.top() };

	bool ballzLeft(abs(stykLeft) < (abs(stykRight)));
	bool ballzTop(abs(stykTop) < abs(stykBottom));

	float minStykX{ ballzLeft ? stykLeft : stykRight };	// "?" -wyra¿enie warunkowe, ":" -w przeciwnym razie
	float minStykY{ ballzTop ? stykTop : stykBottom };

	if (abs(minStykX) < abs(minStykY)) {
		ballzLeft ? ball.moveLeft() : ball.moveRight();
	}
	else {
		ballzTop ? ball.moveUp() : ball.moveDown();
	}
}
void vel(Ball& ball, int x)
{
	ball.zmienVel(x);
}

int main()
{
	//MENU TEST  
	Ball ball(400, 300);	// tworzenie klasy pi³eczki na œrodku ekranu
	Ball ball1(500, 200);
	RenderWindow MENU{ VideoMode{960,720}, "Arcanoid Menu", Style::Default };
	Menu mainMenu(MENU.getSize().x, MENU.getSize().y);
	while (MENU.isOpen()) {
		Event event0;
		while (MENU.pollEvent(event0)) {
			if (event0.type == Event::Closed) {
				MENU.close();
				return 0;
			}
			if (event0.type == Event::KeyReleased) {
				if (event0.key.code == Keyboard::Up) {
					mainMenu.MoveUp();
					break;
				}
				if (event0.key.code == Keyboard::Down) {
					mainMenu.MoveDown();
					break;
				}
				if (event0.key.code == Keyboard::Return) {
					RenderWindow Options(VideoMode{ 960,720 }, "Opcje");
					RenderWindow About(VideoMode{ 960,720 }, "O Mnie");

					int x = mainMenu.MenuKlik();
					if (x == 0) 
					{
						MENU.close();
						break;
					}
					if (x == 1)
					{
						Opcje ObOpcje(Options.getSize().x, Options.getSize().y);	//obiekt klasy opcje
						while (Options.isOpen()) {
							Event event1;							// kolejny event
							while (Options.pollEvent(event1)) {
								if (event1.type == Event::Closed) {
									Options.close();
								}

								if (event1.type == Event::KeyReleased) {
									if (event1.key.code == Keyboard::Right) {
										ObOpcje.MoveRight();
										break;
									}
									if (event1.key.code == Keyboard::Left) {
										ObOpcje.MoveLeft();
										break;
									}
									if (event0.key.code == Keyboard::Return) {
										int t = ObOpcje.OpcjeKlik();
										if (t == 0) {
											cout << "Wybrano poziom Easy ";
											vel(ball, t);
											Options.close();
										}
										if (t == 1) {
											cout << "Wybrano poziom Normal ";
											vel(ball, t);
											Options.close();
										}
										if (t == 2) {
											cout << "Wybrano poziom Hard ";
											vel(ball, t);
											Options.close();
										}
									}
								}
								Options.clear();
								ObOpcje.draw(Options);
								About.close();
								Options.display();
							}
						}
					}
					if (x == 2)
					{
						Omnie ObOmnie(About.getSize().x, About.getSize().y);	// obiekt klasy Omnie
						while (About.isOpen()) {
							Event event1;
							while (About.pollEvent(event1)) {
								if (event1.type == Event::Closed) {
									About.close();
								}
								if (event1.type == Event::KeyPressed) {
									if (event1.key.code == Keyboard::Escape) {
										About.close();
									}
								}
								About.clear();
								ObOmnie.draw(About);
								Options.close();
								About.display();
							}
						}
					}
					if (x == 3) {
						MENU.close();
						return 0;
					}
					break;
				}
			}
		MENU.clear();
		mainMenu.draw(MENU);
		MENU.display();
		}
	}

		// (tworzenie klasy pi³eczki na œrodku ekranu) -> prawdopodobnie lepsze miejsce
	Paletka paletka(400, 550);
	RenderWindow window{ VideoMode{800,600}, "Arcanoid" };
	window.setFramerateLimit(80);			// wymuszamy 60 fps

	Event event;		// zdarzenie (obiekt), ka¿da interakcja (wszystko co u¿ytkownik bêdzie robi³)
	unsigned bloczekX = 10, bloczekY = 4, bloczekWidth = 60, bloczekHeight = 20;

	vector<Bloczek> bloczki;	// dynamiczna tablica(kontener) do przechowywania danych o bloczkach

	for (int i = 0; i < bloczekY; i++) {
		for (int j = 0; j < bloczekX; j++) {
			bloczki.emplace_back((j + 1) * (bloczekWidth + 10), (i + 2) * (bloczekHeight + 5), bloczekWidth, bloczekHeight);
			// tworzy bloczek na koncu kontenera, oczekuje wartoœci parametrów konstruktora bloczka
		}
	}

	while (true)							// g³ówna pêtla gry
	{
		window.clear(Color::Black);
		window.pollEvent(event);			// wy³apywanie wszystich wydarzeñ w obrêbie naszego obiektu

		if (event.type == Event::Closed)	// Zamykanie programu
		{
			window.close();
			break;
		}

		ball.update();
		paletka.update();
		czyKolizja(paletka, ball);

		for (auto& bloczek : bloczki)		// autoloop, takie "dla ka¿dego" automatycznie
			if (czyKolizja(bloczek, ball)) 
				break;		// bo kolizja nastêpuje tylko raz

		auto i = remove_if(begin(bloczki), end(bloczki), [](Bloczek& bloczek) { return bloczek.czyZniszczony(); });
		bloczki.erase(i, end(bloczki));		// usuwamy z kontenera

		window.draw(ball);
		window.draw(paletka);

		for (auto& bloczek : bloczki)	
			window.draw(bloczek);

		window.display();					// wyœwietlamy obiekty metod¹ display
	}
	return 0;
}
