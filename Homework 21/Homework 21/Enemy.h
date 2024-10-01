#pragma once
#include "Actor.h"
#include<iostream>

class Enemy : public Actor, public IHealthUpdateReceiver {
public:
	//приклад використання в отримані повідомленя 
	virtual void ReceiveNewHealth(float newHealth) {
		std::cout << "Enemy got new info" << newHealth << std::endl;
	}
};