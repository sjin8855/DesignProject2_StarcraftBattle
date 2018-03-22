#include"StarCraft.h"

StarCraft::StarCraft()
{
	srand(time(NULL));
	unit = NULL;
	splash_pos =0;
}

// turnBattle 관련 함수 모음
void StarCraft::turnBattle()	// 아군 vs 적군 싸움
{
	Unit* ally;
	Unit* enemy;
	bool check = true;
	int attack_count = 0;
	int ally_count = 0;
	int enemy_count = 0;
	string attack_count_name[2];
	bool arr[2] = {false};
	vector<Unit>::iterator start;
	int vec_count = 0;
	int ran_num = 0;
	bool n_check = false;
	vector<int> _list;
	int q;
	int current_pos = 0;
	/*if(list_ally_unit.size()!=0)
	unit = &list_ally_unit.at(0);
	else
	{
	cout<<"아군 병력이 없습니다."<<endl;
	return ;
	}*/

	while (list_ally_unit.size() !=0 && list_enemy_unit.size() !=0) // 아군이 전멸하거나 적군이 전멸할 때 까지 반복
	{
		current_pos = 0;
		_list.clear();
		if(check)	// 
		{
			unit = randomAlly();	// 아군 랜덤 선택
			/*if(unit == NULL)
			unit = &list_ally_unit.at(0);*/
			if(unit == NULL)
			{
				for(start = list_ally_unit.begin(); start!=list_ally_unit.end(); start++)
					vec_count++;
				if(vec_count!=0)
					ran_num = rand()%vec_count;
				unit = &list_ally_unit.at(ran_num);
				ran_num = 0;
				vec_count = 0;
			}
			enemy = randomEnemy();	// 적군 랜덤 선택 

			/*if(unit!=NULL)
			{
			for(start = list_ally_unit.begin(); start!=list_ally_unit.end(); start++)
			{
			if(unit->get_id()==start->get_id())
			break;
			vec_count++;
			}

			unit = &list_ally_unit.at(vec_count);
			vec_count = 0;
			}

			if(enemy!=NULL)
			{
			for(start = list_enemy_unit.begin(); start!=list_enemy_unit.end(); start++)
			{
			if(enemy->get_id()==start->get_id())
			break;
			vec_count++;
			}
			enemy = &list_enemy_unit.at(vec_count);
			vec_count = 0;
			}*/

			if(enemy != NULL)
			{	
				q = enemy->get_healthPoint();
				cout<<"\t아군유닛 "<<unit->get_name()<<"이(가) "<<enemy->get_name()<<"을(를) 공격하였습니다."<<endl;
				cout<<"\t"<<unit->get_name()<<" 공격력 : "<<unit->get_offence()<<endl;
				cout<<"\t"<<enemy->get_name()<<" 방어력 : "<<enemy->get_defende()<<endl;
				cout<<"\t입은 데미지 : "<<unit->get_offence()-enemy->get_defende()<<endl;
					
				unit ->get_attackbehavior()->attack_damage(*unit, *enemy); // ally가 enemy를 공격한다.
				if(enemy->get_healthPoint()<=0)
					cout<<"\t"<<enemy->get_name()<<" 체력 : "<<q<<"->"<<"사망"<<endl;
				else
					cout<<"\t"<<enemy->get_name()<<" 체력 : "<<q<<"->"<<enemy->get_healthPoint()<<endl;
				
				
				for(vector<Unit>::iterator p = list_enemy_unit.begin(); p!=list_enemy_unit.end(); p++)
				{
					if(p->get_name() == enemy->get_name())
					{
						if(p->get_healthPoint() == enemy->get_healthPoint())
							break;
					}
					current_pos++;
				}

				/*for(vector<Unit>::iterator def = list_defender.begin(); def!=list_defender.end(); def++)
				{
					if(enemy->get_name() == def->get_name())
					{
						list_defender.erase(def);
						break;
					}
				}*/

				for(vector<Unit>::iterator de_start = list_defender.begin(); de_start!=list_defender.end(); de_start++)
				{
					if(de_start->get_name() == enemy->get_name())
					{
						if(de_start->get_healthPoint() - unit->get_offence() <= 0)
						{
							list_defender.erase(de_start);
							break;
						}
					}
				}


				if (enemy->get_healthPoint() <= 0)    // 공격받은 enemy의 체력이 0이 되면
					eraseEnemy(*enemy);		// list_enemy_unit에서 삭제

				

			}

			else
			{
				cout<<"\t"<<unit->get_name()<<"은 "<<"공격할 수 있는 유닛이 없습니다."<<endl;
				attack_count_name[attack_count] = unit->get_name();
				attack_count++;             // 공격 가능한 유닛이 없다면 무승부 : attack_count가 2 되면 무승부
				enemy_count++;
				for(vector<Unit>::iterator start = list_enemy_unit.begin(); start!=list_enemy_unit.end(); start++)
				{
					for(int i=0; i<2; i++)
					{

						if(start->performVehicleType()=="지상")
						{
							for(vector<Unit>::iterator iter = list_ally_unit.begin(); iter!=list_ally_unit.end(); iter++)
							{
								if(iter->get_attackbehavior()->get_attack()=="지상" || iter->get_attackbehavior()->get_attack()=="지상&공중")
								{
									n_check = true;
									break;
								}
							}
						}

						if(start->performVehicleType()=="공중")
						{
							for(vector<Unit>::iterator iter = list_ally_unit.begin(); iter!=list_ally_unit.end(); iter++)
							{
								if(iter->get_attackbehavior()->get_attack()=="공중" || iter->get_attackbehavior()->get_attack()=="지상&공중")
								{
									n_check = true;
									break;
								}
							}
						}

						if(n_check == true)
						{
							attack_count = 0;
							enemy_count = 0;
							break;
						}

						if(attack_count == 2)
						{
							if(start->get_name() == attack_count_name[i])
							{
								for(int j=0; j<2; j++)
								{
									if(arr[j] == false)
									{
										arr[j] = true;
										if(j==1)
										{
											if(arr[0]==true && arr[1] ==true)
												attack_count = 0;
											break;
	
										}
									}
								}
							}
						}
						/*if(arr[0]==true && arr[1] ==true)
						attack_count = 0;*/
					}

					if(enemy_count == 2)
					{
						attack_count = 0;
						enemy_count = 0;
					}


					/*else if(attack_count_name[attack_count-2] == attack_count_name[attack_count-1])
					attack_count = 0;*/

					else
						break;
				}
			}

			if (unit->performSplashable() == "있음")         // splash가 있다면
			{
				int def_count = 0;

				if(list_defender.size()!=0)
				{
					for(vector<Unit>::iterator def_start = list_defender.begin(); def_start!=list_defender.end(); def_start++)
					{
						for(vector<Unit>::iterator enemy_start = list_enemy_unit.begin(); enemy_start!=list_enemy_unit.end(); enemy_start++)
						{
							if(def_start->get_name() == enemy_start->get_name())
							{
								if(def_count!=current_pos)
								{
									_list.push_back(def_count);
									break;
								}
							}
		
						}
						def_count++;
					}
					
					unit->get_attackbehavior()->splash_damage(*unit, list_enemy_unit, _list);  // ally주변에 스플래쉬 데미지 입힘 
					for(vector<Unit>::iterator enemy_start = list_enemy_unit.begin(); enemy_start!=list_enemy_unit.end(); enemy_start++)
					{
						if (enemy_start->get_healthPoint() <= 0)    // 스플공격받은 enemy의 체력이 0이 되면
						{
							list_enemy_unit.erase(enemy_start);		// list_enemy_unit에서 삭제
							if(list_enemy_unit.size()!=0)
								enemy_start = list_enemy_unit.begin();
							else
								break;
						}
					}
					_list.clear();
				}
			}

			if(arr[0]==true && arr[1] ==true)
				break;

			check = false;                                     // 턴 바꾼다.
			cout<<endl<<"============================================================================="<<endl<<endl;
		}
		//-------------------------------------------------------------------------------------
		else	// 아군공격
		{
			unit = randomEnemy();    // 아군 적군이 위와 반대로 바뀐다.
			/*if(unit == NULL)
			unit = &list_ally_unit.at(0);*/
			if(unit == NULL)
			{
				for(start = list_enemy_unit.begin(); start!=list_enemy_unit.end(); start++)
					vec_count++;
				if(vec_count!=0)
					ran_num = rand()%vec_count;
				unit = &list_enemy_unit.at(ran_num);
				ran_num = 0;
				vec_count = 0;
			}
			enemy = randomAlly(); 

			/*	if(enemy!=NULL)
			{
			for(start = list_ally_unit.begin(); start!=list_ally_unit.end(); start++)
			{
			if(unit->get_id()==start->get_id())
			break;
			vec_count++;
			}

			enemy = &list_ally_unit.at(vec_count);
			vec_count = 0; 
			}

			if(unit!=NULL)
			{
			for(start = list_enemy_unit.begin(); start!=list_enemy_unit.end(); start++)
			{
			if(unit->get_id()==start->get_id())
			break;
			vec_count++;
			}
			unit = &list_enemy_unit.at(vec_count);
			vec_count = 0;
			}*/

			if(enemy != NULL)
			{	
				q = enemy->get_healthPoint();
				cout<<"\t적군유닛 "<<unit->get_name()<<"이(가) "<<enemy->get_name()<<"을(를) 공격하였습니다."<<endl;
				cout<<"\t"<<unit->get_name()<<" 공격력 : "<<unit->get_offence()<<endl;
				cout<<"\t"<<enemy->get_name()<<" 방어력 : "<<enemy->get_defende()<<endl;
				cout<<"\t입은 데미지 : "<<unit->get_offence()-enemy->get_defende()<<endl;
				unit ->get_attackbehavior()->attack_damage(*unit, *enemy); // ally가 enemy를 공격한다.
				if(enemy->get_healthPoint()<=0)
					cout<<"\t"<<enemy->get_name()<<" 체력 : "<<q<<"->"<<"사망"<<endl;
				else
					cout<<"\t"<<enemy->get_name()<<" 체력 : "<<q<<"->"<<enemy->get_healthPoint()<<endl;

				for(vector<Unit>::iterator p = list_ally_unit.begin(); p!=list_ally_unit.end(); p++)
				{
					if(p->get_name() == enemy->get_name())
					{
						if(p->get_healthPoint() == enemy->get_healthPoint())
							break;
					}
					current_pos++;
				}
				
				/*for(vector<Unit>::iterator def = list_defender.begin(); def!=list_defender.end(); def++)
				{
					if(enemy->get_name() == def->get_name())
					{
						list_defender.erase(def);
						break;
					}
				}*/

				for(vector<Unit>::iterator de_start = list_defender.begin(); de_start!=list_defender.end(); de_start++)
				{
					if(de_start->get_name() == enemy->get_name())
					{
						if(de_start->get_healthPoint() - unit->get_offence() <= 0)
						{
							list_defender.erase(de_start);
							break;
						}
					}
				}


				if (enemy->get_healthPoint() <= 0)    // 공격받은 enemy의 체력이 0이 되면
					eraseEnemy(*enemy);                       // list_enemy_unit에서 삭제		
			}

			else
			{
				cout<<"\t"<<unit->get_name()<<"은 "<<"공격할 수 있는 유닛이 없습니다."<<endl;
				attack_count_name[attack_count] = unit->get_name();
				attack_count++;             // 공격 가능한 유닛이 없다면 무승부 : attack_count가 2 되면 무승부
				ally_count++;
				for(vector<Unit>::iterator start = list_ally_unit.begin(); start!=list_ally_unit.end(); start++)
				{
					for(int i=0; i<2; i++)
					{

						if(start->performVehicleType()=="지상")
						{
							for(vector<Unit>::iterator iter = list_enemy_unit.begin(); iter!=list_enemy_unit.end(); iter++)
							{
								if(iter->get_attackbehavior()->get_attack()=="지상" || iter->get_attackbehavior()->get_attack()=="지상&공중")
								{
									n_check = true;
									break;
								}
							}
						}

						if(start->performVehicleType()=="공중")
						{
							for(vector<Unit>::iterator iter = list_enemy_unit.begin(); iter!=list_enemy_unit.end(); iter++)
							{
								if(iter->get_attackbehavior()->get_attack()=="공중" || iter->get_attackbehavior()->get_attack()=="지상&공중")
								{
									n_check = true;
									break;
								}
							}
						}

						if(n_check == true)
						{
							attack_count = 0;
							enemy_count = 0;
							break;
						}
						if(attack_count == 2)
						{

							if(start->get_name() == attack_count_name[i])
							{
								for(int j=0; j<2; j++)
								{
									if(arr[j] == false)
									{
										arr[j] = true;
										if(j==1)
										{
											if(arr[0]==true && arr[1] ==true)
												attack_count = 0;
											break;
										}
									}
								}
							}
						}
						/*if(arr[0]==true && arr[1] ==true)
						attack_count = 0;*/
					}

					/*if(arr[0]==true && arr[1] ==true)
						break;*/

					if(ally_count == 2)
					{
						attack_count = 0;
						ally_count = 0;
					}


					/*else if(attack_count_name[attack_count-2] == attack_count_name[attack_count-1])
					attack_count = 0;*/

					else
						break;
				}
			}

			//if (unit->performSplashable() == "있음")         // splash가 있다면
			//	unit->get_attackbehavior()->splash_damage(*unit, list_defender, splash_pos);  // ally주변에 스플래쉬 데미지 입힘  

			if (unit->performSplashable() == "있음")         // splash가 있다면
			{
				int def_count = 0;

				

				if(list_defender.size()!=0)
				{
					

					for(vector<Unit>::iterator def_start = list_defender.begin(); def_start!=list_defender.end(); def_start++)
					{
						for(vector<Unit>::iterator ally_start = list_ally_unit.begin(); ally_start!=list_ally_unit.end(); ally_start++)
						{
							if(def_start->get_name() == ally_start->get_name())
							{
								if(def_count!=current_pos)
								{
									_list.push_back(def_count);
									break;
								}
							}
							
						}
						def_count++;
					}

					unit->get_attackbehavior()->splash_damage(*unit, list_ally_unit, _list);  // ally주변에 스플래쉬 데미지 입힘 
					for(vector<Unit>::iterator ally_start = list_ally_unit.begin(); ally_start!=list_ally_unit.end(); ally_start++)
					{
						if (ally_start->get_healthPoint() <= 0)    // 스플공격받은 enemy의 체력이 0이 되면
						{
							list_ally_unit.erase(ally_start);		// list_enemy_unit에서 삭제
							if(list_ally_unit.size()!=0)
								ally_start = list_ally_unit.begin();
							else
								break;
						}
					}
					_list.clear();
				}
			}

			if(arr[0]==true && arr[1] ==true)
				break;
			check =true;                              // 턴 바꾼다
			cout<<endl<<"============================================================================="<<endl<<endl;
		} 
	}
	//------------------------------------------------------------------------------
	if (list_ally_unit.size() == 0)  // 아군의 리스트 크기가 0인 경우 : 적군 승리      
	{
		cout << "\t적군 승리"<< endl << endl;
		enemyUnitPrint();
	}


	if (list_enemy_unit.size() == 0) // 적군의 리스트 크기가 0인 경우 : 아군 승리       
	{
		cout << "\t아군 승리"<< endl << endl;
		allyUnitPrint();
	}

	if (list_enemy_unit.size() != 0 && list_ally_unit.size() != 0 || attack_count == 2)  // 둘 다 크기는 0이 아닌 경우 : 무승부
	{
		cout << "\t무승부" << endl;
		vector<Unit>::iterator iter;

		cout<<"아군 유닛"<<endl;
		for(iter = list_ally_unit.begin(); iter!=list_ally_unit.end(); iter++)
		{
			cout<<"\t이름 : " << iter->get_name()<<endl;
			cout<<"\t체력 : " << iter->get_healthPoint()<<endl;
			cout<<"\t공격력 : "<<iter->get_offence()<<endl;
			cout<<"\t방어력 : "<<iter->get_defende()<<endl;
			cout<<"\t이동 : "<<iter->performVehicleType()<<endl;
			cout<<"\t공격가능 : "<<iter->performAttackBehavior()<<endl;
			cout<<"\t스플래쉬 : "<<iter->performSplashable()<<endl;
			cout<<"==================================="<<endl;
		}

		cout<<"적군 유닛"<<endl;
		for(iter = list_enemy_unit.begin(); iter!=list_enemy_unit.end(); iter++)
		{
			cout<<"\t이름 : " << iter->get_name()<<endl;
			cout<<"\t체력 : " << iter->get_healthPoint()<<endl;
			cout<<"\t공격력 : "<<iter->get_offence()<<endl;
			cout<<"\t방어력 : "<<iter->get_defende()<<endl;
			cout<<"\t이동 : "<<iter->performVehicleType()<<endl;
			cout<<"\t공격가능 : "<<iter->performAttackBehavior()<<endl;
			cout<<"\t스플래쉬 : "<<iter->performSplashable()<<endl;
			cout<<"==================================="<<endl;
		}
	}
}

