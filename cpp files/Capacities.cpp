#include "../headers/Capacities.h"

const double Capacities::boostAndDebuffs[13] = { 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 0.25, 0.29, 0.33, 0.4, 0.5, 0.67 };

Capacities::Capacities()
{

};

capacity Capacities::Charge()
{
	return capacity({
		"Charge",
		"Normal",
		"Physique",
		30,
		30,
		40,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		100,
		0,
		"None",
		0,
		1 / 24
	});
};

capacity Capacities::Eclair()
{
	return capacity({
		"Eclair",
		"Electrik",
		"Special",
		30,
		30,
		40,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		100,
		0,
		"Paralysie",
		10,
		1 / 24,
		TYPE_ELECTRIK
	});
};

capacity Capacities::Mimi_Queue()
{
	return capacity({
	"Mimi-Queue",
	"Normal",
	"None",
	30,
	30,
	0,
	0,
	0,
	0,
	0,
	0,
	1,
	0,
	0,
	0,
	0,
	0,
	0,
	100,
	0,
	"None",
	0,
	1 / 24
		});
};

capacity Capacities::Rugissement()
{
	return capacity({
	"Rugissement",
	"Normal",
	"None",
	40,
	40,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	1,
	0,
	0,
	0,
	0,
	0,
	100,
	0,
	"None",
	0,
	1 / 24
		});
};

capacity Capacities::Implore()
{
	return capacity({
	"Implore",
	"Normal",
	"Physique",
	25,
	25,
	60,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	100,
	0,
	"None",
	0,
	1 / 24
		});
};

capacity Capacities::Pistolet_a_O()
{
	return capacity({
		"Pistolet a O",
		"Eau",
		"Spécial",
		25,
		25,
		40,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		100,
		0,
		"None",
		0,
		1 / 24,
		TYPE_WATER
	});
};

capacity Capacities::Flammeche()
{
	return capacity({
	"Flammeche",
	"Feu",
	"Spécial",
	25,
	25,
	40,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	100,
	0,
	"Brulure",
	10,
	1 / 24,
	TYPE_FIRE
		});
};

capacity Capacities::Choc_Mental()
{
	return capacity({
	"Choc Mental",
	"Psy",
	"Spécial",
	25,
	25,
	50,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	100,
	0,
	"Confusion",
	10,
	1 / 24,
	TYPE_PSY
		});
};

capacity Capacities::Jet_de_Sable()
{
	return capacity({
	"Jet de Sable",
	"Sol",
	"None",
	15,
	15,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	100,
	-1,
	"None",
	0,
	1 / 24
		});
};

capacity Capacities::Morsure()
{
	return capacity({
	"Morsure",
	"Tenebre",
	"Special",
	25,
	25,
	60,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	100,
	0,
	"Peur",
	30,
	1 / 24,
	TYPE_DARKNESS
		});
};

capacity Capacities::Tranche_Herbe()
{
	return capacity({
	"Tranche'Herbe",
	"Plante",
	"Physique",
	25,
	25,
	55,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	95,
	0,
	"None",
	0,
	1 / 8,
	TYPE_GRASS
		});
};

capacity Capacities::Vent_Glace()
{
	return capacity({
	"Vent Glace",
	"Glace",
	"Special",
	15,
	15,
	55,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	-1,
	0,
	95,
	0,
	"None",
	0,
	1 / 24,
	TYPE_ICE
		});
};

capacity Capacities::Vent_Feerique()
{
	return capacity({
	"Vent Feerique",
	"Fee",
	"Special",
	30,
	30,
	40,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	100,
	0,
	"None",
	0,
	1 / 24,
	TYPE_FAIRY
		});
};