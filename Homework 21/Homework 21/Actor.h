#pragma once
#include<vector>
#include "Interface.h"

class Actor {
public:
private:

};

//public IHealthNotifier - підписується на це, бо він сповіщає всім кому це потрібно
class Character : public Actor, public IHealthNotifier, public IDamagable
{
public:
	virtual void ApplyDamage(float damage) {
		health -= damage;
		//проходимось по масиву та відсилаємо нове здоров'я
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
		//тут ми шукаємо між початком та кінцем, нашого ресівера
		subscribers.erase(std::find(subscribers.begin(), subscribers.end(),receiver));
	}
private:
	// зберігання наших сабскраберів
	std::vector <IHealthUpdateReceiver*> subscribers;
	float health = 100.0f;
};