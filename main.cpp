// Paper Scissors Rock game.
//
// For two players

#include <cstdint>

#include "psr_game.h"

int main() {
	Game game;
	game.init();
	int64_t numberOfGames = game.getNumberOfGames();
	while (numberOfGames > 0) {
		game.run();
		--numberOfGames;
	}
	game.printResults();
	
    return 0;
}
