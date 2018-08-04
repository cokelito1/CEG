#pragma once

#include <vector>

#include "TileManager.h"
#include "GraphicManager.h"
#include "MapManager.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace CEG {
	class Engine {
	public:
		Engine();
		~Engine();

		void run();

		sf::RenderWindow *GetWindow();

		TileManager *GetTileManager();
		GraphicManager *GetGraphicManager();
	private:
		std::vector<Tile *> tilePointers;

		sf::RenderWindow *window;

		TileManager *tileMngr;
		GraphicManager *graphicMngr;
		MapManager *mapMngr;
	};
}

