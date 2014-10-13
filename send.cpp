/*
 Usage: ./send <system_code> <unit_code> <command>
 system_code is a letter from A to P (case insensitive)
 Valid commands are
   0 for OFF
   1 for ON
   2 for BRIGHT
   3 for DIMMED
 */

#include "x10rf.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    /*
     output RF_PIN and LED_PIN are hardcoded for testing purposes
     see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     for pin mapping of the raspberry pi GPIO connector
     */
    int RF_PIN = 15;
    int LED_PIN = -1;
    char systemCode = argv[1][0];
    int unitCode = atoi(argv[2]);
    int command  = atoi(argv[3]);

    if (wiringPiSetup () == -1) return 1;
	printf("sending systemCode[%c] unitCode[%i] command[%i]\n", systemCode, unitCode, command);
	x10rf myX10RF = x10rf(RF_PIN, LED_PIN, 5);

    switch(command) {
        case 0:
            myX10RF.x10Switch(systemCode, unitCode, OFF);
            break;
        case 1:
            myX10RF.x10Switch(systemCode, unitCode, ON);
            break;
        case 2:
            myX10RF.x10Switch(systemCode, unitCode, BRIGHT);
            break;
        case 3:
            myX10RF.x10Switch(systemCode, unitCode, DIM);
            break;
        default:
            printf("command[%i] is unsupported\n", command);
            return -1;
    }
	return 0;
}
