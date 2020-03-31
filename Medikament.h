#pragma once
#include <string>

class Medikament {

private:

	std::string name;
	float konzentration;
	int menge;
	float price;

public:

	Medikament(std::string name, float konzentration, float price);

	int getMenge();
	void setMenge(int newMenge);

	float getPrice();
	void setPrice(float newPrice);

	std::string getName();
	float getKonzentration();
	
	//Compares the two drugs and returns true if they are equal (they have the same name and concentration)
	bool isEqualTo(Medikament other);





};