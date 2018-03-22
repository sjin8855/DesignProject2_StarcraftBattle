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




string Unit::performVehicleType()  // �̵� "����""����"
{
	return vehicleType->get_vehicle();
}

string Unit::performAttackBehavior()  // ���ݰ����� ���� "����""����""����&����"
{
	return attackbehavior->get_attack();
}

string Unit::performSplashable()	// ���÷��� ����,����
{
	return splashable->get_splashable();
}

void Unit::receiveDamage(int _damage)	// �޴� ������
{
	healthPoint -= _damage;	// Defender�� ü�¿��� damage��ŭ ���� ��Ų��.
}





int Unit::get_damage()	// ������ ����
{
	return damage;
}
	
int Unit::get_offence()   //	���ݷ� ����
{
	return offence;
}

int Unit::get_defende()   //	���� ����
{
	return defende;
}

int Unit::get_healthPoint()   //ü�� ����
{
	return healthPoint;
}

string Unit::get_name()   // �̸� ����
{
	return name;
}

int Unit::get_id()   //���̵� ����
{
	return id;
}

void Unit::set_damage(int _damage)   // ������ �Է�
{
	damage = _damage;
}

void Unit::set_offence(int _offence)   // ���ݷ� �Է�
{
	offence = _offence;
}

void Unit::set_defende(int _defende)   // ���� �Է�
{
	defende = _defende;
}

void Unit::set_healthPoint(int _healthPoint)   // ü�� �Է�
{
	healthPoint = _healthPoint;
}

void Unit::set_name(string _name)   // �̸� �Է�
{
	name = _name;
}

void Unit::set_id(int _id)   // ���̵� �Է�
{
	id = _id;
}






// ��Ʈ��Ƽ�� ����
	
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
