#pragma once
#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include "Unit.h"
#include "BattleAlgorithm.h"
#include <ctime>
class Unit;
class BattleAlgorithm;
//-----------------------------------------지상, 공중
class VehicleType
{
public:
	VehicleType(){};
	virtual void vehicle() = 0;
	string get_vehicle()
	{
		return m_vehicle;
	};
protected:
	string m_vehicle;
};

class Ground : public VehicleType
{
public:
	Ground()/*{}*/;
	void vehicle();
};

class Sky : public VehicleType
{
public:
	Sky()/*{}*/;
	void vehicle();
};

//-----------------------------------------스플래쉬 데미지

class Splashable
{
public:
	Splashable(){};
	virtual void splash() = 0;
	string get_splashable();
protected:
	string m_splashable;
};

class Splash:public Splashable
{
public:
	Splash()/*{}*/;
	void splash();
};

class Nosplash :public Splashable
{
public:
	Nosplash()/*{}*/;
	void splash();
};

//-----------------------------------------공격


class Attackbehavior
{
public:
	Attackbehavior(){};
	virtual void attack() = 0;
	string get_attack();
	void attack_damage(Unit &Attacker, Unit &Defender);
	void splash_damage(Unit &Attacker, vector<Unit>& Defender, vector<int> _list/*int pos*/); 
protected:
	string m_attack;
};

class Army :public Attackbehavior
{
public:
	Army()/*{}*/;
	void attack();
};

class AirForce :public Attackbehavior
{
public:
	AirForce()/*{}*/;
	void attack();
};

class Complex :public Attackbehavior
{
public:
	Complex()/*{}*/;
	void attack();
};
