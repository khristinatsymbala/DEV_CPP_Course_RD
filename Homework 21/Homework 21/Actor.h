#pragma once
#include<vector>
#include "Interface.h"

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
private:
	// ��������� ����� �����������
	std::vector <IHealthUpdateReceiver*> subscribers;
	float health = 100.0f;
};