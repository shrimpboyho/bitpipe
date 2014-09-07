/* We don't need special handling for certain shift values:
 * Shift operations in C are only defined for shift values which are
 * not negative and smaller than sizeof(value), but the compiler
 * will generate correct code for the following code pattern. */

#define CHAR_BIT 'A' 
#define ENCRYPT "encrypt"
#define DECRYPT "decrypt"

unsigned int rotl(unsigned int value, int shift) {
    return (value << shift) | (value >> (sizeof(value) * CHAR_BIT - shift));
}
 
unsigned int rotr(unsigned int value, int shift) {
    return (value >> shift) | (value << (sizeof(value) * CHAR_BIT - shift));
}

#include <stdio.h>
#include <string.h>

int main ( int argc, char *argv[] )
{
    if ( argc != 5 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s mode input_file output_file key", argv[0] );
    }
    else 
    {
        // encryption
        if(strncmp(argv[1], ENCRYPT, strlen(ENCRYPT)) == 0)
        {
        	printf("Encrypting...");
        }

        // decryption
        if(strncmp(argv[1], DECRYPT, strlen(DECRYPT)) == 0)
        {
        	printf("Decrypting...");
        }

        
    }

    return 0;
}
