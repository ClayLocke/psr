#include "psr_game.h"

#include <iostream>

void introText() {
	std::cout << "Paper Scissors Rock \n";
	std::cout << "- for two players - \n";
}

void Game::init() {
	introText();
	// player types can be modified here (e.g. Computer vs Computer)
	p1_ = std::make_unique<Player>();
	p2_ = std::make_unique<Computer>();

	while (true) {
		std::cout << "How many games do you want to play? \n";
		std::string games;
		std::cin >> games;
		try {numberOfGames_ = std::stoi(games); }
		catch (std::logic_error) {
			std::cout << "Number of games must be a number. \n";
		}
		if (numberOfGames_ > 0)
			break;
		std::cout << "Please try again. \n";
	}
	std::cout << "Playing " << numberOfGames_ << " games." << std::endl;
}

void Game::run() {
	while(!p1_->getParticipantHand());
	while(!p2_->getParticipantHand());
	
	std::cout << p1_->printName() << ": " << p1_->hand_->printName() << " vs "
		<< p2_->printName() << ": " << p2_->hand_->printName() << " ";
	
	int result = p1_->hand_->compare(*p2_->hand_);
	if (result == 0)
		std::cout << "----> A draw. \n";
	if (result == -1)
		std::cout << "----> " << p1_->printName() << " wins. \n";
	if (result == 1)
		std::cout << "----> " << p2_->printName() << " wins. \n";
	p1_->tally_ += result;
	p2_->tally_ -= result;
}

void Game::printResults() {
	std::cout << "Game over. \n";
	std::cout << "From " << numberOfGames_ << " games ";
	int64_t result = (p1_->tally_ - p2_->tally_)/2;
	if (result == 0)
		std::cout << "it's a draw. \n";
	if (result < 0)
		std::cout << p1_->printName() << " wins by " << -1*result;
	if (result > 0)
		std::cout << p2_->printName() << " wins by " << result;
	std::cout << std::endl;
}
