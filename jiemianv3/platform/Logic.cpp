#include "Logic.h"
#include <fstream>

using namespace DS14;



void DS14::logic::toReplay( std::string directory, Status * statusToFile, Names * namesToFile)
{
	ofstream toFile(directory, ios_base::binary|ios_base::app);
	if(statusToFile->roundNumber == 0)
	{
		toFile.write((char*)(namesToFile),sizeof(namesToFile));
	}
	toFile.write((char*)(&(statusToFile)),sizeof(statusToFile));
}
