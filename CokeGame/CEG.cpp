#include "CEG.h"
#include <iostream>
#include "Tile.h"
#include <random>

namespace CEG {

	Tile *CreateTile(int x, int y, sf::Image image) {
		return new Tile(x, y, image);
	}

	Tile *CreateTile(int x, int y, sf::Image image, int iX, int iY) {
		return new Tile(x, y, image, iX, iY);
	}

	Engine::Engine() {
		sf::Clock t1;
		window = new sf::RenderWindow(sf::VideoMode(800, 544), "Hello World");
		
		graphicMngr = new GraphicManager(this);
		tileMngr = new TileManager(this);
		mapMngr = new MapManager(this);

		sf::Image imgTest;
		imgTest.loadFromFile("./test.png");

		graphicMngr->addImage(imgTest);	

		imgTest.loadFromFile("./cross.png");
		graphicMngr->addImage(imgTest);

		imgTest.loadFromFile("./circle.png");
		graphicMngr->addImage(imgTest);


		tilePointers.push_back(CreateTile(0, 0, graphicMngr->getImage(0)));
		tilePointers.push_back(CreateTile(0, 0, graphicMngr->getImage(0), 32, 0));
		tilePointers.push_back(CreateTile(0, 0, graphicMngr->getImage(0), 96, 0));
		tilePointers.push_back(CreateTile(0, 0, graphicMngr->getImage(0), 128, 0));
		tilePointers.push_back(CreateTile(0, 0, graphicMngr->getImage(0), 256, 0));

		for (auto i : tilePointers) {
			tileMngr->addTile(*i);
		}

		std::vector<int> testMap;
		testMap.push_back(0);
		//testMap.push_back(1);

		mapMngr->addMap(testMap);
		mapMngr->loadMap(0);
		
		testMap.clear();
		for (int i = 0; i < ((25 * 17) / 4) + 1; i++) {
			testMap.push_back(1);
			testMap.push_back(0);
			testMap.push_back(2);
			testMap.push_back(3);
		}
		mapMngr->addMap(testMap);

		int normMap[] = {
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 1, 0, 0 ,0 ,0 ,0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		};

		for (int i = 125; i < 150; i++) {
			normMap[i] = 1;
		}

		for (int i = 275; i < 300; i++) {
			normMap[i] = 1;
		}

		std::vector<int> normMapVec(normMap, normMap + sizeof(normMap) / sizeof(normMap[0]));
		mapMngr->addMap(normMapVec);
		mapMngr->loadMap(2);

		for (int i = 0; i < normMapVec.size(); i++) {
			if (normMapVec.at(i) == 1) {
				mapMngr->tiles->at(i).clickable = false;
			}
		}
		
		gameFont.loadFromFile("font.ttf");

		window->setFramerateLimit(60);
		std::cout << "Tiempo de construccion de CEG: " << t1.getElapsedTime().asSeconds() << " segundos" << std::endl;
	}

	Engine::~Engine() { 
		delete window;
		delete graphicMngr;
		delete tileMngr;
		delete mapMngr;
		for (auto i : tilePointers) {
			delete i;
		}
	}

	GraphicManager *Engine::GetGraphicManager() {
		return graphicMngr;
	}

	TileManager *Engine::GetTileManager() {
		return tileMngr;
	}

	sf::RenderWindow *Engine::GetWindow() {
		return window;
	}

