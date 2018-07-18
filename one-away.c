// Create a program that determines if two strings are at most
// one edit away from each other. Insertion or replace may be used.

// Author: Charles Celerier
// Date: 17 JUL 18
// Time to write: 30 min
// Used Internet for syntax/library help: Yes

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool oa( char* a, char* b, int sofar ) {
	// DEBUG
	//printf( "CALL oa( %s, %s, %d )\n", a, b, sofar );
	
	// end condition
	if ( *a == '\0' || *b == '\0' ) {
		if ( strlen( a ) + strlen( b ) + sofar > 1 ) return false;
		else return true;
	}

	// stopping criteria
	// !! carefeul about size_t return type from strlen
	if ( (int)strlen( a ) - (int)strlen( b ) + sofar > 1 ) return false;
	if ( (int)strlen( b ) - (int)strlen( a ) + sofar > 1 ) return false;

	return oa( a + 1, b + 1, sofar + ( *a == *b ? 0 : 1 ) )
		|| oa( a, b + 1, sofar + 1 )
		|| oa( a + 1, b, sofar + 1 );
}

bool one_away( char* a, char* b ) {
	return oa( a, b, 0 );
}

int main( int argc, char* argv[] ) {
	printf( "%s, %s: %s%s", argv[1], argv[2]
				,	one_away( argv[1], argv[2] ) ? "true" : "false", "\n"
				);
	return 0;
}


