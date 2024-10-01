#pragma once
class IDamagable {
public:
	virtual void ApplyDamage(float damage) = 0;
	/* використання в сабкласі
	virtual void ApplyDamage(float damage){
		health -= damage;
	}
	*/
};

//ОТримувач повідомлення
class IHealthUpdateReceiver {
public:
	virtual void ReceiveNewHealth(float newHealth) = 0;
};

//Хто може посилати данні, на кого ми можемо підписатись та отримувати данні
class IHealthNotifier {
public:
	virtual void Subscribe(IHealthUpdateReceiver* receiver) = 0;
	virtual void Unsubscribe(IHealthUpdateReceiver* receiver) = 0;
};