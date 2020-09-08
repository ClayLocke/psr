#ifndef player_h
#define player_h

#include <memory>
#include <string>
#include <random>

#include "item.h"

class Participant {
public:
	virtual ~Participant() = default;
	virtual std::string printName() = 0;
	virtual bool getParticipantHand() = 0;
	
	std::unique_ptr<Item> hand_;
	int64_t tally_ = 0;
};

class Player : public Participant {
public:
	std::string printName() override {
		return "Player";
	}
	
	bool getParticipantHand() override {
		std::cout << "Enter your choice " << choice();
		char choice;
		std::cin >> choice;
		hand_ = itemFromChar(choice);
		if (hand_ == nullptr)
			return false;
		return true;
	}
};

class Computer : public Participant {
public:
	std::string printName() override {
		return "Computer";
	}
	
	bool getParticipantHand() override {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(1, numberOfElements);
		int i = distr(gen);
		hand_ = itemFromInt(i);
		return true;
	}
};

#endif /* player_h */
