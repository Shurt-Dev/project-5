#pragma once
#include <string>

#define TYPE_NONE NULL
#define TYPE_NORMAL 0
#define TYPE_GRASS 1
#define TYPE_FIRE 2
#define TYPE_WATER 3
#define TYPE_ELECTRIK 4
#define TYPE_ICE 5
#define TYPE_PSY 6
#define TYPE_DARKNESS 7
#define TYPE_FAIRY 8

const struct capacity
{
	std::string capacityName;
	std::string capacityType;
	std::string category;
	int useTotal;
	int useLeft;
	int power;
	int defBoost;
	int atkBoost;
	int speDefBoost;
	int speAtkBoost;
	int speedBoost;
	int precisionBoost;
	int defDeBuff;
	int atkDeBuff;
	int speDefDeBuff;
	int speAtkDeBuff;
	int speedDeBuff;
	int healthBoost;
	int precision;
	int precisionDeBuff;
	std::string appliedStatus;
	int appliedStatusChance;
	int CritChance = 1/24;
	int categoryInt = TYPE_NORMAL;
};

class Capacities
{
public:
	Capacities();

	static const double boostAndDebuffs[13];

	static capacity Charge();

	static capacity Eclair();

	static capacity Mimi_Queue();

	static capacity Rugissement();

	static capacity Implore();

	static capacity Pistolet_a_O();

	static capacity Flammeche();

	static capacity Choc_Mental();

	static capacity Jet_de_Sable();

	static capacity Morsure();

	static capacity Tranche_Herbe();

	static capacity Vent_Glace();

	static capacity Vent_Feerique();
};