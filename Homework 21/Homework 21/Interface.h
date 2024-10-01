#pragma once
class IDamagable {
public:
	virtual void ApplyDamage(float damage) = 0;
	/* ������������ � �������
	virtual void ApplyDamage(float damage){
		health -= damage;
	}
	*/
};

//��������� �����������
class IHealthUpdateReceiver {
public:
	virtual void ReceiveNewHealth(float newHealth) = 0;
};

//��� ���� �������� ����, �� ���� �� ������ ���������� �� ���������� ����
class IHealthNotifier {
public:
	virtual void Subscribe(IHealthUpdateReceiver* receiver) = 0;
	virtual void Unsubscribe(IHealthUpdateReceiver* receiver) = 0;
};