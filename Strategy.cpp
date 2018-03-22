#include"Strategy.h"

//-----------------------------------------지상, 공중
Ground::Ground()
{
	vehicle();
}

void Ground::vehicle()
{
	m_vehicle = "지상";
}

Sky::Sky()
{
	vehicle();
}

void Sky::vehicle()
{
	m_vehicle = "공중";
}

//-----------------------------------------스플래쉬 데미지


string Splashable::get_splashable()
{
	return m_splashable;
}

Splash::Splash()
{
	splash();
}

void Splash::splash()
{
	m_splashable = "있음";
}

Nosplash::Nosplash()
{
	splash();
}

void Nosplash::splash()
{
	m_splashable = "없음";
}


//-----------------------------------------공격

string Attackbehavior::get_attack()
{
	return m_attack;
}

void Attackbehavior::attack_damage(Unit &Attacker, Unit &Defender)
{
	int damage = BattleAlgorithm::EstimateDamage(Attacker, Defender);       //  데미지를 계산한다.

	Defender.receiveDamage(damage);    // 데미지 만큼 Defender의 체력이 감소된다.   
}

void Attackbehavior::splash_damage(Unit &Attacker, vector<Unit>& Defender, vector<int> _list/*int pos*/)
{
	srand(time(NULL));
	int damage;
	int size = _list.size();
	int ran_num;
	int ran;
	int q;

	if(size!=0)
		ran_num = rand()%size;

	if(size == 0)
		return ;

	else if(size == 1)
	{
		q = Defender.at(_list.at(0)).get_healthPoint();
		damage = (Attacker.get_offence() - Defender.at(_list.at(0)).get_defende())*0.5;
		Defender.at(_list.at(0)).receiveDamage(damage);
		cout<<endl<<"\t"<<Defender.at(_list.at(0)).get_name()<<"이(가) 스플레시 데미지를 입었습니다"<<endl;
		cout<<"\t"<<Defender.at(_list.at(0)).get_name()<<" 방어력 : "<<Defender.at(_list.at(0)).get_defende()<<endl;
		cout<<"\t입은데미지 : "<<damage<<endl;
		if(Defender.at(_list.at(0)).get_healthPoint()<=0)
			cout<<"\t"<<Defender.at(_list.at(0)).get_name()<<"체력 : "<<q<<"->"<<"사망"<<endl;
	
		else
			cout<<"\t"<<Defender.at(_list.at(0)).get_name()<<"체력 : "<<q<<"->"<<Defender.at(_list.at(0)).get_healthPoint()<<endl;
		
		
		return ;
	}

	else if(size == 2)
	{
		q = Defender.at(_list.at(0)).get_healthPoint();
		damage = (Attacker.get_offence() - Defender.at(_list.at(0)).get_defende())*0.5;
		Defender.at(_list.at(0)).receiveDamage(damage);
		cout<<endl<<"\t"<<Defender.at(_list.at(0)).get_name()<<"이(가) 스플레시 데미지를 입었습니다"<<endl;
		cout<<"\t"<<Defender.at(_list.at(0)).get_name()<<" 방어력 : "<<Defender.at(_list.at(0)).get_defende()<<endl;
		cout<<"\t입은데미지 : "<<damage<<endl;
		if(Defender.at(_list.at(0)).get_healthPoint()<=0)
			cout<<"\t"<<Defender.at(_list.at(0)).get_name()<<"체력 : "<<q<<"->"<<"사망"<<endl;
		else
			cout<<"\t"<<Defender.at(_list.at(0)).get_name()<<"체력 : "<<q<<"->"<<Defender.at(_list.at(0)).get_healthPoint()<<endl;
		
		q = Defender.at(_list.at(1)).get_healthPoint();
		damage = (Attacker.get_offence() - Defender.at(_list.at(1)).get_defende())*0.5;
		Defender.at(_list.at(1)).receiveDamage(damage);
		cout<<endl<<"\t"<<Defender.at(_list.at(1)).get_name()<<"이(가) 스플레시 데미지를 입었습니다"<<endl;
		cout<<"\t"<<Defender.at(_list.at(1)).get_name()<<" 방어력 : "<<Defender.at(_list.at(1)).get_defende()<<endl;
		cout<<"\t입은데미지 : "<<damage<<endl;
		if(Defender.at(_list.at(1)).get_healthPoint()<=0)
			cout<<"\t"<<Defender.at(_list.at(1)).get_name()<<"체력 : "<<q<<"->"<<"사망"<<endl;
		else
			cout<<"\t"<<Defender.at(_list.at(1)).get_name()<<"체력 : "<<q<<"->"<<Defender.at(_list.at(1)).get_healthPoint()<<endl;
		
		return ;
	}

	else if(size > 2)
	{
		q = Defender.at(_list.at(ran_num)).get_healthPoint();
		damage = (Attacker.get_offence() - Defender.at(_list.at(ran_num)).get_defende())*0.5;
		Defender.at(_list.at(ran_num)).receiveDamage(damage);
		cout<<endl<<"\t"<<Defender.at(_list.at(ran_num)).get_name()<<"이(가) 스플레시 데미지를 입었습니다"<<endl;
		cout<<"\t"<<Defender.at(_list.at(ran_num)).get_name()<<" 방어력 : "<<Defender.at(_list.at(ran_num)).get_defende()<<endl;
		cout<<"\t입은데미지 : "<<damage<<endl;
		if(Defender.at(_list.at(ran_num)).get_healthPoint()<=0)
			cout<<"\t"<<Defender.at(_list.at(ran_num)).get_name()<<"체력 : "<<q<<"->"<<"사망"<<endl;
		else
			cout<<"\t"<<Defender.at(_list.at(ran_num)).get_name()<<"체력 : "<<q<<"->"<<Defender.at(_list.at(ran_num)).get_healthPoint()<<endl;
		
		
		ran = ran_num;
		while(true)
		{
			if(ran_num==ran)
				ran_num = rand()%size;
			else
				break;
		}
	
		

		q = Defender.at(_list.at(ran_num)).get_healthPoint();
		damage = (Attacker.get_offence() - Defender.at(_list.at(ran_num)).get_defende())*0.5;
		Defender.at(_list.at(ran_num)).receiveDamage(damage);
		cout<<endl<<"\t"<<Defender.at(_list.at(ran_num)).get_name()<<"이(가) 스플레시 데미지를 입었습니다"<<endl;
		cout<<"\t"<<Defender.at(_list.at(ran_num)).get_name()<<" 방어력 : "<<Defender.at(_list.at(ran_num)).get_defende()<<endl;
		cout<<"\t입은데미지 : "<<damage<<endl;
		if(Defender.at(_list.at(ran_num)).get_healthPoint()<=0)
			cout<<"\t"<<Defender.at(_list.at(ran_num)).get_name()<<"체력 : "<<q<<"->"<<"사망"<<endl;
		else
			cout<<"\t"<<Defender.at(_list.at(ran_num)).get_name()<<"체력 : "<<q<<"->"<<Defender.at(_list.at(ran_num)).get_healthPoint()<<endl;
		
		
		return ;
	}
}

Army::Army()
{
	attack();
}

void Army::attack()
{
	m_attack = "지상";
}


AirForce::AirForce()
{
	attack();
}

void AirForce::attack()
{
	m_attack = "공중";
}

Complex::Complex()
{
	attack();
}

void Complex::attack()
{
	m_attack = "지상&공중";
}

