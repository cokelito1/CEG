#include "MapManager.h"
#include <iostream>
#include "CEG.h"

namespace CEG {
	MapManager::MapManager(Engine *engine) {
		this->engine = engine;
		tileMngr = engine->GetTileManager();
		tiles = new std::vector<Tile>;
		tiles->reserve(25 * 18);
		CurrentMap = 9999;
	}

	MapManager::~MapManager() { 
		delete tiles;
	}

	void MapManager::addMap(std::vector<int> map) {
		maps.push_back(map);
	}

	void MapManager::loadMap(int index) {
		sf::Clock t1;
		if (CurrentMap != index) {
			CurrentMap = index;
			tiles->clear();
			std::cout << "Cargando mapa " << CurrentMap << std::endl;
			int YLine = 0;
			int XLine = 0;
			int spriteCount = 0;
			for (int i = 0; i < maps[CurrentMap].size(); i++) {
				Tile tmp = tileMngr->getTile(maps[CurrentMap][i]);
				tmp.sprite.move(XLine * 32, YLine * 32);
				spriteCount++;
				XLine++;
				if (spriteCount > 24) {
					YLine++;
					XLine = 0;
					spriteCount = 0;
				}
				tiles->push_back(tmp);
			}
			std::cout << "Mapa " << CurrentMap << " cargado con " << maps[CurrentMap].size() << " tiles" << std::endl;
		}
		std::cout << "Mapa cargado en " << t1.getElapsedTime().asSeconds() << std::endl;
	}

	void MapManager::draw(sf::RenderWindow *window) {
		for (int i = 0; i < tiles->size(); i++) {
			try {
				tiles->at(i).draw(window);
			}
			catch (std::out_of_range &oor) {
				std::cout << "Fuera de rango en " << i << std::endl;
				std::cout << oor.what() << std::endl;
				exit(-1);
			}
		}
	}
}