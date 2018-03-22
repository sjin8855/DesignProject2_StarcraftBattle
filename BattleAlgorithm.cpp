#include"BattleAlgorithm.h"

// 생성자 만들필요 없음
BattleAlgorithm::BattleAlgorithm()
{

}

// 데미지 계산 Attacker.offence - Defender.defense
int BattleAlgorithm::EstimateDamage(Unit &Attacker, Unit &Defender)
{
	int damage = Attacker.get_offence() - Defender.get_defende();
	
	return damage;
}