#include "Classes.h"

bool CombatVehicle::IsDestroyed() const
{
    return health < 1;
}

// default info
void CombatVehicle::ShowInfo()
{
    cout << "Type:" << type << endl;
    cout << "Model: " << model << endl;
    cout << "Health: " << health << endl;
}

int CombatVehicle::Attack()
{
    return 0;
}

void CombatVehicle::Defense(int damage)
{
    
}

bool Tank::IsDestroyed() const
{
    return CombatVehicle::IsDestroyed();
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
    if (IsDestroyed())
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

bool ArmoredCar::IsDestroyed() const
{
    return CombatVehicle::IsDestroyed();
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
    if (IsDestroyed())
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

bool AirDefenseVehicle::IsDestroyed() const
{
    return CombatVehicle::IsDestroyed();
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
    if (IsDestroyed())
        cout << "Air Defense Vehicle destroyed" << endl;
    else
        cout << "Air Defense Vehicle health: " << health << endl;
}

int AirDefenseVehicle::Attack()
{
    int damage;
    damage = (150 + L * (R / 10));
    return damage;
}

bool Round(CombatVehicle* bm1, CombatVehicle* bm2){
    while (!bm1->IsDestroyed() || !bm2->IsDestroyed())
    {
       
        int dmg1 = bm1->Attack();
        bm2->Defense(dmg1);
        if (bm2->IsDestroyed())
        {
            bm2->ShowInfo(); cout << endl;
            cout << "DESTROYED!!!" << endl;
           
        }
        else
        {
            int dmg2 = bm2->Attack();
            bm1->Defense(dmg2);
            if (bm1->IsDestroyed())
            {
                bm1->ShowInfo(); cout << endl;
                cout << "DESTROYED!!!" << endl;
              
            }   
        }
        if (bm1->IsDestroyed())
            return true;
        else if (bm2->IsDestroyed())
            return false;

    }
}
