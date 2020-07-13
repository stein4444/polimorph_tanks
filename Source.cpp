#include<iostream>
#include"Classes.h"


int main()
{
	Tank tank("Ò-34", 1000, 2, 4, 20);
	AirDefenseVehicle air("BM-21", 500, 8, 8, 5);

	Round(&tank, &air);
	return 0;
};