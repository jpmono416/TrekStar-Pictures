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
	int choice, wantProj, matChoice, editProj;
	FileHandler filehandler;
	Project currProject, fakeProject;
	Stack stack = filehandler.importData();
	bool cont = true;
	std::string con = "n";
	int dataPos = 1;

	bool quit = false;
	while (quit == false)
	{
		std::cout << "Your Options Are: \n\n 1. Create New Project \n 2. Edit a Project or it's materials \n 3. Remove Project \n 4. Save and exit \n\n Option: ";
		std::cin >> choice;
		system("CLS");
		switch (choice)
		{
		case 1:
			stack.addElem(currProject.newProject());
			break;
		case 2:
			if (stack.getAmountOfElements() > 0) {
				//DISPLAY EVERY PROJECT IN STACK
				for (int i = 0; i < stack.getAmountOfElements(); i++) {
					currProject = stack.getData()[i];
					std::cout << "Project ID = " << currProject.getProjectID() << "\t\t Film Title: " << currProject.getTitle() << std::endl;
				}
				std::cout << "\nPlease enter the project ID you would like to edit: ";
				std::cin >> wantProj;
				bool found;
				for (int j = 0; j <= stack.getAmountOfElements(); j++) {
					if (stack.getData()[j].getProjectID() == wantProj) {
						dataPos = j;
						found = true;
					}
				}
				if (found) {
					system("CLS");
					std::cout << "Selected Project\n" << std::endl;
					std::cout << currProject.getProjectID() << " " << currProject.getTitle() << std::endl;
					//Ask what it want's to change (Title Runtime Director Language) OR Material
					std::cout << "\nYour options are:\n  1, Edit project\n  2, Add material\n  3, Edit Material \n  Option: ";
					std::cin >> matChoice;
					switch (matChoice) {
					case 1:
						while (cont) {
							std::string z;
							int x;
							system("CLS");
							std::cout << "\n Your Edit Options are:\n 1. Film Title \n 2. Summary\n 3. release Date\n 4. Genre\n 5.Locations\n 6. Languages\n 7. Film Status\n 8. Ticket Sales\n 9.Runtime\n 10. keywords\n";
							std::cin >> (editProj);
							switch (editProj) {
							case 1:
								std::cout << "New Title: ";
								std::cin >> z;
								stack.getData()[dataPos].setTitle(z);
								break;
							case 2:
								std::cout << "New Summary: ";
								std::cin >> z;
								stack.getData()[dataPos].setSummary(z);
								break;
							case 3:
								std::cout << "New Release Date (##/##/####): ";
								std::cin >> z;
								stack.getData()[dataPos].setReleaseDate(z);
								break;
							case 4:
								std::cout << "New Genre (1. Comedy 2. Horror 3. Romance 4. SciFi 5. Adventure 6. Documentary 7. Action 8. War 9. Musical: ";
								std::cin >> x;
								stack.getData()[dataPos].setGenre(x);
								break;
							case 5:
								std::cout << "New Location (1, UK  2, USA  3, China  4, Germany  5, France  6, Netherlands  7, Italy  8, Russia  9, India): ";
								std::cin >> x;
								stack.getData()[dataPos].setLocations(x);
								break;
							case 6:
								std::cout << "New Language (1, English  2, Spanish  3, Chinese  4, German  5, French  6, Dutch  7, Italian  8, Russian  9, Hindi): ";
								std::cin >> x;
								stack.getData()[dataPos].setLanguages(x);
								break;
							case 7:
								std::cout << "Film Status (1, Unreleased  2, Now Playing  3, Released): ";
								std::cin >> x;
								stack.getData()[dataPos].setFilmStatus(x);
								break;
							case 8:
								std::cout << "Ticket Sales: ";
								std::cin >> x;
								stack.getData()[dataPos].setTicketSales(x);
								break;
							case 9:
								std::cout << "Runtime in minutes: ";
								std::cin >> x;
								stack.getData()[dataPos].setRuntime(x);
								break;
							case 10:
								std::cout << "Key Words: ";
								std::cin >> z;
								stack.getData()[dataPos].setKeywords(z);
								break;
							}
							std::cout << "Edit another part of the project (y/n)?";
							std::cin >> con;
							if (con == "n" || con == "N") {
								cont = false;
							}
						}
						break;
					case 2:
						newMaterial();
						break;
					case 3:

						break;
					}
					//Ask which part of Material it wants to change
					//Change the piece of Material.



				}
				else {
					std::cout << "Project Not Found :(\n";
				}
			}
			else {
				std::cout << "There are no projects\n";
			}
			break;
		case 3:
			if (stack.getAmountOfElements() > 0) {
				//DISPLAY EVERY PROJECT IN STACK
				for (int i = 0; i < stack.getAmountOfElements(); i++) {
					currProject = stack.getData()[i];
					std::cout << "Project ID = " << currProject.getProjectID() << "\t\t Film Title: " << currProject.getTitle() << std::endl;
				}
				std::cout << "\nPlease enter the project ID you would like to edit: ";
				std::cin >> wantProj;
				bool found;
				for (int j = 0; j <= stack.getAmountOfElements(); j++) {
					if (stack.getData()[j].getProjectID() == wantProj) {
						stack.getData()[j] = Project();
						found = true;
					}
				}
				if (found) {
					system("CLS");
					std::cout << "Selected Project\n" << std::endl;
					std::cout << currProject.getProjectID() << " " << currProject.getTitle() << std::endl;

					stack.removeFromAmount();

				}
				else {
					std::cout << "Project Not Found :(\n";
				}
			}
			else {
				std::cout << "There are no projects\n";
			}

			break;
		case 4:
			filehandler.saveAllChanges(stack);
			quit = true;
			exit(0);
		default:
			break;
		}
	}
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
