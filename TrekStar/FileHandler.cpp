#include "pch.h"
#include "FileHandler.h"

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
	const int arrayLength = sizeof(projects) / sizeof(Project);
	this->projectsStream.open("projects.csv");

	for (unsigned int counter = 0; counter <= arrayLength; ++counter)
	{
		Project pr = projects[counter];
		this->projectsStream << pr << std::endl;
		materialsStream << pr.getMaterials << std::endl;
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
		 materials.emplace_back(parseMaterialCSV(line));
	}
	
	const int arraySize = 20;
	Project projects[arraySize];

	file.close();
	file.open("projects.csv");
	for (unsigned int counter = 0; std::getline(file, line); ++counter)
	{
		projects[counter] = parseProjectCSV(line).setMaterials(materials.at(counter);
	}

	Stack stack = Stack();

	
}

Materials FileHandler::parseMaterialCSV(std::string text)
{
	std::vector<std::string> atts = this->splitStrings(text);
	Materials tempMat = Materials();

	// Could create custom constructor to receive
	// vector of strings and do this automatically
	tempMat.setid(stoi(atts.at(0)));
	tempMat.setTitle(atts.at(1));
	tempMat.setVideoFormat(stoi(atts.at(2)));
	tempMat.setAudioFormat(stoi(atts.at(3)));
	tempMat.setRunTime(strtol(atts.at(4).c_str(),nullptr,0));
	tempMat.setMainContent(atts.at(5));
	tempMat.setLanguage(stoi(atts.at(6)));
	tempMat.setRetailPrice(stof(atts.at(7)));
	tempMat.setSubtitles(stoi(atts.at(8)));
	tempMat.setFrameAspect(atts.at(9));
	tempMat.setPackaging(stoi(atts.at(10)));
	tempMat.setMaterialType(stoi(atts.at(11)));

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

	proj.setMaterials(this->materials);
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
	this->split(text, delim, std::back_inserter(elements));
	return elements;
}