void StarCraft::createAlly(char type)  // 아군유닛 객체 생성
{ 
	unit = uf.createUnit(type);
	list_ally_unit.push_back(*unit);

	/*unit = uf.createUnit(4);
	list_ally_unit.push_back(*unit);
	unit = uf.createUnit(4);
	list_ally_unit.push_back(*unit);
	unit = uf.createUnit(3);
	list_ally_unit.push_back(*unit);
	unit = uf.createUnit(4);
	list_ally_unit.push_back(*unit);
	unit = uf.createUnit(5);
	list_ally_unit.push_back(*unit);
	unit = uf.createUnit(6);
	list_ally_unit.push_back(*unit);
	unit = uf.createUnit(7);
	list_ally_unit.push_back(*unit);
	unit = uf.createUnit(1);
	list_ally_unit.push_back(*unit);
	unit = uf.createUnit(2);
	list_ally_unit.push_back(*unit);
	unit = uf.createUnit(3);
	list_ally_unit.push_back(*unit);
	unit = uf.createUnit(4);
	list_ally_unit.push_back(*unit);
	unit = uf.createUnit(5);
	list_ally_unit.push_back(*unit);
	unit = uf.createUnit(6);
	list_ally_unit.push_back(*unit);
	unit = uf.createUnit(7);
	list_ally_unit.push_back(*unit);*/
}

