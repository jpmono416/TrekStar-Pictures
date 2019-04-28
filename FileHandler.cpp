#include "pch.h"
#include "FileHandler.h"
#include <sstream>
#include <array>
FileHandler::FileHandler()
{
}


FileHandler::~FileHandler()
{
}

bool FileHandler::saveAllChanges(Stack proj)
{
	std::ofstream materialsStream;

	Project* projects{ proj.getData() };
	const size_t arrayLength = sizeof(projects) / sizeof(*projects);
	this->projectsStream.open("projects.csv");

	for (unsigned int counter = 0; counter <= arrayLength; ++counter)
	{
		Project pr = projects[counter];
		this->projectsStream << pr << std::endl;
		for (auto material : pr.getMaterials())
		{
			materialsStream << material << std::endl;
		}
	}
	return true;

	projectsStream.open("projects.csv");
	materialsStream.open("materials.csv");
}

Stack FileHandler::importData()
{
	std::ifstream file("materials.csv");
	std::string line;
	
	while(std::getline(file, line))
	{
		Materials mat = parseMaterialCSV(line);
		materialsMap.emplace(mat.getProjectID(), mat);
	}
	
	const int arraySize = 20;
	Project projects[arraySize];

	file.close();
	file.open("projects.csv");
	for (unsigned int counter = 0; std::getline(file, line); ++counter)
	{
		const Project&& pro = parseProjectCSV(line);
		projects[counter] = pro;

		auto itPair = materialsMap.equal_range(pro.getProjectID());

		for (auto count = itPair.first; count != itPair.second; ++count)
		{
			projects[counter].addMaterial(count->second);
		}
	}

	

	Stack stack = Stack();
	stack.setData(projects);
	return stack;
}

Materials FileHandler::parseMaterialCSV(std::string text)
{
	std::vector<std::string> atts = this->splitStrings(text);
	Materials tempMat = Materials();

	// Could create custom constructor to receive
	// vector of strings and do this automatically
	tempMat.setProjectID(stoi(atts.at(0)));
	tempMat.setid(stoi(atts.at(1)));
	tempMat.setTitle(atts.at(2));
	tempMat.setVideoFormat(stoi(atts.at(3)));
	tempMat.setAudioFormat(stoi(atts.at(4)));
	tempMat.setRunTime(strtol(atts.at(5).c_str(),nullptr,0));
	tempMat.setMainContent(atts.at(6));
	tempMat.setLanguage(stoi(atts.at(7)));
	tempMat.setRetailPrice(stof(atts.at(8)));
	tempMat.setSubtitles(stoi(atts.at(9)));
	tempMat.setFrameAspect(atts.at(10));
	tempMat.setPackaging(stoi(atts.at(11)));
	tempMat.setMaterialType(stoi(atts.at(12)));

	return Materials();
}

Project FileHandler::parseProjectCSV(std::string text)
{
	std::vector<std::string> atts = this->splitStrings(text);
	Project proj = Project();

	proj.setProjectID(stoi(atts.at(0)));
	proj.setTitle(atts.at(1));
	proj.setSummary(atts.at(2));
	proj.setReleaseDate(atts.at(3));
	proj.setGenre(stoi(atts.at(4)));
	proj.setRuntime(stoi(atts.at(5)));
	proj.setFilmStatus(stoi(atts.at(6)));
	proj.setTicketSales(stoi(atts.at(7)));
	

	
	for (auto location : this->splitStrings(atts.at(8), ';'))
	{
		proj.setLocations(stoi(location));
	}
	
	for (auto language : this->splitStrings(atts.at(9), ';'))
	{
		proj.setLanguages(stoi(language));
	}

	for (auto keyword : this->splitStrings(atts.at(10), ';'))
	{
		proj.setKeywords(keyword);
	}
	return Project();
}

/*
	Code extracted from: https://stackoverflow.com/a/236803
*/
template<typename Out>
void FileHandler::split(const std::string &s, char delim, Out result) 
{
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) 
	{
		*(result++) = item;
	}
}

std::vector<std::string> FileHandler::splitStrings(std::string text, char delim)
{
	std::vector<std::string> elements;
	if (text.find("[]") != std::string::npos)
	{
		text.erase(std::remove(text.begin(), text.end(), '['), text.end());
		text.erase(std::remove(text.begin(), text.end(), ']'), text.end());
	}
	this->split(text, delim, std::back_inserter(elements));
	return elements;
}