	void Engine::run() {
restart:
		int gameStatus = 0;
		int currentTurn = 0;
		int currentCross = 0, currentCicle = 0;

		std::random_device rd;
		std::default_random_engine random(rd());
		std::uniform_int_distribution<int> gen(0, 8);

		int gameState[9];
		for (int i = 0; i < 9; i++) {
			gameState[i] = 3;
		}

		sf::Sprite cross[5];
		sf::Sprite circle[4];

		sf::Texture Cross;
		sf::Texture circles;

		Cross.loadFromImage(graphicMngr->getImage(1), sf::IntRect(0, 0, 128, 128));
		circles.loadFromImage(graphicMngr->getImage(2), sf::IntRect(0, 0, 128, 128));

		for (int i = 0; i < 5; i++) {
			cross[i].setTexture(Cross);
			cross[i].setPosition(0, 0);
		}

		for (int i = 0; i < 4; i++) {
			circle[i].setTexture(circles);
			circle[i].setPosition(0, 0);
		}

		while (window->isOpen()) {
			sf::Event evt;
			while (window->pollEvent(evt)) {
				switch (evt.type) {
				case sf::Event::Closed:
					window->close();
					break;
				case sf::Event::MouseButtonPressed:
					if(gameStatus == 0) {
						if (currentTurn == 0) {
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
								sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
								for (int i = 0; i < mapMngr->tiles->size(); i++) {
									if (mapMngr->tiles->at(i).clickable) {
										if (mapMngr->tiles->at(i).sprite.getGlobalBounds().contains((sf::Vector2f)mousePos)) {
											std::cout << "Clicked en " << i << std::endl;
											int Yax = i / 25;
											int Xax = i % 25;

											if (gameState[(Yax / 6) * 3 + (Xax / 8)] != 3) {
												break;
											}

											cross[currentCross].setPosition(((float)Xax * 32) - cross[currentCross].getTexture()->getSize().x / 2, ((float)Yax * 32) - cross[currentCross].getTexture()->getSize().y / 2);
											gameState[(Yax / 6) * 3 + (Xax / 8)] = 0;
											currentTurn = 1;
											if (currentCross < 5) {
												currentCross++;
												currentTurn = 1;
											}
											if (i == 0) {
												mapMngr->loadMap(1);
											}
											for (int i = 0; i < 3; i++) {
												for (int j = 0; j < 3; j++) {
													std::cout << gameState[i * 3 + j] << " ";
												}
												std::cout << std::endl;
											}
											break;
										}
									}
								}
							}
						}
						break;
					}
					else {
						goto restart;
					}
					break;
				case sf::Event::KeyPressed:
					if (gameStatus == 1 || gameStatus == 2 || gameStatus == 3 && evt.key.code == sf::Keyboard::Space) {
						goto restart;
					}
				}
			}

			if (gameState[0] == 0 && gameState[1] == 0 && gameState[2] == 0) {
				gameStatus = 1;
			}
			else if (gameState[3] == 0 && gameState[4] == 0 && gameState[5] == 0) {
				gameStatus = 1;
			}
			else if (gameState[6] == 0 && gameState[7] == 0 && gameState[8] == 0) {
				gameStatus = 1;
			}
			else if (gameState[0] == 0 && gameState[3] == 0 && gameState[6] == 0) {
				gameStatus = 1;
			}
			else if (gameState[1] == 0 && gameState[4] == 0 && gameState[7] == 0) {
				gameStatus = 1;
			}
			else if (gameState[2] == 0 && gameState[5] == 0 && gameState[8] == 0) {
				gameStatus = 1;
			}
			else if (gameState[0] == 0 && gameState[4] == 0 && gameState[8] == 0) {
				gameStatus = 1;
			}
			else if (gameState[2] == 0 && gameState[4] == 0 && gameState[6] == 0) {
				gameStatus = 1;
			}

			if (currentTurn == 1) {
				while (1 && currentCicle < 4 && currentCross < 5 && gameStatus == 0) {
					int index = gen(random);
					if (gameState[index] == 3) {
						gameState[index] = 1;
						circle[currentCicle].setPosition((index % 3) * 9 * 32, (index / 3) * 7 * 32);
						currentCicle++;
						currentTurn = 0;
						break;
					}
				}
				std::cout << std::endl;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						std::cout << gameState[i * 3 + j] << " ";
					}
					std::cout << std::endl;
				}
			}

			if (gameState[0] == 1 && gameState[1] == 1 && gameState[2] == 1) {
				gameStatus = 2;
			}
			else if (gameState[3] == 1 && gameState[4] == 1 && gameState[5] == 1) {
				gameStatus = 2;
			}
			else if (gameState[6] == 1 && gameState[7] == 1 && gameState[8] == 1) {
				gameStatus = 2;
			}
			else if (gameState[0] == 1 && gameState[3] == 1 && gameState[6] == 1) {
				gameStatus = 2;
			}
			else if (gameState[1] == 1 && gameState[4] == 1 && gameState[7] == 1) {
				gameStatus = 2;
			}
			else if (gameState[2] == 1 && gameState[5] == 1 && gameState[8] == 1) {
				gameStatus = 2;
			}
			else if (gameState[0] == 1 && gameState[4] == 1 && gameState[8] == 1) {
				gameStatus = 2;
			}
			else if (gameState[2] == 1 && gameState[4] == 1 && gameState[6] == 1) {
				gameStatus = 2;
			}

			if (gameStatus == 0) {
				window->clear(sf::Color::Black);
				mapMngr->draw(window);
				for (int i = 0; i < currentCross; i++) {
					if (i < 5) {
						window->draw(cross[i]);
					}
				}
				for (int i = 0; i < currentCicle; i++) {
					if (i < 4) {
						window->draw(circle[i]);
					}
				}

				if (currentCicle > 3 && currentCross > 4 && gameStatus == 0) {
					gameStatus = 3;
				}
			}
			else if (gameStatus == 1) {
				sf::Text text;
				text.setFont(gameFont);
				text.setString("Ganaste\n click para volver a empezar");
				text.setCharacterSize(24);
				text.setFillColor(sf::Color::Black);
				text.setPosition((window->getSize().x / 2) - text.getCharacterSize(), (window->getSize().y / 2) - text.getCharacterSize());
				window->clear(sf::Color::Green);
				window->draw(text);
			}
			else if (gameStatus == 2) {
				sf::Text text;
				text.setFont(gameFont);
				text.setString("Perdiste\n click para volver a empezar");
				text.setCharacterSize(24);
				text.setFillColor(sf::Color::Black);
				text.setPosition((window->getSize().x / 2) - text.getCharacterSize(), (window->getSize().y / 2) - text.getCharacterSize());
				window->clear(sf::Color::Red);
				window->draw(text);
			}
			else if (gameStatus == 3) {
				sf::Text text;
				text.setFont(gameFont);
				text.setString("Empate\n click para volver a empezar");
				text.setCharacterSize(24);
				text.setFillColor(sf::Color::Black);
				text.setPosition((window->getSize().x / 2) - text.getCharacterSize(), (window->getSize().y / 2) - text.getCharacterSize());
				window->clear(sf::Color::Yellow);
				window->draw(text);
			}
			window->display();
		}
	}
}