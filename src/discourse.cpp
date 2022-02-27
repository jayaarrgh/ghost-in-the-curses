#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include "discourse.h"


Discourse::Discourse(){
	this->getFileContent("data/computer.txt", this->m_sayings);
}

bool Discourse::getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs){
    // Open the File
    std::ifstream in(fileName.c_str());
    // Check if object is valid
    if(!in)
    {
        std::cerr << "Cannot open the File : "<<fileName<<std::endl;
        return false;
    }
    std::string str;
    // Read the next line from File untill it reaches the end.
    while (std::getline(in, str))
    {
        // Line contains string of length > 0 then save it in vector
        if(str.size() > 0)
            vecOfStrs.push_back(str);
    }
    //Close The File
    in.close();
    return true;
}

std::string Discourse::GetSequentialSentence(){
	if ( m_seq_index > (this->m_sayings.size() - 1) ) {
		return GetRandomSentence();
	}
	int i = m_seq_index;
	++m_seq_index;
	return this->m_sayings[i];
}

std::string Discourse::GetRandomSentence() {
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, this->m_sayings.size()-1); // define the range
	return this->m_sayings[(int)distr(gen)];
}
