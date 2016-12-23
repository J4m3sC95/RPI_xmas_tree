#include "xmas.h"
#define DELAY_TIME 100

// main loop
int main(){
	xmas_setup();
	
	unsigned char n;
	SET_CTRL_BYTE(0);
	while(1){
		for(n = 1; n < 8; n++){
			LED_ON(n);
			tree_control(DELAY_TIME);
		}
		for(n = 1; n < 8; n++){
			LED_OFF(n);
			tree_control(DELAY_TIME);
		}	
		for(n = 7; n > 0; n--){
			LED_ON(n);
			tree_control(DELAY_TIME);
		}	
		for(n = 7; n > 0; n--){
			LED_OFF(n);
			tree_control(DELAY_TIME);
		}			
	}

	return 0;
}
