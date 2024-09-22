#pragma once
#include <string>
class Weapon
{
public:
	Weapon();
	~Weapon();

	
	virtual float GetDamage() = 0;
	virtual std::string GetName() = 0;
	virtual bool two_hands() = 0;

};

/////////////////////////////////////////////////////// Sword
class Sword : public Weapon
{
public:
	Sword();
	~Sword();

	Sword(std::string name, float damage, bool twohands);


	virtual float GetDamage() override;

	virtual std::string GetName() override; 

	virtual bool two_hands() override { return two_hands; }

private:
	std::string Sword_Name; //{"Two-edged"}
	float damage{ 0 };
	bool two_hands = false;

};


/////////////////////////////////////////////////////// Halberd - алебарда



/////////////////////////////////////////////////////// Mace(bludgeon) - булава