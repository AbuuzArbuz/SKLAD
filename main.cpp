#include <iostream>
#include <vector>	
#include "CarBible.h"



int main() {


	int size = 35;

	int i, j;
	for (i = 0; i<15; i++) {
		for (j = 0; j<11; j++) {
			globalMap[i][j] = 0;
		}
	}

	for (i = 0; i<15; i += 2) {
		for (j = 1; j<10; j++) {
			globalMap[i][j] = -1;
		}
	}

	for (i = 1; i<14; i++) {
		globalMap[i][5] = 0;
	}

	globalMap[0][0] = 1;
	globalMap[14][10] = 1;
	globalMap[0][10] = -1;
	globalMap[14][0] = -1;

	Car car1(6, 2, 0, 0, 1);

	i = 0;
	while (i < 10) {
		car1.go();
		++i;
	}
	int w8me;
	std::cin >> w8me;

	return 0;
}



