#include "xmas.h"

// main loop
int main(){
	xmas_setup();

	unsigned char n;
	while(1){
		SET_CTRL_BYTE(0);
		for(n = 1; n < 8; n++){
			LED_ON(n);
			tree_control(1000);
		}
	}

	return 0;
}