void StarCraft::createEnemy()	// 적군유닛 객체 생성
{
	int a = (rand() % 7) + 1;   // 1~7중에 랜덤으로 추출된 숫자 a를 유닛으로 생산      
	unit  = uf.createUnit(a);
	list_enemy_unit.push_back(*unit);
	/*unit  = uf.createUnit(1);
	list_enemy_unit.push_back(*unit);
	unit  = uf.createUnit(6);
	list_enemy_unit.push_back(*unit);
	unit  = uf.createUnit(2);
	list_enemy_unit.push_back(*unit);
	unit  = uf.createUnit(1);
	list_enemy_unit.push_back(*unit);
	unit  = uf.createUnit(7);
	list_enemy_unit.push_back(*unit);
	unit  = uf.createUnit(5);
	list_enemy_unit.push_back(*unit);
	unit  = uf.createUnit(1);
	list_enemy_unit.push_back(*unit);
	unit  = uf.createUnit(5);
	list_enemy_unit.push_back(*unit);
	unit  = uf.createUnit(1);
	list_enemy_unit.push_back(*unit);
	unit  = uf.createUnit(5);
	list_enemy_unit.push_back(*unit);
	unit  = uf.createUnit(1);
	list_enemy_unit.push_back(*unit);
	unit  = uf.createUnit(5);
	list_enemy_unit.push_back(*unit);
	unit  = uf.createUnit(1);
	list_enemy_unit.push_back(*unit);*/
	
	
	switch(a)
	{
	case 1:
		cout<<"\t질럿";
		break;
	case 2:
		cout<<"\t해병";
		break;
	case 3:
		cout<<"\t히드라";
		break;
	case 4:
		cout<<"\t아콘";
		break;
	case 5:
		cout<<"\t스카우트";
		break;
	case 6:
		cout<<"\t가디언";
		break;
	case 7:
		cout<<"\t발키리";
		break;
	}
	cout<<"이(가) 생성되었습니다."<<endl;
	system("pause");
	system("cls");
}

