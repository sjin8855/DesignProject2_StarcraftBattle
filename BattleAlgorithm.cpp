#include"BattleAlgorithm.h"

// ������ �����ʿ� ����
BattleAlgorithm::BattleAlgorithm()
{

}

// ������ ��� Attacker.offence - Defender.defense
int BattleAlgorithm::EstimateDamage(Unit &Attacker, Unit &Defender)
{
	int damage = Attacker.get_offence() - Defender.get_defende();
	
	return damage;
}