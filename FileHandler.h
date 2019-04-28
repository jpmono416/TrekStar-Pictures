#pragma once
#include <string>
#include "Project.h"
#include "Stack.h"
#include <fstream>
#include <unordered_map>

class FileHandler
{
public:
	FileHandler();
	~FileHandler();

	bool saveAllChanges(Stack projects);
	std::string getFileContent() { return this->fileContent; }
	Stack importData();
	Materials parseMaterialCSV(std::string text);
	Project parseProjectCSV(std::string text);
	std::vector<std::string> splitStrings(std::string, char delim = ',');

	template<typename Out>
	void split(const std::string &s, char delim, Out result);

private:
	std::string fileContent;
	const std::string separator = ",";
	std::ofstream projectsStream;
	//std::vector<Materials> materials;
	std::unordered_multimap<int,Materials> materialsMap;
};

