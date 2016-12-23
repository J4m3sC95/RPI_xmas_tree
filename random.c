#include "xmas.h"
#include <stdlib.h>

int main(){
	xmas_setup();

	while(1){
		SET_CTRL_BYTE(rand());
		tree_control(100);
	}
}
