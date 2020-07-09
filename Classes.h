#pragma once
#include<iostream>
#include<string>
using std::string;
using std::endl;
using std::cout;

class CombatVehicle
{
protected:
	string type;
	string model;
	int health;
public:
	CombatVehicle(string type, string model, int health): type(type), model(model), health(health) {}
	virtual bool IsDestroyed(int health) const;
	virtual void ShowInfo();
	virtual int Attack() = 0;
	virtual void Defense(int damage);

};
class Tank : protected CombatVehicle
{
private: 
	int R;//reload time
	int A;//shot accuracy
	int T;//armor thickness
public:
	Tank(string model, int health, int R, int A, int T): CombatVehicle
		("Tank", model, health), R(R), A(A), T(T){}
	virtual bool IsDestroyed(int health) const;
	virtual void ShowInfo();
	virtual void Defense(int damage);
	virtual int Attack();
};

class ArmoredCar : protected CombatVehicle
{
private:
	int C; //weapon count
	int S; //speed
public:
	ArmoredCar(string model, int health, int C, int S):
		CombatVehicle("Armored Car", model, health), C(C), S(S) {}
	virtual bool IsDestroyed(int health) const;
	virtual void ShowInfo();
	virtual void Defense(int damage);
	virtual int Attack();
};

class AirDefenseVehicle : protected CombatVehicle
{
private:
	int L; // shooting distance
	int R; // shoots ped minute
	int M; // mobility
public:
	AirDefenseVehicle( string model, int health,int L, int R, int M):
		CombatVehicle("Air Defense Vehicle", model, health), L(L), R(R), M(M) {}
	virtual bool IsDestroyed(int health) const;
	virtual void ShowInfo();
	virtual void Defense(int damage);
	virtual int Attack();
};

void Round(CombatVehicle& bm1, CombatVehicle& bm2)
{
	bm1.
};