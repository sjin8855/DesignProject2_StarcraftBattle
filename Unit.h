#pragma once
#include <iostream>
#include <string>
#include "Strategy.h"
using namespace std;

class VehicleType;
class Ground;
class Sky;

class Splashable;
class Splash;
class Nosplash;

class Attackbehavior;
class Army;
class AirForce;
class Complex;

class Unit
{
public:
	Unit();

public:
	string performVehicleType();  // �̵� "����""����"
	string performAttackBehavior();  // ���ݰ����� ���� "����""����""����&����"
	string performSplashable();	// ���÷��� ����,����
	void receiveDamage(int _damage);	// �޴� ������

public:
	int get_damage();	// ������ ����
	int get_offence();	// ���ݷ� ����
	int get_defende();  //���� ����
	int get_healthPoint();   //ü�� ����
	string get_name();   // �̸� ����
	void set_damage(int _damage);   // ������ �Է�
	void set_offence(int _offence);
	void set_defende(int _defende);   // ���� �Է�
	void set_healthPoint(int _healthPoint);   // ü�� �Է�
	void set_name(string _name);   // �̸� �Է�
	void set_id(int _id);   // ���̵� �Է�
	int get_id();   //���̵� ����

public:// ��Ʈ��Ƽ�� ����
	//&���� *�� �ٲ�
	void set_vehicleType(VehicleType &_vehicleType); 
	void set_splashable(Splashable &_splashable);
	void set_attackbehavior(Attackbehavior &_attackbehavior);

	Attackbehavior* get_attackbehavior()
	{
		return attackbehavior;
	}

private:
	VehicleType *vehicleType;
	Splashable *splashable;
	Attackbehavior *attackbehavior;

	int damage;	//������(���� �߰�)
	int offence; // ���ݷ�
	int defende;  // ����
	int healthPoint;  // ü��
	string name;  // �̸�
	int id;// ���̵�
};

