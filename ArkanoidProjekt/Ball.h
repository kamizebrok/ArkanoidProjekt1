#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Ball : public Drawable
{	// dodaliœmy interfejs, klasa bêdzie dziedziczy³a publicznie interfejs Drawable (bêdzie "rysowalna"),
	// bêdzie przekazywaæ obiekt do odpowiedniej funkcji rysuj¹cej, (":" = dziedziczy)
	  
public:						// dostêp do dowolnej zmiennej i funkcji z dowolnego miejsca w kodzie
	Ball(float t_X, float t_Y);		// koordynaty, gdzie tworzymy nasz obiekt
	Ball() = delete;				// konstruktor, poprzez delete jest powstrzymywany przed jego generacj¹
	~Ball() = default;				// destruktor, niepotrzebne i¿ nieistotna jest dealokacja pamiêci etc.

	void update();					// aktualizowanie stanu obiektu aby siê porusza³o wszystko !!!

	void moveUp();		// zmiana ruchow
	void moveDown();
	void moveLeft();
	void moveRight();

	Vector2f getPosition();	// wektor 2 wartosci

	float left();
	float right();
	float top();
	float bottom();
	float ballVelocity{5.0f};		// prêdkoœæ pi³eczki
	void zmienVel(int x);
	Vector2f velocity{ ballVelocity, ballVelocity };	// wektor w dwóch wymiarach x i y

private:					// prywatna = nie mo¿na wykorzystywaæ zmiennych i funkcji zadeklarowanych w klasie 'na zewn¹trz', 
							// dostêp do zmiennych i funkcji tylko z poziomu klasy
	CircleShape circle;
	const float ballRadius{ 10.0f };		// promieñ pi³eczki

	void draw(RenderTarget& target, RenderStates state) const override;	// funkcja sta³a i nadpisujemy tutaj metudê wirtualn¹ z interfejsu
	// dzieku temu jest mozliwy do narysowania
};

