#pragma once
#include "Unit.h"
class Unit;

class BattleAlgorithm
{
private:	// 생성자 만들필요 없음
	BattleAlgorithm();
public:
	static int EstimateDamage(Unit &Attacker, Unit &Defender); // 데미지 계산 Attacker.offence - Defender.defense
	
};

