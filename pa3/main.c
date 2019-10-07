#include "anagrams.h"
//FILE *stdError = stderr;


int main( int argc, char *argv[] )
{
  struct anagramInfo anaStruct;
  if( (argc == 3) || (argc == 1) )
  {
    if( argc == 1 )
    {
      processDB( &anaStruct );
      userInteractive( &anaStruct );
    }
    else if( (strcmp(argv[1], "--build") == 0) && (strcmp(argv[2], "/usr/dict/words") == 0) )
    {
      buildDB(argv[2]);
    }
    else
    {
      (void)fprintf( stderr, "Usage: %s [--build dictionary_file]\n", argv[0] );
    }
  }
  else
  {
    (void)fprintf( stderr, "Usage: %s [--build dictionary_file]\n", argv[0] );
  }
  free(anaStruct.anagramPtr);
  return 0;
}
