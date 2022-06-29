#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Ball : public Drawable
{	// dodali�my interfejs, klasa b�dzie dziedziczy�a publicznie interfejs Drawable (b�dzie "rysowalna"),
	// b�dzie przekazywa� obiekt do odpowiedniej funkcji rysuj�cej, (":" = dziedziczy)
	  
public:						// dost�p do dowolnej zmiennej i funkcji z dowolnego miejsca w kodzie
	Ball(float t_X, float t_Y);		// koordynaty, gdzie tworzymy nasz obiekt
	Ball() = delete;				// konstruktor, poprzez delete jest powstrzymywany przed jego generacj�
	~Ball() = default;				// destruktor, niepotrzebne i� nieistotna jest dealokacja pami�ci etc.

	void update();					// aktualizowanie stanu obiektu aby si� porusza�o wszystko !!!

	void moveUp();		// zmiana ruchow
	void moveDown();
	void moveLeft();
	void moveRight();

	Vector2f getPosition();	// wektor 2 wartosci

	float left();
	float right();
	float top();
	float bottom();
	float ballVelocity{5.0f};		// pr�dko�� pi�eczki
	void zmienVel(int x);
	Vector2f velocity{ ballVelocity, ballVelocity };	// wektor w dw�ch wymiarach x i y

private:					// prywatna = nie mo�na wykorzystywa� zmiennych i funkcji zadeklarowanych w klasie 'na zewn�trz', 
							// dost�p do zmiennych i funkcji tylko z poziomu klasy
	CircleShape circle;
	const float ballRadius{ 10.0f };		// promie� pi�eczki

	void draw(RenderTarget& target, RenderStates state) const override;	// funkcja sta�a i nadpisujemy tutaj metud� wirtualn� z interfejsu
	// dzieku temu jest mozliwy do narysowania
};

