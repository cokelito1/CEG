#include "Tile.h"
#include <SFML/Graphics.hpp>

namespace CEG {
	Tile::Tile() { }

	Tile::Tile(const Tile& Copy) : image(Copy.image), sprite(Copy.sprite){
		texture.loadFromImage(image);
		x = Copy.x;
		y = Copy.y;
		//sprite.setPosition(x, y);
	}

	Tile::Tile(int x, int y, sf::Image image) {
		createSprite(x, y, image);
	}

	Tile::Tile(int x, int y, sf::Image image, int iX, int iY) {
		createSprite(x, y, image, iX, iY);
	}
	
	Tile::~Tile() { }

	void Tile::createSprite(int x, int y, sf::Image image) {
		this->image = image;
		texture.loadFromImage((this->image), sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)));
		sprite.setTexture(texture);
		sprite.setPosition(x, y);
	}

	void Tile::createSprite(int x, int y, sf::Image image, int iX, int iY) {
		this->image = image;
		texture.loadFromImage((this->image), sf::IntRect(sf::Vector2i(iX, iY), sf::Vector2i(32, 32)));
		sprite.setTexture(texture);
		sprite.setPosition(x, y);
	}

	void Tile::draw(sf::RenderWindow *window) {
		window->draw(sprite);
	}
}