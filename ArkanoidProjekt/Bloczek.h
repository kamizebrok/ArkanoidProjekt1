#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Bloczek : public Drawable
{
public:
	Bloczek(float t_X, float t_Y, float t_Width, float t_Height);
	Bloczek() = delete;
	~Bloczek() = default;

	void update();
	Vector2f getPosition();

	float left();
	float right();
	float top();
	float bottom();

	bool czyZniszczony();
	void niszcz();
	Vector2f getSize();
private:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
	RectangleShape shape;
	bool zniszczon{ false }; // inicjalizujemy od razu false

};

