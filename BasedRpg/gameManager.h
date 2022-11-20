#pragma once

#include <memory>
#include <vector>
#include "playerCharacter.h"

class GameManager {
private:
	std::vector<std::shared_ptr<playerCharacter>> players{};
	playerCharacter* getPlayer(int playerTurn);
public:
	void startGame();
	void run();
};