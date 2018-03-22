#include"Unit.h"

Unit::Unit()
{
	vehicleType = NULL;
	splashable = NULL;
	attackbehavior = NULL;

	offence = 0;
	defende = 0;
	healthPoint = 0;
	name = "";
	id = 0;
}




string Unit::performVehicleType()  // 이동 "지상""공중"
{
	return vehicleType->get_vehicle();
}

string Unit::performAttackBehavior()  // 공격가능한 형태 "지상""공중""지상&공중"
{
	return attackbehavior->get_attack();
}

string Unit::performSplashable()	// 스플래쉬 있음,없음
{
	return splashable->get_splashable();
}

void Unit::receiveDamage(int _damage)	// 받는 데미지
{
	healthPoint -= _damage;	// Defender의 체력에서 damage만큼 감소 시킨다.
}





int Unit::get_damage()	// 데미지 리턴
{
	return damage;
}
	
int Unit::get_offence()   //	공격력 리턴
{
	return offence;
}

int Unit::get_defende()   //	방어력 리턴
{
	return defende;
}

int Unit::get_healthPoint()   //체력 리턴
{
	return healthPoint;
}

string Unit::get_name()   // 이름 리턴
{
	return name;
}

int Unit::get_id()   //아이디 리턴
{
	return id;
}

void Unit::set_damage(int _damage)   // 데미지 입력
{
	damage = _damage;
}

void Unit::set_offence(int _offence)   // 공격력 입력
{
	offence = _offence;
}

void Unit::set_defende(int _defende)   // 방어력 입력
{
	defende = _defende;
}

void Unit::set_healthPoint(int _healthPoint)   // 체력 입력
{
	healthPoint = _healthPoint;
}

void Unit::set_name(string _name)   // 이름 입력
{
	name = _name;
}

void Unit::set_id(int _id)   // 아이디 입력
{
	id = _id;
}






// 스트레티지 패턴
	
void Unit::set_vehicleType(VehicleType &_vehicleType)
{
	vehicleType = &_vehicleType;
}

void Unit::set_splashable(Splashable &_splashable)
{
	splashable = &_splashable;
}

void Unit::set_attackbehavior(Attackbehavior &_attackbehavior)
{
	attackbehavior = &_attackbehavior;
}
