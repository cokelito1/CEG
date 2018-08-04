#include <iostream>
#include "TileManager.h"
#include "CEG.h"

namespace CEG {

	TileManager::TileManager(Engine *engine) {
		this->engine = engine;
		graphicMngr = engine->GetGraphicManager();
	}

	TileManager::~TileManager() {
	}

	void TileManager::addTile(Tile& tile) {
		tiles.push_back(tile);
	}

	Tile TileManager::getTile(int index) {
		try {
			return tiles.at(index);
		}
		catch (std::out_of_range &oor) {
			std::cout << "Fuera de rango en : " << index << std::endl;
			std::cout << oor.what() << std::endl;
			exit(-1);
		}
	}

	void TileManager::drawMap(sf::RenderWindow *window) {
		for (auto i : tiles) {
			i.draw(window);
		}
	}
}
