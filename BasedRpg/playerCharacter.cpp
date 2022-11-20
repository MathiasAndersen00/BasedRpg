#include "playerCharacter.h"

playerCharacter::playerCharacter(std::string name, int hp, int mp, int armor, int magicArmor) :
	m_name(name),
	m_hitPoints(hp),
	m_magicPoints(mp),
	m_armor(armor),
	m_magicArmor(magicArmor) 
{

}

playerCharacter::~playerCharacter()
{
}

void playerCharacter::runTurn(int target, int action)
{
	m_target = target;
	m_action = action;
}

std::string playerCharacter::getName()
{
	return m_name;
}

int playerCharacter::getHp()
{
	return m_hitPoints;
}

int playerCharacter::getTarget()
{
	return m_target;
}

int playerCharacter::getAction()
{
	return m_action;
}
