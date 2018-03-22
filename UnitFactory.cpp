#include "UnitFactory.h"

UnitFactory::UnitFactory()
{

}

Unit* UnitFactory::createUnit(int type) // ���� ����
{
	Unit* unit = new Unit();
	VehicleType *vehicleType;
	Splashable *splashable;
	Attackbehavior *attackbehavior;

	switch (type)
	{
	case 1: // ����
		vehicleType = new Ground();
		splashable = new Nosplash();
		attackbehavior = new Army();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(1);
		unit->set_name("����");
		unit->set_healthPoint(100);
		unit->set_offence(8);
		unit->set_defende(3);
		return unit;
		break;

	case 2: // �غ�
		vehicleType = new Ground();
		splashable = new Nosplash();
		attackbehavior = new Complex();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(2);
		unit->set_name("�غ�");
		unit->set_healthPoint(40);
		unit->set_offence(6);
		unit->set_defende(1);
		return unit;
		break;

	case 3: // �����
		vehicleType = new Ground();
		splashable = new Nosplash();
		attackbehavior = new Complex();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(3);
		unit->set_name("�����");
		unit->set_healthPoint(80);
		unit->set_offence(10);
		unit->set_defende(1);
		return unit;
		break;

	case 4:// ����
		vehicleType = new Ground();
		splashable = new Splash();
		attackbehavior = new Complex();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(4);
		unit->set_name("����");
		unit->set_healthPoint(250);
		unit->set_offence(30);
		unit->set_defende(1);
		return unit;
		break;

	case 5://  ��ī��Ʈ
		vehicleType = new Sky();
		splashable = new Nosplash();
		attackbehavior = new Complex();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(5);
		unit->set_name("��ī��Ʈ");
		unit->set_healthPoint(150);
		unit->set_offence(12);
		unit->set_defende(2);
		return unit;
		break;

	case 6: // �����
		vehicleType = new Sky();
		splashable = new Nosplash();
		attackbehavior = new Army();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(6);
		unit->set_name("�����");
		unit->set_healthPoint(150);
		unit->set_offence(20);
		unit->set_defende(2);
		return unit;
		break;

	case 7: // ��Ű��
		vehicleType = new Sky();
		splashable = new Splash();
		attackbehavior = new AirForce();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(7);
		unit->set_name("��Ű��");
		unit->set_healthPoint(200);
		unit->set_offence(10);
		unit->set_defende(2);
		return unit;
		break;
	}
}


Unit* UnitFactory::createUnit(char type) // ���� ����
{
	Unit* unit = new Unit();
	VehicleType *vehicleType;
	Splashable *splashable;
	Attackbehavior *attackbehavior;

	switch (type)
	{
	case '1': // ����
		vehicleType = new Ground();
		splashable = new Nosplash();
		attackbehavior = new Army();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(1);
		unit->set_name("����");
		unit->set_healthPoint(100);
		unit->set_offence(8);
		unit->set_defende(3);
		return unit;
		break;

	case '2': // �غ�
		vehicleType = new Ground();
		splashable = new Nosplash();
		attackbehavior = new Complex();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(2);
		unit->set_name("�غ�");
		unit->set_healthPoint(40);
		unit->set_offence(6);
		unit->set_defende(1);
		return unit;
		break;

	case '3': // �����
		vehicleType = new Ground();
		splashable = new Nosplash();
		attackbehavior = new Complex();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(3);
		unit->set_name("�����");
		unit->set_healthPoint(80);
		unit->set_offence(10);
		unit->set_defende(1);
		return unit;
		break;

	case '4':// ����
		vehicleType = new Ground();
		splashable = new Splash();
		attackbehavior = new Complex();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(4);
		unit->set_name("����");
		unit->set_healthPoint(250);
		unit->set_offence(30);
		unit->set_defende(1);
		return unit;
		break;

	case '5'://  ��ī��Ʈ
		vehicleType = new Sky();
		splashable = new Nosplash();
		attackbehavior = new Complex();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(5);
		unit->set_name("��ī��Ʈ");
		unit->set_healthPoint(150);
		unit->set_offence(12);
		unit->set_defende(2);
		return unit;
		break;

	case '6': // �����
		vehicleType = new Sky();
		splashable = new Nosplash();
		attackbehavior = new Army();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(6);
		unit->set_name("�����");
		unit->set_healthPoint(150);
		unit->set_offence(20);
		unit->set_defende(2);
		return unit;
		break;

	case '7': // ��Ű��
		vehicleType = new Sky();
		splashable = new Splash();
		attackbehavior = new AirForce();

		unit->set_vehicleType(*vehicleType);
		unit->set_splashable(*splashable);
		unit->set_attackbehavior(*attackbehavior);
		unit->set_id(7);
		unit->set_name("��Ű��");
		unit->set_healthPoint(200);
		unit->set_offence(10);
		unit->set_defende(2);
		return unit;
		break;
	}
}