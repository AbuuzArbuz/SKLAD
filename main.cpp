#include <iostream>
#include <vector>	
#include <SkladBible.h>



int main(){
	

	int size = 35;

	int i, j;
	for (i = 0; i<15; i++){
		for (j = 0; j<11; j++){
			globalmap[i][j] = 0;
		}
	}
	
	for (i = 0; i<15; i += 2){
		for (j = 1; j<10; j++){
			globalmap[i][j] = -1;
		}
	}
	
	for (i = 1; i<14; i++){
		globalmap[i][5] = 0;
	}
	
	globalmap[0][0] = 1;
	globalmap[14][10] = 1;
	globalmap[0][10]=-1;
	globalmap[14][0]=-1;

	Car car1(6, 2, 0, 0, 1);
	
	int i = 0;
	while(i < 10){
		car1.go();
		++i;
	}



}



