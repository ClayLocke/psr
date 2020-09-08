#ifndef psr_game_h
#define psr_game_h

#include <cstdint>
#include <memory>

#include "item.h"
#include "player.h"

class Game {
public:
	void init();
	void run();
	int64_t getNumberOfGames() { return numberOfGames_;}
	void printResults();

private:
	std::unique_ptr<Participant> p1_;
	std::unique_ptr<Participant> p2_;
	int64_t numberOfGames_ = 0;
};

#endif /* psr_game_h */
