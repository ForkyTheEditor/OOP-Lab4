#include "MedikamentRepo.h"
#include <algorithm>

void MedikamentRepo::addMedikament(Medikament medikament) {

	historyList = medikamentList;

	for (int i = 0; i < medikamentList.size(); i++) {


		//If the drug already exists, add 1 to the amount
		if (medikamentList[i].isEqualTo(medikament)) {


			medikamentList[i].setMenge(medikamentList[i].getMenge() + 1);
			return;

		}


	}

	redoList = medikamentList;

	//If the drug doesn't exist, add it to the list
	medikament.setMenge(1);
	medikamentList.push_back(medikament);	


}

void MedikamentRepo::deleteMedikament(Medikament medikament) {

	historyList = medikamentList;

	for (int i = 0; i < medikamentList.size(); i++) {

		if (medikamentList[i].isEqualTo(medikament)) {

			medikamentList.erase(medikamentList.begin() + i);

			redoList = medikamentList;

			return;


		}

	}


}


std::vector<Medikament> MedikamentRepo::findMedikament(Medikament searchedMedikament) {

	std::vector<Medikament> returnList;


	for (int i = 0; i < medikamentList.size(); i++) {

		if (medikamentList[i].isEqualTo(searchedMedikament)) {

			returnList.push_back(medikamentList[i]);
			break;


		}

	}

	return returnList;

}

std::vector<Medikament> MedikamentRepo::findMedikamentenByString(std::string name) {

	std::vector<Medikament> returnList;


	//If the given string is empty return the entire list
	if (name == "") {

		returnList = medikamentList;


	}
	else {
		

		for (int i = 0; i < medikamentList.size(); i++) {


			//Add all the drugs whose names contain the given string to the list
			if (medikamentList[i].getName().find(name) != std::string::npos) {

				returnList.push_back(medikamentList[i]);

			}


		}

	}

	//Sort the list alphabetically
	std::sort(returnList.begin(), returnList.end(), [](Medikament a, Medikament b) {return a.getName() < b.getName(); });

	return returnList;
}

std::vector<Medikament> MedikamentRepo::findMedikamentenByAmount(int maxMenge) {

	std::vector<Medikament> returnList;

	for (int i = 0; i < medikamentList.size(); i++) {

		if (medikamentList[i].getMenge() <= maxMenge) {

			returnList.push_back(medikamentList[i]);
		}


	}

	return returnList;



}

std::vector<Medikament> MedikamentRepo::returnMedikamentenByPrice() {

	std::vector<Medikament> returnList;

	returnList = medikamentList;

	std::sort(returnList.begin(), returnList.end(), [](Medikament a, Medikament b) {return a.getPrice() < b.getPrice(); });

	return returnList;
}

void MedikamentRepo::undo() {

	redoList = medikamentList;
	medikamentList = historyList;

}

void MedikamentRepo::redo() {

	historyList = medikamentList;
	medikamentList = redoList;

}

