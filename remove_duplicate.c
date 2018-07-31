#include <stdio.h>
#include <stdlib.h>

typedef struct List {
  int car;
  struct List *cdr;
} List_t;

List_t* makeList( size_t N, int const a[static N] ) {
  size_t i;
  List_t* new;
  List_t* last;
  for ( i = N-1, last = NULL ; i < N ; i = i - 1, last = new ) {
    new = malloc( sizeof( List_t ) );
    printf("i = %zu\n", i);
    // printf("adding %d\n", a[i]);
    new->car = a[i];
    new->cdr = last;
  }
  
  return new;
}

void freeList( List_t* l ) {
  for ( ; l != NULL ; ) {
    List_t* toDelete = l;
    
    l = l->cdr;
    free( toDelete );
  }
}

void printList( List_t* l, char* name ) {
  printf( "%s:", name );
  for ( ; l != NULL ; l = l->cdr ) {
    printf( " %d", l->car );
  }
  printf( "\n" );
}

void remove_duplicates( List_t* l ) {
  for ( List_t* cur = l ; cur != NULL ; cur = cur->cdr ) {
    for ( List_t* runner = cur ; runner->cdr != NULL ; runner = runner->cdr ) {
      if ( cur->car == runner->cdr->car ) {
        List_t* new_cdr = runner->cdr->cdr;
        free( runner->cdr );
        runner->cdr = new_cdr;
      }
    }
  }
}

int main ( int argc, char* argv[argc+1] ) {
  int const a[8] = { 1, 1, 129, 2, 3, 3, 129, 2301, };
  List_t* a_list = makeList( 8, a );
  printList( a_list, "a" );
  remove_duplicates( a_list );
  printList( a_list, "a no duplicates" );
  freeList( a_list );
  
  return EXIT_SUCCESS;
}