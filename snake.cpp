#include "snake.h"
#include "settings.h"
	
Snake::Snake() {
	texture.loadFromFile(IMAGES_FOLDER + SNAKE_RIGHT_FILE_NAME);
	sprite.setTexture(texture);
	spawn();
}
void Snake::update() {
	sprite.move(2.f, 0.f);

	float time = snake_clock.getElapsedTime().asMicroseconds();
	snake_clock.restart();
	time = time / 800;
	sprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
	CurrentFrame += 0.015 * time;
	if (sprite.getPosition().x >= 1200) {
		texture.loadFromFile(IMAGES_FOLDER + SNAKE_RIGHT_FILE_NAME);
		sprite.setTexture(texture);
		spawn();
	}
		if (CurrentFrame > 9) CurrentFrame -= 9;
		sprite.setTextureRect(sf::IntRect(128 * int(CurrentFrame), 0, 128, 128));
}
void Snake::draw(sf::RenderWindow& window) { window.draw(sprite); }
void Snake::spawn() {
	sf::FloatRect g_bound = sprite.getGlobalBounds();
	float x = -200;
	float y = 780;
	sprite.setPosition(x, y);
	speedx = 2.f;
	speedy = 0.f;
}
sf::FloatRect Snake::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Snake::getPosition() { return sprite.getPosition(); }
void Snake::setDel(bool a) { del = a; }
bool Snake::getDel() { return del; }