// WrittenBy: ZihShuen 
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
    printf("Hello! This is just a practice to play around with endian-ness to get used to data handling.\n\n");
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
    
    // Set UserInput
    BYTE data[8]={0}; // Fill with zeros


    // BYTE 0: Fixed size of data
    data[0] = sizeof(data);
    printf("BYTE0 = 0x%02X\n",data[0]);

    // BYTE 1: 0x00= Fill MSB with boolean `isSystemReady` and LSB with `isControlReady`
    if (input.isSystemReady)
        data[1] |= 0x10; // Set high nibble to 1 at 0x10
    if (input.isControlReady)
        data[1] |= 0x01; // Set low nibble to 1

    printf("BYTE1 = 0x%02X\n",data[1]);

    // BYTE 2: 0x00= Fill with unsigned8bit variable `position`
    data[2]= static_cast<BYTE>(input.position);
    printf("BYTE2 = 0x%02X\n",data[2]);

    // BYTE 3: 0x00= Fill with signed8bit variable `direction` (-1:Back,0:Center,1:Front)
    data[3]= static_cast<BYTE>(input.direction);
    printf("BYTE3 = 0x%02X\n",data[3]);

    // BYTE 4&5: 0x00=  Fill BYTE4 and BYTE5 with uint16_t `power` in little-endian order (e.g., 0xABCD → BYTE4=0xCD, BYTE5=0xAB)
    data[4] = static_cast<BYTE>(input.power & 0xFF);         // Mask the lower byte with 0xFF
    data[5] = static_cast<BYTE>((input.power >> 8) & 0xFF);  // Shift right by 8 bits, mask with 0xFF
    printf("BYTE4 = 0x%02X\n",data[4]);
    printf("BYTE5 = 0x%02X\n",data[5]);

    // BYTE 6&7: 0x00=  Fill BYTE6 and BYTE7 with uint16_t `speed` in big-endian order (e.g., 0xABCD → BYTE4=0xAB, BYTE5=0xCD)
    data[6] = static_cast<BYTE>((input.speed >> 8) & 0xFF);  // Shift right by 8 bits, mask with 0xFF
    data[7] = static_cast<BYTE>(input.speed & 0xFF);         // Mask the lower byte with 0xFF

    printf("BYTE6 = 0x%02X\n",data[6]);
    printf("BYTE7 = 0x%02X\n",data[7]);

    printf("\nFullByte = { ");
    for (int i = 0; i < sizeof(data); ++i) {
        printf("0x%02X ", data[i]);
    }
    printf("}\n");

    system("pause");
}
