#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class Discourse {
	private:
	// idea: index many lists of sayings by keys words
	// try to find a key word from user input in the "sayings" dict
	int m_seq_index = 0;
	std::vector<std::string> m_sayings;
	bool getFileContent(std::string, std::vector<std::string>&);
	public:
	Discourse();
	/* std::string FindSentence(); */
	// gets sentences sequentially, until it runs out, and then it just randomly grabs sentences
	std::string GetSequentialSentence();
	std::string GetRandomSentence();
};

