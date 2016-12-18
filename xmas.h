// Pin definitions
#define NODE_A 29
#define NODE_B 24
#define NODE_C 25
#define NODE_D 28
// time for which LEDs are on in loop
#define LED_ON_TIME 1

// macros to add/remove an led from the control byte
unsigned char tree_control_byte;
#define LED_ON(n) (tree_control_byte |= (1 << (n-1)))
#define LED_OFF(n) (tree_control_byte &= (!(1<<(n-1)))) 

// function definitions
void xmas_setup();
void tree_control(unsigned char control_byte, unsigned int LED_delay);
void LED_control(unsigned char n);