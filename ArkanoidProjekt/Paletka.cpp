#include "Paletka.h"


Paletka::Paletka(float t_X, float t_Y)
{
	shape.setPosition(t_X, t_Y);
	shape.setSize({ this->paletkaWidth, this->paletkaHeight });
	shape.setFillColor(Color::White);
	shape.setOrigin(paletkaWidth / 2.f, paletkaHeight / 2.f);

}

void Paletka::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

void Paletka::update()
{
	this->shape.move(this->velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0) {
		velocity.x = -paletkaVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 800) {
		velocity.x = paletkaVelocity;
	}
	else {
		velocity.x = 0;
	}
}

float Paletka::left()
{
	return this->shape.getPosition().x - shape.getSize().x/2.f;	//
}
float Paletka::right()
{
	return this->shape.getPosition().x + shape.getSize().x/2.f;	// 
}
float Paletka::top()
{
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}
float Paletka::bottom()
{
	return this->shape.getPosition().y + shape.getSize().y / 2.f;
}

Vector2f Paletka::getPosition()
{
	return shape.getPosition();
}