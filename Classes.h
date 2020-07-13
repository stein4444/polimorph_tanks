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
	CombatVehicle(): type("none"), model("none") , health(0){}
	CombatVehicle(string type, string model, int health): type(type), model(model), health(health) {}
	virtual bool IsDestroyed() const;
	virtual void ShowInfo();
	virtual int Attack();
	virtual void Defense(int damage);

};
class Tank : public CombatVehicle
{
protected:
	int R;//reload time
	int A;//shot accuracy
	int T;//armor thickness
public:
	Tank(): R(0), A(0), T(0){}
	Tank(string model, int health, int R, int A, int T): CombatVehicle
		("Tank", model, health), R(R), A(A), T(T){}
	virtual bool IsDestroyed() const override;
	virtual void ShowInfo()override;
	virtual void Defense(int damage)override;
	virtual int Attack()override;
};

class ArmoredCar : public CombatVehicle
{
protected:
	int C; //weapon count
	int S; //speed
public:
	ArmoredCar(): C(0), S(0){}
	ArmoredCar(string model, int health, int C, int S):
		CombatVehicle("Armored Car", model, health), C(C), S(S) {}
	virtual bool IsDestroyed() const override;
	virtual void ShowInfo()override;
	virtual void Defense(int damage)override;
	virtual int Attack()override;
};

class AirDefenseVehicle : public CombatVehicle
{
protected:
	int L; // shooting distance
	int R; // shoots per minute
	int M; // mobility
public:
	AirDefenseVehicle() : L(0), R(0), M(0) {}
	AirDefenseVehicle( string model, int health,int L, int R, int M):
		CombatVehicle("Air Defense Vehicle", model, health), L(L), R(R), M(M) {}
	virtual bool IsDestroyed() const override;
	virtual void ShowInfo()override;
	virtual void Defense(int damage)override;
	virtual int Attack()override;
};

bool Round(CombatVehicle* bm1, CombatVehicle* bm2);