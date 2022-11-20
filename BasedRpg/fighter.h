#pragma once
#include <string>

class fighter {
public:
	fighter(std::string m_name, int m_hp, int m_mp, int m_armor, int m_magicArmor);
	~fighter();
	std::string m_name = "Not set";
	int m_hitPoints = 0;
	int m_magicPoints = 0;
	int m_armor = 0;
	int m_magicArmor = 0;
};