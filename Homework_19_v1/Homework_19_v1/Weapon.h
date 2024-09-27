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

class Sword : public Weapon {
public:
    float GetDamage()  override { return 15.0f; }
    std::string GetName()  override { return "Sword"; }
};

class Halberd : public Weapon {
public:
    float GetDamage()  override { return 30.0f; }
    std::string GetName()  override { return "Halberd"; }
};

class Bludgeon : public Weapon {
public:
    float GetDamage()  override { return 25.0f; }
    std::string GetName()  override { return "Bludgeon"; }
};