#include"StarCraft.h"

StarCraft::StarCraft()
{
	srand(time(NULL));
	unit = NULL;
	splash_pos =0;
}

// turnBattle ���� �Լ� ����
void StarCraft::turnBattle()	// �Ʊ� vs ���� �ο�
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
	cout<<"�Ʊ� ������ �����ϴ�."<<endl;
	return ;
	}*/

	while (list_ally_unit.size() !=0 && list_enemy_unit.size() !=0) // �Ʊ��� �����ϰų� ������ ������ �� ���� �ݺ�
	{
		current_pos = 0;
		_list.clear();
		if(check)	// 
		{
			unit = randomAlly();	// �Ʊ� ���� ����
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
			enemy = randomEnemy();	// ���� ���� ���� 

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
				cout<<"\t�Ʊ����� "<<unit->get_name()<<"��(��) "<<enemy->get_name()<<"��(��) �����Ͽ����ϴ�."<<endl;
				cout<<"\t"<<unit->get_name()<<" ���ݷ� : "<<unit->get_offence()<<endl;
				cout<<"\t"<<enemy->get_name()<<" ���� : "<<enemy->get_defende()<<endl;
				cout<<"\t���� ������ : "<<unit->get_offence()-enemy->get_defende()<<endl;
					
				unit ->get_attackbehavior()->attack_damage(*unit, *enemy); // ally�� enemy�� �����Ѵ�.
				if(enemy->get_healthPoint()<=0)
					cout<<"\t"<<enemy->get_name()<<" ü�� : "<<q<<"->"<<"���"<<endl;
				else
					cout<<"\t"<<enemy->get_name()<<" ü�� : "<<q<<"->"<<enemy->get_healthPoint()<<endl;
				
				
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


				if (enemy->get_healthPoint() <= 0)    // ���ݹ��� enemy�� ü���� 0�� �Ǹ�
					eraseEnemy(*enemy);		// list_enemy_unit���� ����

				

			}

			else
			{
				cout<<"\t"<<unit->get_name()<<"�� "<<"������ �� �ִ� ������ �����ϴ�."<<endl;
				attack_count_name[attack_count] = unit->get_name();
				attack_count++;             // ���� ������ ������ ���ٸ� ���º� : attack_count�� 2 �Ǹ� ���º�
				enemy_count++;
				for(vector<Unit>::iterator start = list_enemy_unit.begin(); start!=list_enemy_unit.end(); start++)
				{
					for(int i=0; i<2; i++)
					{

						if(start->performVehicleType()=="����")
						{
							for(vector<Unit>::iterator iter = list_ally_unit.begin(); iter!=list_ally_unit.end(); iter++)
							{
								if(iter->get_attackbehavior()->get_attack()=="����" || iter->get_attackbehavior()->get_attack()=="����&����")
								{
									n_check = true;
									break;
								}
							}
						}

						if(start->performVehicleType()=="����")
						{
							for(vector<Unit>::iterator iter = list_ally_unit.begin(); iter!=list_ally_unit.end(); iter++)
							{
								if(iter->get_attackbehavior()->get_attack()=="����" || iter->get_attackbehavior()->get_attack()=="����&����")
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

			if (unit->performSplashable() == "����")         // splash�� �ִٸ�
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
					
					unit->get_attackbehavior()->splash_damage(*unit, list_enemy_unit, _list);  // ally�ֺ��� ���÷��� ������ ���� 
					for(vector<Unit>::iterator enemy_start = list_enemy_unit.begin(); enemy_start!=list_enemy_unit.end(); enemy_start++)
					{
						if (enemy_start->get_healthPoint() <= 0)    // ���ð��ݹ��� enemy�� ü���� 0�� �Ǹ�
						{
							list_enemy_unit.erase(enemy_start);		// list_enemy_unit���� ����
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

			check = false;                                     // �� �ٲ۴�.
			cout<<endl<<"============================================================================="<<endl<<endl;
		}
		//-------------------------------------------------------------------------------------
		else	// �Ʊ�����
		{
			unit = randomEnemy();    // �Ʊ� ������ ���� �ݴ�� �ٲ��.
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
				cout<<"\t�������� "<<unit->get_name()<<"��(��) "<<enemy->get_name()<<"��(��) �����Ͽ����ϴ�."<<endl;
				cout<<"\t"<<unit->get_name()<<" ���ݷ� : "<<unit->get_offence()<<endl;
				cout<<"\t"<<enemy->get_name()<<" ���� : "<<enemy->get_defende()<<endl;
				cout<<"\t���� ������ : "<<unit->get_offence()-enemy->get_defende()<<endl;
				unit ->get_attackbehavior()->attack_damage(*unit, *enemy); // ally�� enemy�� �����Ѵ�.
				if(enemy->get_healthPoint()<=0)
					cout<<"\t"<<enemy->get_name()<<" ü�� : "<<q<<"->"<<"���"<<endl;
				else
					cout<<"\t"<<enemy->get_name()<<" ü�� : "<<q<<"->"<<enemy->get_healthPoint()<<endl;

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


				if (enemy->get_healthPoint() <= 0)    // ���ݹ��� enemy�� ü���� 0�� �Ǹ�
					eraseEnemy(*enemy);                       // list_enemy_unit���� ����		
			}

			else
			{
				cout<<"\t"<<unit->get_name()<<"�� "<<"������ �� �ִ� ������ �����ϴ�."<<endl;
				attack_count_name[attack_count] = unit->get_name();
				attack_count++;             // ���� ������ ������ ���ٸ� ���º� : attack_count�� 2 �Ǹ� ���º�
				ally_count++;
				for(vector<Unit>::iterator start = list_ally_unit.begin(); start!=list_ally_unit.end(); start++)
				{
					for(int i=0; i<2; i++)
					{

						if(start->performVehicleType()=="����")
						{
							for(vector<Unit>::iterator iter = list_enemy_unit.begin(); iter!=list_enemy_unit.end(); iter++)
							{
								if(iter->get_attackbehavior()->get_attack()=="����" || iter->get_attackbehavior()->get_attack()=="����&����")
								{
									n_check = true;
									break;
								}
							}
						}

						if(start->performVehicleType()=="����")
						{
							for(vector<Unit>::iterator iter = list_enemy_unit.begin(); iter!=list_enemy_unit.end(); iter++)
							{
								if(iter->get_attackbehavior()->get_attack()=="����" || iter->get_attackbehavior()->get_attack()=="����&����")
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

			//if (unit->performSplashable() == "����")         // splash�� �ִٸ�
			//	unit->get_attackbehavior()->splash_damage(*unit, list_defender, splash_pos);  // ally�ֺ��� ���÷��� ������ ����  

			if (unit->performSplashable() == "����")         // splash�� �ִٸ�
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

					unit->get_attackbehavior()->splash_damage(*unit, list_ally_unit, _list);  // ally�ֺ��� ���÷��� ������ ���� 
					for(vector<Unit>::iterator ally_start = list_ally_unit.begin(); ally_start!=list_ally_unit.end(); ally_start++)
					{
						if (ally_start->get_healthPoint() <= 0)    // ���ð��ݹ��� enemy�� ü���� 0�� �Ǹ�
						{
							list_ally_unit.erase(ally_start);		// list_enemy_unit���� ����
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
			check =true;                              // �� �ٲ۴�
			cout<<endl<<"============================================================================="<<endl<<endl;
		} 
	}
	//------------------------------------------------------------------------------
	if (list_ally_unit.size() == 0)  // �Ʊ��� ����Ʈ ũ�Ⱑ 0�� ��� : ���� �¸�      
	{
		cout << "\t���� �¸�"<< endl << endl;
		enemyUnitPrint();
	}


	if (list_enemy_unit.size() == 0) // ������ ����Ʈ ũ�Ⱑ 0�� ��� : �Ʊ� �¸�       
	{
		cout << "\t�Ʊ� �¸�"<< endl << endl;
		allyUnitPrint();
	}

	if (list_enemy_unit.size() != 0 && list_ally_unit.size() != 0 || attack_count == 2)  // �� �� ũ��� 0�� �ƴ� ��� : ���º�
	{
		cout << "\t���º�" << endl;
		vector<Unit>::iterator iter;

		cout<<"�Ʊ� ����"<<endl;
		for(iter = list_ally_unit.begin(); iter!=list_ally_unit.end(); iter++)
		{
			cout<<"\t�̸� : " << iter->get_name()<<endl;
			cout<<"\tü�� : " << iter->get_healthPoint()<<endl;
			cout<<"\t���ݷ� : "<<iter->get_offence()<<endl;
			cout<<"\t���� : "<<iter->get_defende()<<endl;
			cout<<"\t�̵� : "<<iter->performVehicleType()<<endl;
			cout<<"\t���ݰ��� : "<<iter->performAttackBehavior()<<endl;
			cout<<"\t���÷��� : "<<iter->performSplashable()<<endl;
			cout<<"==================================="<<endl;
		}

		cout<<"���� ����"<<endl;
		for(iter = list_enemy_unit.begin(); iter!=list_enemy_unit.end(); iter++)
		{
			cout<<"\t�̸� : " << iter->get_name()<<endl;
			cout<<"\tü�� : " << iter->get_healthPoint()<<endl;
			cout<<"\t���ݷ� : "<<iter->get_offence()<<endl;
			cout<<"\t���� : "<<iter->get_defende()<<endl;
			cout<<"\t�̵� : "<<iter->performVehicleType()<<endl;
			cout<<"\t���ݰ��� : "<<iter->performAttackBehavior()<<endl;
			cout<<"\t���÷��� : "<<iter->performSplashable()<<endl;
			cout<<"==================================="<<endl;
		}
	}
}

void StarCraft::createAlly(char type)  // �Ʊ����� ��ü ����
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

void StarCraft::createEnemy()	// �������� ��ü ����
{
	int a = (rand() % 7) + 1;   // 1~7�߿� �������� ����� ���� a�� �������� ����      
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
		cout<<"\t����";
		break;
	case 2:
		cout<<"\t�غ�";
		break;
	case 3:
		cout<<"\t�����";
		break;
	case 4:
		cout<<"\t����";
		break;
	case 5:
		cout<<"\t��ī��Ʈ";
		break;
	case 6:
		cout<<"\t�����";
		break;
	case 7:
		cout<<"\t��Ű��";
		break;
	}
	cout<<"��(��) �����Ǿ����ϴ�."<<endl;
	system("pause");
	system("cls");
}

Unit* StarCraft::randomAlly()	// �������� �Ʊ� Unit ��ü ����
{
	string available;;//������Ȯ��
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

	if (available  == "����")                 // ���� ���ָ� ���ݰ���
	{
		for( start; start != end; start++, _count++)
		{
			if(start->performVehicleType() == "����")
			{
				list_defender.push_back(*start);// list_defender�� splash_pos�̿��� BattleAlgorithm::EstimateDamage()�Լ����� ���÷��� ������ ���
				int_list.push_back(_count);
				count++;
			}     
		}

		if(count !=0)
		{
			splash_pos = (rand() % count);      // 1 ~ count ���� ����
			return &list_ally_unit.at(int_list.at(splash_pos));
		}
	}

	if (available  == "����")                  // ���� ���ָ� ���ݰ���
	{
		for( start; start != end; start++,_count++)
		{
			if(start->performVehicleType() == "����")
			{
				list_defender.push_back(*start);// list_defender�� splash_pos�̿��� BattleAlgorithm::EstimateDamage()�Լ����� ���÷��� ������ ���
				int_list.push_back(_count);
				count++;
			}
		}

		if(count !=0)
		{	
			splash_pos = (rand() % count);      // 1 ~ count ���� ����
			return &list_ally_unit.at(int_list.at(splash_pos));
		}
	}    

	if (available  == "����&����")         // ��� ���� ���ݰ���
	{
		for(start; start!=end; start++,_count++)
		{
			list_defender.push_back(*start);
			int_list.push_back(_count);
			count++;
		}
		if(count !=0)
		{
			splash_pos = (rand() % list_ally_unit.size());   // 1~ enemy_size() ���� ����
			return &list_ally_unit.at(int_list.at(splash_pos));
		}
	}
	return NULL;                   // ���� ���� ���� ����
}

Unit* StarCraft::randomEnemy()  // �������� ���� Unit ��ü ����
{
	string available;//������Ȯ��
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

	if (available  == "����")                 // ���� ���ָ� ���ݰ���
	{
		for( start; start != end; start++,_count++)
		{
			if(start->performVehicleType() == "����")
			{
				list_defender.push_back(*start);// list_defender�� splash_pos�̿��� BattleAlgorithm::EstimateDamage()�Լ����� ���÷��� ������ ���
				int_list.push_back(_count);
				count++;
			}       
		}

		if(count !=0)
		{
			splash_pos = (rand() % count);      // 1 ~ count ���� ����
			return &list_enemy_unit.at(int_list.at(splash_pos));
		}
	}

	if (available  == "����")                  // ���� ���ָ� ���ݰ���
	{
		for( start; start != end; start++,_count++)
		{
			if(start->performVehicleType() == "����")
			{
				list_defender.push_back(*start);// list_defender�� splash_pos�̿��� BattleAlgorithm::EstimateDamage()�Լ����� ���÷��� ������ ���
				int_list.push_back(_count);
				count++;
			}
		}

		if(count !=0)
		{
			splash_pos = (rand() % count);      // 1 ~ count ���� ����
			return &list_enemy_unit.at(int_list.at(splash_pos));
		}
	}    

	if (available  == "����&����")         // ��� ���� ���ݰ���
	{
		for(start; start!=end; start++,_count++)
		{
			list_defender.push_back(*start);
			int_list.push_back(_count);
			count++;
		}

		if(count!=0)
		{
			splash_pos = (rand() % count);   // 1~ enemy_size() ���� ����
			return &list_enemy_unit.at(int_list.at(splash_pos));
		}
	}
	return NULL;                   // ���� ���� ���� ����
}

void StarCraft::eraseAlly(Unit &_unit)  // healthPoint(ü��)�� 0�� �Ʊ� Unit��ü ����
{
	vector<Unit>::iterator iter;
	for(iter=list_ally_unit.begin(); iter!=list_ally_unit.end(); iter++)
		if(iter->get_id() == _unit.get_id())
			list_ally_unit.erase(iter);
}

void StarCraft::eraseEnemy(Unit &_unit)  // healthPoint(ü��)�� 0�� ���� Unit��ü ����
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

void StarCraft::printStart()	// ����ȭ��
{
	char sellect;
	while(true)
	{
		cout<<"\t\tstarCraft"<<endl<<endl;
		cout<<"\t�޴�"<<endl<<endl;
		cout<<"\t1. �Ʊ� ���� ����"<<endl;
		cout<<"\t2. �Ʊ� ���� Ȯ��"<<endl;
		cout<<"\t3. ���� ���� ����"<<endl;
		cout<<"\t4. ���� ���� Ȯ��"<<endl;
		cout<<"\t5. ��Ʋ"<<endl;
		cout<<"\t6. ����"<<endl<<endl;
		cout<<"\t�޴� ���� : ";
		sellect = _getch();
		cout<<sellect<<endl<<endl;

		switch(sellect)
		{
		case '1':
			system("cls");
			cout<<"\t\tstarCraft"<<endl<<endl;
			cout<<"\t�޴�"<<endl<<endl;
			cout<<"\t1. ����"<<endl;
			cout<<"\t2. �غ�"<<endl;
			cout<<"\t3. �����"<<endl;
			cout<<"\t4. ����"<<endl;
			cout<<"\t5. ��ī��Ʈ"<<endl;
			cout<<"\t6. �����"<<endl;
			cout<<"\t7. ��Ű��"<<endl<<endl;
			cout<<"\t���� ���� : ";
			sellect = _getch();
			cout<<sellect<<endl<<endl;
			if(sellect=='1' || sellect=='2' || sellect=='3' || sellect=='4' || sellect=='5' || sellect=='6' || sellect=='7')
			{
				createAlly(sellect);
				switch(sellect)
				{
				case '1':
					cout<<"\t����";
					break;
				case '2':
					cout<<"\t�غ�";
					break;
				case '3':
					cout<<"\t�����";
					break;
				case '4':
					cout<<"\t����";
					break;
				case '5':
					cout<<"\t��ī��Ʈ";
					break;
				case '6':
					cout<<"\t�����";
					break;
				case '7':
					cout<<"\t��Ű��";
					break;
				}
				cout<<"��(��) �����Ǿ����ϴ�."<<endl;
			}

			else
				cout<<"\t�߸� �Է��ϼ̽��ϴ�."<<endl;

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
			cout<<"\t�߸� �Է��ϼ̽��ϴ�."<<endl;
			break;
		}
	}
}

void StarCraft::allyUnitPrint()  // �Ʊ����� vector<Unit> list_ally_unit ���
{
	vector<Unit>::iterator iter;
	for(iter = list_ally_unit.begin(); iter!=list_ally_unit.end(); iter++)
	{
		cout<<"\t�̸� : " << iter->get_name()<<endl;
		cout<<"\tü�� : " << iter->get_healthPoint()<<endl;
		cout<<"\t���ݷ� : "<<iter->get_offence()<<endl;
		cout<<"\t���� : "<<iter->get_defende()<<endl;
		cout<<"\t�̵� : "<<iter->performVehicleType()<<endl;
		cout<<"\t���ݰ��� : "<<iter->performAttackBehavior()<<endl;
		cout<<"\t���÷��� : "<<iter->performSplashable()<<endl;
		cout<<"==================================="<<endl;
	}
	system("pause");
	system("cls");
}

void StarCraft::enemyUnitPrint()  // �������� vector<Unit> list_enemy_unit ���
{
	vector<Unit>::iterator iter;
	for(iter = list_enemy_unit.begin(); iter!=list_enemy_unit.end(); iter++)
	{
		cout<<"\t�̸� : " << iter->get_name()<<endl;
		cout<<"\tü�� : " << iter->get_healthPoint()<<endl;
		cout<<"\t���ݷ� : "<<iter->get_offence()<<endl;
		cout<<"\t���� : "<<iter->get_defende()<<endl;
		cout<<"\t�̵� : "<<iter->performVehicleType()<<endl;
		cout<<"\t���ݰ��� : "<<iter->performAttackBehavior()<<endl;
		cout<<"\t���÷��� : "<<iter->performSplashable()<<endl;
		cout<<"==================================="<<endl;
	}
	system("pause");
	system("cls");
}