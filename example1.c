#include "xmas.h"

// main loop
int main(){
	xmas_setup();

	unsigned char n;
	while(1){
		tree_control_byte = 0;
		for(n = 1; n < 8; n++){
			LED_ON(n);
			tree_control(tree_control_byte, 1000);
		}
	}

	return 0;
}
