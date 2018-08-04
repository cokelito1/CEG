#pragma once

#include <SFML/Graphics.hpp>

namespace CEG {
	class Tile {
	public:
		bool clickable = true;

		Tile();
		Tile(const Tile& Copy);
		Tile(int x, int y, sf::Image image);
		Tile(int x, int y, sf::Image image, int iX, int iY);
		~Tile();
		
		int x, y;
		sf::Sprite sprite;

		void createSprite(int x, int y, sf::Image image);
		void createSprite(int x, int y, sf::Image image, int iX, int iY);

		void draw(sf::RenderWindow *window);
	private:
		sf::Image image;
		sf::Texture texture;
	};
}

