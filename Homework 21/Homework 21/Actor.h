#pragma once
#include<vector>
#include <memory>
#include <iostream>
#include "Interface.h"

class Enemy;
class Weapon;


class Actor {
public:
private:

};

//public IHealthNotifier - ���������� �� ��, �� �� ������ ��� ���� �� �������
class Character : public Actor, public IHealthNotifier, public IDamagable
{
public:

	virtual void ApplyDamage(float damage) {
		health -= damage;
		//����������� �� ������ �� �������� ���� ������'�
		for (IHealthUpdateReceiver* receiver : subscribers)
		{
			receiver->ReceiveNewHealth(health);
		}
	}
	virtual void Subscribe(IHealthUpdateReceiver* receiver) 
	{
		subscribers.push_back(receiver);
	}
	virtual void Unsubscribe(IHealthUpdateReceiver* receiver) {
		//��� �� ������ �� �������� �� �����, ������ �������
		subscribers.erase(std::find(subscribers.begin(), subscribers.end(),receiver));
	}

	Character(std::string Name, int XP, float Health)
		:name{ Name }, Xp{ XP }, health{ Health } {}
	~Character() {}

	//  ���� ����� ���������
	void SetWeapon(std::unique_ptr<Weapon> weapon);

	//�� ����� ��������, �� �� ����� � ���������
	Weapon* GetWeapon() const;

	void ListWeapons();
	void GainXP(int Xp_enemy);

	bool IsAlive() const { return health > 0; }
	float GetHealth() { return health; }
	void SetHealth(float newHealth) {
		if (newHealth >= 0) {
			health = newHealth;
		}
	}

	void Fight(Enemy* monster);

private:
	// ��������� ����� �����������
	std::vector <IHealthUpdateReceiver*> subscribers;
	float health = 100.0f;

	std::string name;
	int activeWeaponIndex;
	int maxWeapons{ 2 };
	int Xp{ 0 };
	std::vector<std::unique_ptr<Weapon>> inventory;
};