#include <wiringPi.h>

// Pin definitions
#define NODE_A 29
#define NODE_B 24
#define NODE_C 25
#define NODE_D 28
// time for which LEDs are on in loop
#define LED_ON_TIME 1

// macros to add/remove an led from the control byte
unsigned char tree_control_byte = 0;
#define LED_ON(n) (tree_control_byte |= (1 << (n-1)))
#define LED_OFF(n) (tree_control_byte &= (!(1<<(n-1)))) 

// function definitions
void tree_control(unsigned char control_byte, unsigned int LED_delay);
void LED_control(unsigned char n);

// main loop
int main(){
	wiringPiSetup();

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

// function to update LEDs and keep them illuminated for given time period
void tree_control(unsigned char control_byte, unsigned int LED_delay){
	unsigned char n;
	if(control_byte == 0){
		delay(LED_delay);
	}
	else{
		unsigned long prevTime = millis();
		while((millis() - prevTime) < LED_delay){
			for(n = 1; n < 8; n++){
				if(control_byte & (1 << (n-1))){
					LED_control(n);
					delay(LED_ON_TIME);
				}
			}
		}
	}
}

// Takes an LED number and illuminates that LED
void LED_control(unsigned char LED_number){
	unsigned char anode, cathode;

	// set all pins to inputs
	pinMode(NODE_A, INPUT);
	pinMode(NODE_B, INPUT);
	pinMode(NODE_C, INPUT);
	pinMode(NODE_D, INPUT);

	switch(LED_number){
		case 1:{anode = NODE_C; cathode = NODE_D;}break;
		case 2:{anode = NODE_D; cathode = NODE_C;}break;
		case 3:{anode = NODE_D; cathode = NODE_B;}break;
		case 4:{anode = NODE_B; cathode = NODE_D;}break;
		case 5:{anode = NODE_A; cathode = NODE_B;}break;
		case 6:{anode = NODE_B; cathode = NODE_A;}break;
		// rename top LED to LED 7 rather than 0
		case 7:{anode = NODE_C; cathode = NODE_A;}break;
		default: {return;}break;
	}

	// setup the anode and cathode as outputs and to the relevant logic levels
	pinMode(anode, OUTPUT);
	pinMode(cathode, OUTPUT);
	digitalWrite(cathode, LOW);
	digitalWrite(anode, HIGH);
}
