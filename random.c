#include "xmas.h"
#include <stdlib.h>

int main(){
	xmas_setup();

	while(1){
		tree_control(rand(), 100);
	}
}
