#pragma once
#include "Medikament.h"

class ApothekeUI {

public:
	void startProgram();

	/*Function for taking the input of a drug
	Takes in a bool parameter. If set to false then the price input will be ignored
	If set to true then the price will be taken into account*/
	Medikament takeInput(bool forAddition);


};
