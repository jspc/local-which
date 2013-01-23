/**
   which.c
   jspc - 20120518
   
   Plays better with which
**/


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


int main(int argc, char const *argv[]) {
  char cat[4] = "cat";
  char buffer[64];
  char cmd_txt[128];
  FILE *which_in;
  
  if ( argc < 2 ){
    printf( ANSI_COLOR_RED  "Which what?"   ANSI_COLOR_RESET "\n" );
    return -1;
  }

  if ( argc > 2 ){
    printf( ANSI_COLOR_RED  "Please; one at a time"   ANSI_COLOR_RESET "\n" );
    return -2;
  }

  printf( ANSI_COLOR_MAGENTA "Which: " ANSI_COLOR_GREEN "%s\n" ANSI_COLOR_RESET, argv[1] );

  if ( strncmp(argv[1], cat, 3) == 0 ){
    printf( "Your cat is dead\n" );
  } else {

    sprintf( cmd_txt, "which %s", argv[1] );
    if( !( which_in = popen( cmd_txt, "r" ) ) ){
      exit( 1 );
    }

    while( fgets( buffer, sizeof(buffer), which_in ) !=NULL ){
      printf( "%s", buffer );
    }
  }

  return 0;
}
