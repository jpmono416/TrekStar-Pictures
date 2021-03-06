// TrekStar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Materials.h"
#include "Project.h"
#include "Stack.h"
#include "FileHandler.h"
#include <iostream>
#include <string>
#include <algorithm>
void newMaterial();
bool isInputStringValid(std::string stringCheck);
int main()
{
	std::string command = "";
	int choice, wantProj, matChoice;
	FileHandler filehandler;
	Project currProject, fakeProject;
	Stack stack = filehandler.importData();

	while (command != "quit")
	{
		std::cout << "Please Enter a command...\n"; //Currently only "Admin" works
		std::cin >> command;
		std::transform(command.begin(), command.end(), command.begin(), ::tolower);
		if (command == "admin") {
			std::cout << "Your Options Are: \n 1. Create New Project \n 2. Edit a Project or it's materials \n 3. Remove Project \n";
			std::cin >> choice;
			switch (choice)
			{
			case 1:
				stack.addElem(currProject.newProject());
				break;
			case 2:
				if (stack.getAmountOfElements() > 0) {
					//DISPLAY EVERY PROJECT IN STACK
					for (int i = 0; i <= stack.getAmountOfElements(); i++) {
						currProject = stack.getData()[i];
						std::cout << i << ". " << currProject.getTitle() << " " << currProject.getProjectID() << " " << currProject.getTitle() << " " << currProject.getRuntime() << std::endl;
					}
					std::cout << "Please Select project ID you would like to edit.";
					std::cin >> wantProj;
					bool found;
					for (int j = 0; j <= stack.getAmountOfElements(); j++) {
						if (stack.getData()[j].getProjectID() == wantProj) {
							currProject = stack.getData()[j];
							found = true;
						}
					}
					if (found) {
						//Display Found Project
						std::cout << currProject.getProjectID() << " " << currProject.getTitle() << std::endl;
						//Ask what it want's to change (Title Runtime Director Language) OR Material
						//Change x Or ask which Material it wants to change (List Materials Or Add new)
						std::cout << "Type 1 if you want to add a new Material";
						std::cin >> matChoice;
						switch (matChoice) {
						case 1:
							newMaterial();
						}
						//Ask which part of Material it wants to change
						//Change the piece of Material.



					}
					else {
						std::cout << "Project Not Found :(";
					}
				}
				else {
					std::cout << "There are no projects";
				}
				break;
			case 3:
				//Ask what project
				//Remove project
				break;
			default:
				break;
			}

		}
		else
		{
			std::cout << "Invalid Option. Please try a different command\n";
		}

	}
	filehandler.saveAllChanges(stack);
	exit(0);
}

void newMaterial() {
	int ID, packaging, language, videoFormats, audioFormats, materialType;
	std::string title, frameAspect, mainContent;
	long runTime;
	float retailPrice;
	bool subtitles;


	Materials newMaterial;
	Project currProject;

	std::cout << "\nNew ID: ";
	std::cin >> ID;
	newMaterial.setid(ID);

	newMaterial.setProjectID(currProject.getProjectID());

	std::cout << "Select Material Type: \n 1.Single DVD \n 2. Double DVD \n 3.BluRay \n 4.ComboBox \n 5.VHS";
	std::cin >> materialType;
	newMaterial.setMaterialType(materialType);

	std::cout << "\nNew Title: ";
	std::cin >> title;
	newMaterial.setTitle(title);

	std::cout << "\nNew Runtime: ";
	std::cin >> runTime;
	newMaterial.setRunTime(runTime);

	std::cout << "\nNew Main Content: ";
	std::cin >> mainContent;
	newMaterial.setMainContent(mainContent);

	std::cout << "\nNew Retail Price: ";
	std::cin >> retailPrice;
	newMaterial.setRetailPrice(retailPrice);

	std::cout << "\nSubtitles (1 = True or 0 = False): ";
	std::cin >> subtitles;
	newMaterial.setSubtitles(subtitles);

	std::cout << "\nNew Frame Aspect: ";
	std::cin >> frameAspect;
	newMaterial.setFrameAspect(frameAspect);

	std::cout << "\nSelect Package: \n 1.Cardboard \n 2.Plastic \n";
	std::cin >> packaging;
	newMaterial.setPackaging(packaging);

	std::cout << "\nSelect Language: \n 1.English \n 2.Spanish \n 3.Chinese";
	std::cin >> language;
	newMaterial.setLanguage(language);

	std::cout << "\nSelect Video Format: \n 1.MP4 \n 2.AVI \n 3.WPA";
	std::cin >> videoFormats;
	newMaterial.setVideoFormat(videoFormats);

	std::cout << "\nSelect Audio Format: \n 1.Dolby \n 2.Dolby Digital \n 3.MPEG-1 \n 4.PCM \n 5.DTS";
	std::cin >> audioFormats;
	newMaterial.setAudioFormat(audioFormats);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
