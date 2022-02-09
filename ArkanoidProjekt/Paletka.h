#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;

class Paletka : public Drawable
{
public:
	Paletka(float t_X, float t_Y);
	Paletka() = delete;
	~Paletka() = default;
	void update();

	float right();
	float left();
	float top();
	float bottom();

	Vector2f getPosition();

	float paletkaWidth{ 80.0f };
	float paletkaVelocity{ 10.0f };
	Vector2f velocity{ paletkaVelocity, 0.f };

private:
	void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape shape;
	const float paletkaHeight{ 20.f };

};

