#include "Classes.h"

bool CombatVehicle::IsDestroyed(int health) const
{
    return health == 0 && health <= 0;
}

// default info
void CombatVehicle::ShowInfo()
{
    cout << "Type:" << type << endl;
    cout << "Model: " << model << endl;
    cout << "Health: " << health << endl;

}

void CombatVehicle::Defense(int damage)
{
    
}

bool Tank::IsDestroyed(int health) const
{
    return CombatVehicle::IsDestroyed(health);
}

// Tank show info
void Tank::ShowInfo()
{
    CombatVehicle::ShowInfo();
    cout <<"Reload time: " <<  R << endl;//reload time
    cout << "Shot accuracy: " << A << endl;//shot accuracy
    cout << "Armor thickness: " << T << endl;;//armor thickness
}
//defence Tank
void Tank::Defense(int damage)
{
    health -= (damage - T);
    if (IsDestroyed(health))
        cout << "Tank destroyed" << endl;
    else
        cout << "Tank health: " << health << endl;

}

int Tank::Attack()
{
    int damage;
    damage = (100 * A / R);
    return damage;
}

bool ArmoredCar::IsDestroyed(int health) const
{
    return CombatVehicle::IsDestroyed(health);
}

//info armored car
void ArmoredCar::ShowInfo()
{
    CombatVehicle::ShowInfo();
    cout << "Number of weapons: " << C << endl;
    cout << "Speed: " << S << endl;
}
//defence Armored car
void ArmoredCar::Defense(int damage)
{
    health -= (damage - (S/2));
    if (IsDestroyed(health))
        cout << "Armored Car destroyed" << endl;
    else
        cout << "Armored Car health: " << health << endl;
}

int ArmoredCar::Attack()
{
    int damage ;
    damage = (50 * C);
    return damage;
}

bool AirDefenseVehicle::IsDestroyed(int health) const
{
    return CombatVehicle::IsDestroyed(health);
}
// info AirDefenseVehicle
void AirDefenseVehicle::ShowInfo()
{
    CombatVehicle::ShowInfo();
    cout << "Shooting range: " << L << endl;
    cout << "Shots per minute: " << R << endl;
    cout << "Mobility: " << M << endl;
}
//defence air vehicle
void AirDefenseVehicle::Defense(int damage)
{
    health -= (damage / M);
    if (IsDestroyed(health))
        cout << "Air Defense Vehicle destroyed" << endl;
    else
        cout << "Air Defense Vehicle health: " << health << endl;
}

int AirDefenseVehicle::Attack()
{
    int damage;
    damage = ((150 + L) * (R / 10));
    return damage;
}
