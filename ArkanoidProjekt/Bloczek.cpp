#include "Bloczek.h"

Bloczek::Bloczek(float t_X, float t_Y, float t_Width, float t_Height)
{
	shape.setPosition(t_X, t_Y);
	shape.setSize({ t_Width, t_Height });
	shape.setFillColor(Color::White);
	shape.setOrigin(t_Width / 2.f, t_Height / 2.f);
}

void Bloczek::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

float Bloczek::left() {
	return this->shape.getPosition().x - shape.getSize().x / 2.f;
}
float Bloczek::right() {
	return this->shape.getPosition().x + shape.getSize().x / 2.f;
}
float Bloczek::top() {
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}
float Bloczek::bottom() {
	return this->shape.getPosition().y - shape.getSize().y / 2.f;
}

Vector2f Bloczek::getPosition() {
	return shape.getPosition();
}

bool Bloczek::czyZniszczony() {
	return this->zniszczon;
}
void Bloczek::niszcz() {
	this->zniszczon = true;
}
Vector2f Bloczek::getSize() {
	return shape.getSize();
}

void Bloczek::update() {

}