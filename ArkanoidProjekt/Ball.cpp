#include "Ball.h"

Ball::Ball(float t_X, float t_Y)
{
	circle.setPosition(t_X, t_Y);
	circle.setRadius(this->ballRadius);
	circle.setFillColor(Color::Blue);
	circle.setOrigin(this->ballRadius, this->ballRadius); // przesuwamy punkt wzglêdem którego bêdziemy odnosiæ siê do pi³eczki aby by³ w œrodku
	// dwukrotnie o promieñ
}

void Ball::draw(RenderTarget& target, RenderStates state) const		// nie bêdzie zmieniaæ pól klasy
{
	target.draw(this->circle, state);		// rysowanie obiektu draw(kszta³t, parametr state(?))
}

void Ball::update()
{
	circle.move(this->velocity);

	if (this->left() < 0)					// zderzenie z lew¹ krawêdzi¹
	{
		velocity.x = ballVelocity;
	}
	else if (this->right() > 800)			// kiedy zderza siê z praw¹ krawêdzi¹ zmieniamy wektor prêdkoœci
	{
		velocity.x = -ballVelocity;
	}

	if (this->top() < 0)					// dalej powtarzamy
	{
		velocity.y = ballVelocity;
	}
	else if (this->bottom() > 600)
	{
		velocity.y = -ballVelocity;
	}
}

float Ball::left()
{
	return this->circle.getPosition().x - circle.getRadius();	// ¿eby wyznaczyæ lew¹ krawêdŸ kulki nale¿y odj¹æ promieñ
}
float Ball::right()
{
	return this->circle.getPosition().x + circle.getRadius();	// dodanie promienia by wyznaczyæ praw¹ krawêdŸ
}
float Ball::top()
{
	return this->circle.getPosition().y - circle.getRadius();	// to samo z górn¹
}
float Ball::bottom()
{
	return this->circle.getPosition().y + circle.getRadius();	// i z doln¹
}
void Ball::zmienVel(int x)
{
	if (x == 0)
		ballVelocity = 3.0f;
	if (x == 1)
		ballVelocity = 6.0f;
	if (x == 2)
		ballVelocity = 9.0f;
}

void Ball::moveDown()
{
	this->velocity.y = ballVelocity;
}
void Ball::moveUp()
{
	this->velocity.y = -ballVelocity;
}
void Ball::moveRight()
{
	this->velocity.x = ballVelocity;
}
void Ball::moveLeft()
{
	this->velocity.x = -ballVelocity; 
}

Vector2f Ball::getPosition()
{
	return circle.getPosition();
}