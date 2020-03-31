#include "ApothekeUI.h"
#include "MedikamentRepo.h"
#include <iostream>
#include "UnitTests.h"

void ApothekeUI::startProgram() {

	Tests testObject;
	testObject.runAllTests();


	bool quitProgram = false;

	MedikamentRepo mainRepo;

	std::string menuText = "\n1. Add Medikament\n2. Delete Medikament\n3. Change Medikament price\n4. Show Medikamenten list sorted by price";
	menuText += "\n5.Search Medikamenten by string\n6.Search Medikamenten by amount\n7. Undo\n8. Redo\n0.Exit program\n\n";

	//Main loop of the program
	while (!quitProgram) {

		std::cout << menuText;

		int userInput = -1;

		std::cout << "Your choice: ";
		
		//Take the user choice
		std::cin >> userInput;

		//Check if the input is incorrect 
		if (std::cin.fail()) {

			std::cin.clear();
			std::cin.ignore();
			std::cout << std::endl << "Invalid input!" << std::endl;
			
		}
		
		switch (userInput) {

		case 0:
			quitProgram = true;
			break;

		case 1:
			mainRepo.addMedikament(this->takeInput(true));
			break;

		case 2:
			mainRepo.deleteMedikament(this->takeInput(false));
			break;
		case 3:
			{
				Medikament searchedMedikament = this->takeInput(false);
				float newPrice = -1;

				std::cout << "\nMedikament neu preis: ";
				std::cin >> newPrice;

				if (std::cin.fail()) {

					std::cin.clear();
					std::cin.ignore();
					std::cout << std::endl << "Invalid input! Exiting to main menu..." << std::endl;

					break;

				}

				if (mainRepo.findMedikament(searchedMedikament).size() != 0) {

					mainRepo.findMedikament(searchedMedikament)[0].setPrice(newPrice);
					break;

				}
				else {

					std::cout << "\nMedikament wasn't found!";
					break;

				}
			}
		case 4:
			{
			
				std::vector<Medikament> printVector = mainRepo.returnMedikamentenByPrice();

				for (int i = 0; i < printVector.size(); i++) {

					std::cout << printVector[i].getName() << " Konz: "  << printVector[i].getKonzentration()<< " Menge: " << printVector[i].getMenge() << " Preis: " << printVector[i].getPrice() << std::endl;

				}

				break;
			}
		case 5:

			{

				std::string searchString;
				std::cout << "\nString: ";
				std::cin >> searchString;

				std::vector<Medikament> printVector = mainRepo.findMedikamentenByString(searchString);

				for (int i = 0; i < printVector.size(); i++) {

					std::cout << printVector[i].getName() << " Konz: " << printVector[i].getKonzentration() << " Menge: " << printVector[i].getMenge() << " Preis: " << printVector[i].getPrice() << std::endl;

				}

				break;
			}

		case 6:

			{
				int menge = -1;
				while (menge == -1) {

					std::cout << "\nAmount: ";
					std::cin >> menge;

					if (std::cin.fail()) {

						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << std::endl << "Invalid input!" << std::endl;

						menge = -1;

					}

				}

				std::vector<Medikament> printVector = mainRepo.findMedikamentenByAmount(menge);

				for (int i = 0; i < printVector.size(); i++) {

					std::cout << printVector[i].getName() << " Konz: " << printVector[i].getKonzentration() << " Menge: " << printVector[i].getMenge() << " Preis: " << printVector[i].getPrice() << std::endl;

				}

				break;

			}

		}

	}

}

Medikament ApothekeUI::takeInput(bool forAddition) {

	std::string newName;
	float newKonzentration = -1;
	float newPrice = -1;

	std::cout << "\nMedikament name: ";
	std::cin >> newName;

	while (newKonzentration == -1) {

		std::cout << "\nMedikament konzentration: ";
		std::cin >> newKonzentration;

		if (std::cin.fail()) {

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl << "Invalid input!" << std::endl;

			newKonzentration = -1;

		}

	}
	
	if (forAddition) {

		while (newPrice == -1) {

			std::cout << "\nMedikament preis: ";
			std::cin >> newPrice;

			if (std::cin.fail()) {

				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl << "Invalid input!" << std::endl;

				newPrice = -1;

			}
		}

	}
	

	return Medikament(newName, newKonzentration, newPrice);


}

