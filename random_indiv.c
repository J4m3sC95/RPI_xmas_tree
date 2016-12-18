#include "xmas.h"
#include <stdlib.h>

int random_LED = 0;
int prev_LED = 0;

int main(){
	xmas_setup();

	while(1){
		tree_control_byte = 0;
		do{
			random_LED = (rand() % 7) + 1;
		}while (random_LED == prev_LED);
		prev_LED = random_LED;
		
		LED_ON(random_LED);
		tree_control(tree_control_byte, 100);
	}
}
