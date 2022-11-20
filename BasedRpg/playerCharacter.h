#pragma once

#include <string>

class playerCharacter {
private:
	std::string m_name = "Not set";
	int m_hitPoints = 0;
	int m_magicPoints = 0;
	int m_armor = 0;
	int m_magicArmor = 0;
	int m_target = 0;
	int m_action = 0;
public:
	playerCharacter(std::string m_name, int m_hp, int m_mp, int m_armor, int m_magicArmor);
	~playerCharacter();
	void runTurn(int target, int action);
	std::string getName();
	int getHp();
	int getTarget();
	int getAction();
};