Unit* StarCraft::randomAlly()	// 램덤으로 아군 Unit 객체 선택
{
	string available;;//에러시확인
	vector<Unit>::iterator start = list_ally_unit.begin();
	vector<Unit>::iterator end = list_ally_unit.end();
	int count = 0;
	int _count = 0;
	int ran_count = 0;
	int ran_num = 0;
	vector<int> int_list;
	list_defender.clear();

	/*for(vector<Unit>::iterator st = list_ally_unit.begin(); st!=list_ally_unit.end(); st++)
	ran_count++;
	if(ran_count!=0)
	ran_num = (rand() % ran_count);
	if(unit==NULL)
	unit = &list_ally_unit.at(ran_num);
	ran_num = 0;
	ran_count = 0;*/
	if(unit!=NULL)
		available = unit->get_attackbehavior()->get_attack();

	if (available  == "지상")                 // 지상 유닛만 공격가능
	{
		for( start; start != end; start++, _count++)
		{
			if(start->performVehicleType() == "지상")
			{
				list_defender.push_back(*start);// list_defender와 splash_pos이용해 BattleAlgorithm::EstimateDamage()함수에서 스플래쉬 데미지 계산
				int_list.push_back(_count);
				count++;
			}     
		}

		if(count !=0)
		{
			splash_pos = (rand() % count);      // 1 ~ count 사이 랜덤
			return &list_ally_unit.at(int_list.at(splash_pos));
		}
	}

	if (available  == "공중")                  // 공중 유닛만 공격가능
	{
		for( start; start != end; start++,_count++)
		{
			if(start->performVehicleType() == "공중")
			{
				list_defender.push_back(*start);// list_defender와 splash_pos이용해 BattleAlgorithm::EstimateDamage()함수에서 스플래쉬 데미지 계산
				int_list.push_back(_count);
				count++;
			}
		}

		if(count !=0)
		{	
			splash_pos = (rand() % count);      // 1 ~ count 사이 랜덤
			return &list_ally_unit.at(int_list.at(splash_pos));
		}
	}    

	if (available  == "지상&공중")         // 모든 유닛 공격가능
	{
		for(start; start!=end; start++,_count++)
		{
			list_defender.push_back(*start);
			int_list.push_back(_count);
			count++;
		}
		if(count !=0)
		{
			splash_pos = (rand() % list_ally_unit.size());   // 1~ enemy_size() 사이 랜덤
			return &list_ally_unit.at(int_list.at(splash_pos));
		}
	}
	return NULL;                   // 공격 가능 유닛 없음
}

