/** lab33functs.c
* ===========================================================
* Name: FIRST LAST, DATE
* Section: SECTION
* Project: Lab 33
* ===========================================================  */

#include "lab33functs.h"
#include <string.h>

/** ----------------------------------------------------------
 * @fn void print_bits(void* ptr, int num_bytes)
 * @brief prints char representation of any variables individual bits
 * @param ptr is a pointer to the variable being printed
 * @param num_bytes is the number of bytes in the variable
 * @return void, prints each bit as a character, ends with a new line
 * ----------------------------------------------------------
 */
void print_bits(void* ptr, int num_bytes) {
    // Cast the pointer as an unsigned byte
    uint8_t* byte = ptr;

    // For each byte, (bytes are little endian ordered)
    for (int i = num_bytes - 1; i >= 0; --i) {

        // For each bit, (inside the byte, bits are big endian ordered)
        for (int j = 7; j >= 0; --j) {

            // Print a character 1 or 0, given the bit value
            printf("%c", (byte[i] >> j) & 1 ? '1' : '0');
        }
        
        // Separate bytes
        printf(" ");
    }

    // End with a new line
    printf("\n");
}

int check_bit(int value, int bit){
    int mask = 1  << bit;

    if(value & mask){
        return 1;
    }
    else{
        return 0;
    }
}

int count_bits(int value){
    int count = 0;
    while(value){
        value = value & (value - 1);
        count++;
    }

    return count;
}

int bit_parity(int value){
    int count = 0;

    while(value){
        value = value & (value - 1);
        count++;
    }
    return count%2;
}

int flip_bit(int value, int bit){
    int mask = 1 << bit;
    value = value ^ mask;
    return value;
}

unsigned int simple_checksum(char* string){
     unsigned int checksum = 0;
     while (*string) {
        checksum ^= (unsigned int)(*string); 
        string++; 
    }

    return checksum;
}