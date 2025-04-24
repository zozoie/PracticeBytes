// CreatedBy: ZihShuen 
// Date: 24April2025
//================================================================
// Exercise: 
//  Create a stream of BYTE data based on user input & printout the entire BYTE message in hexadecimal.
//
// BYTE 0: Fixed size of data
// BYTE 1: 0x00= Fill MSB with boolean `isSystemReady` and LSB with `isControlReady`
// BYTE 2: 0x00= Fill with unsigned8bit variable `position`
// BYTE 3: 0x00= Fill with signed8bit variable `direction` (-1:Back,0:Center,1:Front)
// BYTE 4: 0x00=  Fill BYTE4 and BYTE5 with uint16_t `power` in little-endian order (e.g., 0xABCD → BYTE4=0xCD, BYTE5=0xAB)
// BYTE 5: refer above
// BYTE 6: 0x00=  Fill BYTE6 and BYTE7 with uint16_t `speed` in big-endian order (e.g., 0xABCD → BYTE4=0xAB, BYTE5=0xCD)
// BYTE 7: refer above
//
// Check your work: 
//  
//================================================================

#include <iostream>
#include <cstdint>

int main(){
    printf("Hello! This is just a practice to play around with endian-ness to get used to data handling.\n");
    struct userInput{
        bool isSystemReady;
        bool isControlReady;
        uint8_t position;
        int8_t direction;
        uint16_t power;
        uint16_t speed;
    };

    typedef unsigned char BYTE;
    userInput input;
    input.isSystemReady= false;
    input.isControlReady= true;
    input.position = 0xFF;
    input.direction= 1;
    input.power = 0xABCD;
    input.speed = 0xABCD;
    
    system("pause");
}
