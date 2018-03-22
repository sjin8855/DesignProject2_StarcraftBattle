#include "UnitFactory.h"

UnitFactory::UnitFactory()
{

}

Unit* UnitFactory::createUnit(int type) // 유닛 생산
{
	Unit* unit = new Unit();
	VehicleType *vehicleType;
	Splashable *splashable;
	Attackbehavior *attackbehavior;

	switch (type)
	{
	case 1: // 질럿
		vehicleType = new Ground();
		splashable = new Nosplash();
		attackbehavior = new Army();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(1);
		unit->set_name("질럿");
		unit->set_healthPoint(100);
		unit->set_offence(8);
		unit->set_defende(3);
		return unit;
		break;

	case 2: // 해병
		vehicleType = new Ground();
		splashable = new Nosplash();
		attackbehavior = new Complex();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(2);
		unit->set_name("해병");
		unit->set_healthPoint(40);
		unit->set_offence(6);
		unit->set_defende(1);
		return unit;
		break;

	case 3: // 히드라
		vehicleType = new Ground();
		splashable = new Nosplash();
		attackbehavior = new Complex();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(3);
		unit->set_name("히드라");
		unit->set_healthPoint(80);
		unit->set_offence(10);
		unit->set_defende(1);
		return unit;
		break;

	case 4:// 아콘
		vehicleType = new Ground();
		splashable = new Splash();
		attackbehavior = new Complex();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(4);
		unit->set_name("아콘");
		unit->set_healthPoint(250);
		unit->set_offence(30);
		unit->set_defende(1);
		return unit;
		break;

	case 5://  스카우트
		vehicleType = new Sky();
		splashable = new Nosplash();
		attackbehavior = new Complex();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(5);
		unit->set_name("스카우트");
		unit->set_healthPoint(150);
		unit->set_offence(12);
		unit->set_defende(2);
		return unit;
		break;

	case 6: // 가디언
		vehicleType = new Sky();
		splashable = new Nosplash();
		attackbehavior = new Army();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(6);
		unit->set_name("가디언");
		unit->set_healthPoint(150);
		unit->set_offence(20);
		unit->set_defende(2);
		return unit;
		break;

	case 7: // 발키리
		vehicleType = new Sky();
		splashable = new Splash();
		attackbehavior = new AirForce();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(7);
		unit->set_name("발키리");
		unit->set_healthPoint(200);
		unit->set_offence(10);
		unit->set_defende(2);
		return unit;
		break;
	}
}


Unit* UnitFactory::createUnit(char type) // 유닛 생산
{
	Unit* unit = new Unit();
	VehicleType *vehicleType;
	Splashable *splashable;
	Attackbehavior *attackbehavior;

	switch (type)
	{
	case '1': // 질럿
		vehicleType = new Ground();
		splashable = new Nosplash();
		attackbehavior = new Army();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(1);
		unit->set_name("질럿");
		unit->set_healthPoint(100);
		unit->set_offence(8);
		unit->set_defende(3);
		return unit;
		break;

	case '2': // 해병
		vehicleType = new Ground();
		splashable = new Nosplash();
		attackbehavior = new Complex();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(2);
		unit->set_name("해병");
		unit->set_healthPoint(40);
		unit->set_offence(6);
		unit->set_defende(1);
		return unit;
		break;

	case '3': // 히드라
		vehicleType = new Ground();
		splashable = new Nosplash();
		attackbehavior = new Complex();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(3);
		unit->set_name("히드라");
		unit->set_healthPoint(80);
		unit->set_offence(10);
		unit->set_defende(1);
		return unit;
		break;

	case '4':// 아콘
		vehicleType = new Ground();
		splashable = new Splash();
		attackbehavior = new Complex();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(4);
		unit->set_name("아콘");
		unit->set_healthPoint(250);
		unit->set_offence(30);
		unit->set_defende(1);
		return unit;
		break;

	case '5'://  스카우트
		vehicleType = new Sky();
		splashable = new Nosplash();
		attackbehavior = new Complex();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(5);
		unit->set_name("스카우트");
		unit->set_healthPoint(150);
		unit->set_offence(12);
		unit->set_defende(2);
		return unit;
		break;

	case '6': // 가디언
		vehicleType = new Sky();
		splashable = new Nosplash();
		attackbehavior = new Army();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(6);
		unit->set_name("가디언");
		unit->set_healthPoint(150);
		unit->set_offence(20);
		unit->set_defende(2);
		return unit;
		break;

	case '7': // 발키리
		vehicleType = new Sky();
		splashable = new Splash();
		attackbehavior = new AirForce();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(7);
		unit->set_name("발키리");
		unit->set_healthPoint(200);
		unit->set_offence(10);
		unit->set_defende(2);
		return unit;
		break;
	}
}