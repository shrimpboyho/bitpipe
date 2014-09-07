#include <stdio.h>
#include <string.h>
#include <limits.h>

/* We don't need special handling for certain shift values:
 * Shift operations in C are only defined for shift values which are
 * not negative and smaller than sizeof(value), but the compiler
 * will generate correct code for the following code pattern. */

#define ENCRYPT "encrypt"
#define DECRYPT "decrypt"

unsigned int rotl(unsigned int value, int shift) {
    return (value << shift) | (value >> (sizeof(value) * CHAR_BIT - shift));
}
 
unsigned int rotr(unsigned int value, int shift) {
    return (value >> shift) | (value << (sizeof(value) * CHAR_BIT - shift));
}

void printbits(unsigned int v) {
	for (; v; v >>= 1) 
		putchar('0' + (v & 1));
		putchar('\n');
}

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
        	FILE *ifp;
        	if ((ifp = fopen(argv[2], "rb")) == NULL) {
		        printf("Couldn't open %s for reading\n", argv[2]);
		        return 0;
		    }
		    FILE *ofp = fopen(argv[3], "ab");
		    unsigned int c;
		    do {
		      c = fgetc(ifp);
		      printbits(c);
		      fputc(c, ofp);
		    } while (c != EOF);
		    fclose(ifp);
		    fclose(ofp);
        }

        // decryption
        if(strncmp(argv[1], DECRYPT, strlen(DECRYPT)) == 0)
        {
        	printf("Decrypting...");
        }   
    }
    return 0;
}