Unit* StarCraft::randomEnemy()  // 램덤으로 적군 Unit 객체 선택
{
	string available;//에러시확인
	vector<Unit>::iterator start = list_enemy_unit.begin();
	vector<Unit>::iterator end = list_enemy_unit.end();
	int count = 0;
	int _count = 0;
	int ran_count = 0;
	int ran_num = 0;
	vector<int> int_list;

	list_defender.clear();

	/*for(vector<Unit>::iterator st = list_enemy_unit.begin(); st!=list_enemy_unit.end(); st++)
	ran_count++;
	if(ran_count!=0)
	ran_num = (rand() % ran_count);
	if(unit==NULL)
	unit = &list_enemy_unit.at(ran_num);
	ran_num = 0;
	ran_count = 0;*/
	if(unit!=NULL)
		available = unit->get_attackbehavior()->get_attack();

	if (available  == "지상")                 // 지상 유닛만 공격가능
	{
		for( start; start != end; start++,_count++)
		{
			if(start->performVehicleType() == "지상")
			{
				list_defender.push_back(*start);// list_defender와 splash_pos이용해 BattleAlgorithm::EstimateDamage()함수에서 스플래쉬 데미지 계산
				int_list.push_back(_count);
				count++;
			}       
		}

		if(count !=0)
		{
			splash_pos = (rand() % count);      // 1 ~ count 사이 랜덤
			return &list_enemy_unit.at(int_list.at(splash_pos));
		}
	}

	if (available  == "공중")                  // 공중 유닛만 공격가능
	{
		for( start; start != end; start++,_count++)
		{
			if(start->performVehicleType() == "공중")
			{
				list_defender.push_back(*start);// list_defender와 splash_pos이용해 BattleAlgorithm::EstimateDamage()함수에서 스플래쉬 데미지 계산
				int_list.push_back(_count);
				count++;
			}
		}

		if(count !=0)
		{
			splash_pos = (rand() % count);      // 1 ~ count 사이 랜덤
			return &list_enemy_unit.at(int_list.at(splash_pos));
		}
	}    

	if (available  == "지상&공중")         // 모든 유닛 공격가능
	{
		for(start; start!=end; start++,_count++)
		{
			list_defender.push_back(*start);
			int_list.push_back(_count);
			count++;
		}

		if(count!=0)
		{
			splash_pos = (rand() % count);   // 1~ enemy_size() 사이 랜덤
			return &list_enemy_unit.at(int_list.at(splash_pos));
		}
	}
	return NULL;                   // 공격 가능 유닛 없음
}

