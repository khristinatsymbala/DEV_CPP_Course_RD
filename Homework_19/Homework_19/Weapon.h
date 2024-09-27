#pragma once
#include <string>
class Weapon
{
public:
	Weapon();
	~Weapon();

	
	virtual float GetDamage() = 0;
	virtual std::string GetName() = 0;


};

/////////////////////////////////////////////////////// Sword
class Sword : public Weapon
{
public:
	Sword();
	~Sword();

	//Sword(std::string name, float damage, bool twohands);


	virtual float GetDamage() override { return damage; }

	virtual std::string GetName() override { return Name; }


private:
	std::string Name{ "Sword" };
	float damage{ 15.0f };
	

};


/////////////////////////////////////////////////////// Halberd - алебарда
class Halberd : public Weapon
{
public:
	Halberd();
	~Halberd();

	virtual float GetDamage() override { return damage; }

	virtual std::string GetName() override { return Name; }


private:
	std::string Name{ "Halberd" };
	float damage{ 30.0f };
};

/////////////////////////////////////////////////////// Mace(bludgeon) - булава

class Bludgeon : public Weapon
{
public:
	Bludgeon();
	~Bludgeon();
	virtual float GetDamage() override { return damage; }

	virtual std::string GetName() override { return Name; }


private:
	std::string Name{ "Mace" };
	float damage{ 25.0f };


};