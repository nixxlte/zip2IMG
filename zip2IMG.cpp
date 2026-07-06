#include "zip2IMG.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Code by NixxLTE -w-

std::string prefix = "--";
std::string file;

int main(int argc, char* argv[]) {
	for (int i = 1; 1 < argc; i++) {
		std::string arg = argv[i];

		if (arg == (prefix + "help")) {
			printf("Avaiable arguments: \n");
			return 0;
		}
		else if (arg == (prefix + "install")) {
			#ifdef _WIN32
				system("winget install -e --id Google.Brotli");
				system("winget install -e --id 7zip.7zip");
			#elif __linux__
				system("sudo apt update && sudo apt install brotli 7zip -y");
			#endif
		}
		else if (arg == (prefix + "zip")) {
			if (i + 1 < argc) {
				file = argv[i + 1];

				#ifdef _WIN32
					std::string cmd = "\"C:\\Program Files\\7-zip\\7z.exe\" >nul 2>&1";
					int result = system(cmd.c_str());
				#elif __linux__
					std::string cmd = "7z t \"" + file + "\" >nul 2>&1";
					int result = system(cmd.c_str());
				#endif
				if (result == 0){printf("zip file is:\033[3m valid\033[0m\n");}
				else if (result != 0){
					printf("zip file is:\033[3m invalid\033[0m\n");
					return 1;
				}

				printf("Make sure you have all the dependencies installed.\n if you dont have, run zip2img --install\n");
				#ifdef _WIN32
					system("\"C:\\Program Files\\7-zip\\7z.exe\" > version.txt");
					// std::cout << "\"C:\\Program Files\\7-zip\\7z.exe\" > version.txt" << endl;
					std::ifstream text("version.txt");
					if (!text.is_open()) {
						std::cerr << "Cant get version.txt\n";
					}
					std::string line;
					if (std::getline(text, line)) {
						std::cout << line << std::endl;
					}
					text.close();
					system("del /f version.txt");
				#endif
				
				if (result == 0) {
					#ifdef _WIN32
						cmd = "\"C:\\Program Files\\7-zip\\7z.exe\" x \"" + file + "\" ";
						std::cout << "\n" << cmd << endl;
						system((cmd).c_str());
					#elif __linux__
						system("7z \"" + file + "\"");
					#endif
				}
			}
			else {
				printf("Please select a zip file");
				return 1;
			}
		}
	}
}
