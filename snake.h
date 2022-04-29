#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

class Snake {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	static std::string potion_file_names[];
	float speedx, speedy;
	bool del = false;
	float CurrentFrame = 0;
	sf::Clock snake_clock;
public:
	Snake();
	void update();
	void draw(sf::RenderWindow&);
	void spawn();
	void setDel(bool);
	bool getDel();
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
};