#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

namespace CEG {
	class Engine;

	class GraphicManager {
	public:
		GraphicManager(Engine *engine);
		~GraphicManager();

		void addImage(sf::Image& image);
		sf::Image& getImage(int index);
		
	private:
		Engine *engine;
		std::vector<sf::Image> images;
	};
}