void StarCraft::eraseAlly(Unit &_unit)  // healthPoint(체력)이 0인 아군 Unit객체 삭제
{
	vector<Unit>::iterator iter;
	for(iter=list_ally_unit.begin(); iter!=list_ally_unit.end(); iter++)
		if(iter->get_id() == _unit.get_id())
			list_ally_unit.erase(iter);
}

void StarCraft::eraseEnemy(Unit &_unit)  // healthPoint(체력)이 0인 적군 Unit객체 삭제
{
	vector<Unit>::iterator iter;
	for(iter=list_enemy_unit.begin(); iter!=list_enemy_unit.end(); iter++)
	{
		if(iter->get_healthPoint()<=0)
		{
			list_enemy_unit.erase(iter);
			break;
		}
	}

	for(iter=list_ally_unit.begin(); iter!=list_ally_unit.end(); iter++)
	{
		if(iter->get_healthPoint()<=0)
		{
			list_ally_unit.erase(iter);
			break;
		}
	}
}

void StarCraft::printStart()	// 시작화면
{
	char sellect;
	while(true)
	{
		cout<<"\t\tstarCraft"<<endl<<endl;
		cout<<"\t메뉴"<<endl<<endl;
		cout<<"\t1. 아군 유닛 생산"<<endl;
		cout<<"\t2. 아군 유닛 확인"<<endl;
		cout<<"\t3. 적군 유닛 생산"<<endl;
		cout<<"\t4. 적군 유닛 확인"<<endl;
		cout<<"\t5. 배틀"<<endl;
		cout<<"\t6. 종료"<<endl<<endl;
		cout<<"\t메뉴 선택 : ";
		sellect = _getch();
		cout<<sellect<<endl<<endl;

		switch(sellect)
		{
		case '1':
			system("cls");
			cout<<"\t\tstarCraft"<<endl<<endl;
			cout<<"\t메뉴"<<endl<<endl;
			cout<<"\t1. 질럿"<<endl;
			cout<<"\t2. 해병"<<endl;
			cout<<"\t3. 히드라"<<endl;
			cout<<"\t4. 아콘"<<endl;
			cout<<"\t5. 스카우트"<<endl;
			cout<<"\t6. 가디언"<<endl;
			cout<<"\t7. 발키리"<<endl<<endl;
			cout<<"\t유닛 선택 : ";
			sellect = _getch();
			cout<<sellect<<endl<<endl;
			if(sellect=='1' || sellect=='2' || sellect=='3' || sellect=='4' || sellect=='5' || sellect=='6' || sellect=='7')
			{
				createAlly(sellect);
				switch(sellect)
				{
				case '1':
					cout<<"\t질럿";
					break;
				case '2':
					cout<<"\t해병";
					break;
				case '3':
					cout<<"\t히드라";
					break;
				case '4':
					cout<<"\t아콘";
					break;
				case '5':
					cout<<"\t스카우트";
					break;
				case '6':
					cout<<"\t가디언";
					break;
				case '7':
					cout<<"\t발키리";
					break;
				}
				cout<<"이(가) 생성되었습니다."<<endl;
			}

			else
				cout<<"\t잘못 입력하셨습니다."<<endl;

			system("pause");
			system("cls");
			break;

		case '2':
			system("cls");
			allyUnitPrint();
			break;

		case '3':
			createEnemy();
			break;

		case '4':
			system("cls");
			enemyUnitPrint();
			break;

		case '5':
			turnBattle();
			break;

		case '6':
			exit(100);

		default:
			cout<<"\t잘못 입력하셨습니다."<<endl;
			break;
		}
	}
}

