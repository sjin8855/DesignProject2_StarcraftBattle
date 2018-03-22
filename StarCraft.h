#pragma once
#include "UnitFactory.h"
#include <vector>
#include <list>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include <conio.h>

class StarCraft
{
public:
	StarCraft();
	
public: // turnBattle 관련 함수 모음
	void turnBattle();	// 아군 vs 적군 싸움
	void createAlly(char type);  // 아군유닛 객체 생성
	void createEnemy();	// 적군유닛 객체 생성
	Unit* randomAlly();	// 램덤으로 아군 Unit 객체 선택
	Unit* randomEnemy();  // 램덤으로 적군 Unit 객체 선택
	void eraseAlly(Unit &_unit);  // healthPoint(체력)이 0인 아군 Unit객체 삭제
	void eraseEnemy(Unit &_unit);  // healthPoint(체력)이 0인 적군 Unit객체 삭제
	
public :
	void printStart();	// 시작화면
	void allyUnitPrint();  // 아군유닛 vector<Unit> list_ally_unit 출력
	void enemyUnitPrint();  // 적군유닛 vector<Unit> list_enemy_unit 출력

private:
	UnitFactory uf;  // 유닛팩토리 객체
	Unit* unit;  // 유닛 객체
	vector<Unit> list_ally_unit;  // 아군유닛 저장
	vector<Unit> list_enemy_unit;  // 적군유닛 저장
	vector<Unit> list_defender; // 스플래쉬를 당하는 유닛 저장
	int splash_pos; // 스플래쉬 당하는 list_defender의 위치 저장
	
};