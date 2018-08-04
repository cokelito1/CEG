#pragma once

#include <vector>

#include "Tile.h"

namespace CEG {
	class GraphicManager;
	class Engine;

	class TileManager {
	public:
		TileManager(Engine *engine);
		~TileManager();

		void addTile(Tile& tile);
		Tile getTile(int index);

		void drawMap(sf::RenderWindow *window);
		std::vector<Tile> tiles;
	private:
		Engine *engine;
		GraphicManager *graphicMngr;	
		
	};
}

