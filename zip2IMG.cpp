// zip2IMG.cpp: define o ponto de entrada para o aplicativo.
//

#include "zip2IMG.h"

using namespace std;

int main(int argc, char* argv[]) {
	for (int i = 1; 1 < argc; i++) {
		std::string arg = argv[i];

		if (arg == "help") {
			printf("Avaiable arguments: \n");
		}
		else if (arg == "-i") {
			return 0;
		}
	}
	return 0;
}
