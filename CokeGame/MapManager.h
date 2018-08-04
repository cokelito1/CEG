#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Tile.h"

namespace CEG {
	class TileManager;
	class Engine;

	class MapManager {
	public:
		MapManager(Engine *engine);
		~MapManager();

		void addMap(std::vector<int> map);
		void loadMap(int index);
		void draw(sf::RenderWindow *window);

		std::vector<Tile> *tiles;
	private:
		
		std::vector<std::vector<int>> maps;

		int CurrentMap;

		TileManager *tileMngr;
		Engine *engine;
	};
}

