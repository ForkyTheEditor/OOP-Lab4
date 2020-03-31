#include "Medikament.h"

Medikament::Medikament(std::string name, float konzentration, float price) {

	this->name = name;
	this->konzentration = konzentration;
	this->price = price;

	this->menge = 0;


}

std::string Medikament::getName() {

	return this->name;

}

float Medikament::getKonzentration() {

	return this->konzentration;
}

float Medikament::getPrice() {


	return this->price;

}

void Medikament::setPrice(float newPrice) {

	this->price = newPrice;

}

int Medikament::getMenge() {

	return this->menge;

}

void Medikament::setMenge(int newMenge) {

	this->menge = newMenge;

}




bool Medikament::isEqualTo(Medikament other) {

	if (this->getName() == other.getName() && this->getKonzentration() == other.getKonzentration()) {

		return true;
	}


	return false;
	


}