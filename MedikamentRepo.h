#pragma once
#include "Medikament.h"
#include <vector>

class MedikamentRepo {

private:

	std::vector<Medikament> historyList;
	std::vector<Medikament> redoList;
	std::vector<Medikament> medikamentList;


public:

	void addMedikament(Medikament medikament);
	void deleteMedikament(Medikament medikament);

	//Returns a vector with the searched drug. If the drug isn't in the repo, returns an empty vector.
	std::vector<Medikament> findMedikament(Medikament searchedMedikament);

	//Returns all the drugs that contain the given string in their name. Returns all drugs if the string is empty
	std::vector<Medikament> findMedikamentenByString(std::string name);
	
	//Returns all the drugs less than the amount maxMenge
	std::vector<Medikament> findMedikamentenByAmount(int maxMenge);

	//Returns all drugs sorted by price
	std::vector<Medikament> returnMedikamentenByPrice();

	//Undoes the last change in the repo
	void undo();

	//Redoes the undone change in the repo
	void redo();


};