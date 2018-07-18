// Identify permutation of palindromes.

// Author: Charles Celerier
// Date: 17 JUL 18
// Time to make: 13:49
// Used Internet for help? No.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CHAR_RANGE 26 // a - z

bool pp( char *s, uint hits ) {
	// DEBUG
	printf( "pp( %s, 0x%x )\n", s, hits );
	if ( *s == '\0' ) {
		return (hits & (hits - 1)) == 0; // bit trick for at most one bit set
	}

	return pp( s + 1, *s == ' ' ? hits : hits ^ ( 1 << ((int)*s % CHAR_RANGE)) );
}

bool palindrome_permutation( char* s ) {
	return pp( s, 0 );
}

int main ( int argc, char* argv[] ) {
	printf( "%s: %s\n", argv[1], palindrome_permutation( argv[1] ) ? "true" : "false" );
	return 0;
}