void StarCraft::allyUnitPrint()  // 아군유닛 vector<Unit> list_ally_unit 출력
{
	vector<Unit>::iterator iter;
	for(iter = list_ally_unit.begin(); iter!=list_ally_unit.end(); iter++)
	{
		cout<<"\t이름 : " << iter->get_name()<<endl;
		cout<<"\t체력 : " << iter->get_healthPoint()<<endl;
		cout<<"\t공격력 : "<<iter->get_offence()<<endl;
		cout<<"\t방어력 : "<<iter->get_defende()<<endl;
		cout<<"\t이동 : "<<iter->performVehicleType()<<endl;
		cout<<"\t공격가능 : "<<iter->performAttackBehavior()<<endl;
		cout<<"\t스플래쉬 : "<<iter->performSplashable()<<endl;
		cout<<"==================================="<<endl;
	}
	system("pause");
	system("cls");
}

void StarCraft::enemyUnitPrint()  // 적군유닛 vector<Unit> list_enemy_unit 출력
{
	vector<Unit>::iterator iter;
	for(iter = list_enemy_unit.begin(); iter!=list_enemy_unit.end(); iter++)
	{
		cout<<"\t이름 : " << iter->get_name()<<endl;
		cout<<"\t체력 : " << iter->get_healthPoint()<<endl;
		cout<<"\t공격력 : "<<iter->get_offence()<<endl;
		cout<<"\t방어력 : "<<iter->get_defende()<<endl;
		cout<<"\t이동 : "<<iter->performVehicleType()<<endl;
		cout<<"\t공격가능 : "<<iter->performAttackBehavior()<<endl;
		cout<<"\t스플래쉬 : "<<iter->performSplashable()<<endl;
		cout<<"==================================="<<endl;
	}
	system("pause");
	system("cls");
}