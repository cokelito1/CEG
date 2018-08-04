#include <SFML/Window.hpp>
#include "CEG.h"

int main() {
	CEG::Engine *eng = new CEG::Engine();
	eng->run();
	delete eng;
	return 0;
}