#define _CRT_SECURE_NO_WARNINGS
/******************************************************************************

8/11/23
Alessandro Di Roberto

Esempi

*******************************************************************************/

#include <iostream>

class Pc
{
public:
	int core;
	virtual void Print(char) { printf("PC\n"); };
	virtual void Print(int, int, int) { printf("PC\n"); }; //overloading

	virtual void Print() { printf("PC\n"); };
};

class Portatile : public Pc
{
public:
	int durata_batteria;
	virtual void Print()
	{
		printf("Portatile\n");
	};	//Overriding
};

class TinO : public Portatile
{
public:
	int pezzi;
	void Print();
};

class Fisso : public Pc
{
public:
	int kwh;
};

int main()
{
	Pc arr[3];

	arr[0] = Fisso();
	arr[1] = Portatile();
	arr[2] = TinO();

	for (int i = 0; i < 3; i++)
		Print(arr[i]);

	Portatile port;
	TinO t;
	Fisso f;

	Print(port);
	Print(t);
	Print(f);

	return 0;
}

void Print(Pc pc)
{
	//a run-time, assume diversi aspetti
	pc.Print();
}