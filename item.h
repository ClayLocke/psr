#ifndef item_h
#define item_h

#include <iostream>
#include <memory>
#include <string>

// additional elements can be added to this header, i.e. Scissors Paper Rock Spock Lizard
// update number of elements as well as what elements it beats (1) or is beaten by (-1)

class Scissors;
class Paper;
class Rock;
static int numberOfElements = 3;

class Item {
public:
	virtual ~Item() = default;

	virtual uint32_t compare(Item&) = 0;
	virtual uint32_t vs(Scissors&) = 0;
	virtual uint32_t vs(Paper&) = 0;
	virtual uint32_t vs(Rock&) = 0;
	
	virtual std::string printName() = 0;
};

class Scissors : public Item {
	uint32_t compare(Item& i) override {return i.vs(*this);}
	uint32_t vs(Scissors&) override {return 0;}
	uint32_t vs(Paper&) override {return 1;}
	uint32_t vs(Rock&) override {return -1;}
	
	std::string printName() override {return "Scissors";}
};

class Paper : public Item {
	uint32_t compare(Item& i) override {return i.vs(*this);}
	uint32_t vs(Scissors&) override {return -1;}
	uint32_t vs(Paper&) override {return 0;}
	uint32_t vs(Rock&) override {return 1;}
	
	std::string printName() override {return "Paper";}
};

class Rock : public Item {
	uint32_t compare(Item& i) override {return i.vs(*this);}
	uint32_t vs(Scissors&) override {return 1;}
	uint32_t vs(Paper&) override {return -1;}
	uint32_t vs(Rock&) override {return 0;}
	
	std::string printName() override {return "Rock";}
};

inline std::string choice() {
	return "(p/s/r)";
}

inline std::unique_ptr<Item> itemFromInt(int i) {
	switch (i) {
	case 1 :
 		return std::make_unique<Scissors>();
	case 2 :
 		return std::make_unique<Paper>();
	case 3 :
	 	return std::make_unique<Rock>();
	}
	return std::make_unique<Rock>();
};

inline std::unique_ptr<Item> itemFromChar(char c) {
	switch (c) {
		case ('s') :
			return std::make_unique<Scissors>();
		case ('p') :
			return std::make_unique<Paper>();
		case ('r') :
			return std::make_unique<Rock>();
	}
	return nullptr;
};

#endif
