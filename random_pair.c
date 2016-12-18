#include "xmas.h"
#include <stdlib.h>

int random_LED[] = {0,0};
int prev_LED[] = {0,0};

int redo = 0;

int main(){
	xmas_setup();

	while(1){
		tree_control_byte = 0;
		do{
			random_LED[0] = (rand() % 7) + 1;
			random_LED[1] = (rand() % 7) + 1;
			if((random_LED[0] == random_LED[1]) || ((random_LED[0] == prev_LED[0]) && (random_LED[1] == prev_LED[1])) || ((random_LED[0] == prev_LED[1]) && (random_LED[1] == prev_LED[0]))){
				redo = 1;
			}
			else{
				redo = 0;
			}
		}while (redo);
		prev_LED[0] = random_LED[0];
		prev_LED[1] = random_LED[1];
		
		LED_ON(random_LED[0]);
		LED_ON(random_LED[1]);
		tree_control(tree_control_byte, 100);
	}
}
