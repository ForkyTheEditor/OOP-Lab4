#include "UnitTests.h"
#include "MedikamentRepo.h"
#include "Medikament.h"
#include <cassert>

void Tests::testRepo() {

	//Some unit testing
	MedikamentRepo testRepo;
	testRepo.addMedikament(Medikament("lala", 3.4, 4));

	assert(testRepo.findMedikament(Medikament("lala", 3.4, 1243)).size() != 0 );

	testRepo.addMedikament(Medikament("tete", 4, 5));

	assert( testRepo.findMedikamentenByString("te").size() == 1 );

	testRepo.deleteMedikament(Medikament("tete", 4, 5));
	assert(testRepo.findMedikamentenByString("te").size() == 0);

	assert(testRepo.returnMedikamentenByPrice().size() == 1);

}


void Tests::runAllTests() {

	this->testRepo();

}