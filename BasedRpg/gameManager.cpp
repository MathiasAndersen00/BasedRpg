#include "gameManager.h"
#include <string>
#include <iostream>
#include <memory>

void GameManager::startGame()
{
	int playerCount;
	std::cout << "BasedRpg v1.0" << "\n---------------" << "\n\nEnter number of players: ";
	std::cin >> playerCount;
	std::cout << "Initializing " << playerCount << " players ..." << "\n\n---------------\n";

	for (int x = 0; x < playerCount; x++)
	{
		std::string name = "";
		int pClass = 0;
		int hp = 0;
		int mp = 0;
		int armor = 0;
		int magicArmor = 0;

		std::cout << "Player Classes:" << "\n 1 - Wizard" << "\n 2 - Troll" << "\n 3 - Assassin"
			<< "\nPick player " << x + 1 << "`s class : ";
		std::cin >> pClass;
		std::cout << "\nWrite player " << x + 1 << "`s name: ";
		std::cin >> name;
		std::cout << "\n\n---------------\n\n";

		if (pClass == 1) { hp = 80; mp = 200; armor = 5; magicArmor = 20; }
		else if (pClass == 2) { hp = 200; mp = 0; armor = 20; magicArmor = 0; }
		else if (pClass == 3) { hp = 120; mp = 50; armor = 10; magicArmor = 10; }

		players.insert(players.begin() + x, std::make_shared<playerCharacter>(name, hp, mp, armor, magicArmor));

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
	}
}

void GameManager::run()
{
	bool gameRunning = true;
	int roundCount = 1;

	while (gameRunning)
	{
		std::cout << "Round " << roundCount << " - player stats: \n";

		for (int x = 0; x < players.size(); x++)
		{
			std::cout << " " << getPlayer(x)->getName() << " (#" << x + 1 << "): " << getPlayer(x)->getHp() << " HP\n\n";
		}

		std::cout << "Actions:\n" << " 1 - Attack\n 2 - Dodge\n\n";

		for (int j = 0; j < players.size(); j++)
		{
			int action = 0;
			int target = 0;
			std::cout << getPlayer(j)->getName() << " (#" << j + 1 << "), pick an action: ";
			std::cin >> action;
			if (action == 1)
			{
				std::cout << "Targets\n";
				for (int i = 0; i < players.size(); i++)
				{
					if (i != j) { std::cout << " " << i+1 << " - " << getPlayer(i)->getName() << "\n\n"; }
				}
				std::cout << getPlayer(j)->getName() << " (#" << j + 1 << "), pick your target: ";
				std::cin >> target;
			}
			getPlayer(j)->runTurn(target, action);
		}

		for (int x = 0; x < players.size(); x++)
		{
			int action = getPlayer(x)->getAction();
			int target = getPlayer(x)->getTarget();

			if (action == 1)
			{
				if (getPlayer(target - 1)->getAction() == 1)
				{
					std::cout << getPlayer(x)->getName() << " attacked " << getPlayer(target - 1)->getName() << " for x damage.\n";
				}
				else if (getPlayer(target - 1)->getAction() == 2)
				{
					std::cout << getPlayer(x)->getName() << " attacked " << getPlayer(target - 1)->getName() << ", but failed.\n";
				}
			}
			if (action == 2)
			{
				int attacksTargetingPlayer = 0;
				for (int i = 0; i < players.size(); i++)
				{
					if (i != x && getPlayer(i)->getTarget() - 1 == x) { attacksTargetingPlayer++; }
				}
				if (attacksTargetingPlayer == 0) { std::cout << getPlayer(x)->getName() << " dodged.\n"; }
				else if (attacksTargetingPlayer == 1) { std::cout << getPlayer(x)->getName() << " dodged an attack.\n"; }
				else if (attacksTargetingPlayer > 1) { std::cout << getPlayer(x)->getName() << " dodged multiple attacks.\n"; }
			}
		}
		gameRunning = false;
	}
}

playerCharacter* GameManager::getPlayer(int playerTurn)
{
	return players.at(playerTurn).get();
}
