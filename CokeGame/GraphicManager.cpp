#include "GraphicManager.h"

namespace CEG {
	GraphicManager::GraphicManager(Engine *engine) {
		this->engine = engine;
	}


	GraphicManager::~GraphicManager() {
	}

	void GraphicManager::addImage(sf::Image& image) {
		images.push_back(image);
	}

	sf::Image& GraphicManager::getImage(int index) {
		return images.at(index);
	}
}