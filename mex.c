#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

#define VER "2.0.0"

void help(void) {
  printf("%s%s", "mex v", VER);
  printf("%s", "\n----------\n\n");
  printf("%s", "A simple macro expander for Fortran 77.\n");
  printf("%s", "---------------------------------------\n");
  printf("%s", "Usage:\n");
  printf("%s", "mex [file]\n");
  printf("%s", "Note: File *must* end with .mf\n");
}

int main(int argc, char* argv[]) {
  // If argc isn't 2, or the first argument is -h or --help, call help.
  if(argc != 2 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
    help();
    exit(0);
  }
  // argc guaranteed to be 2 from here on.
  // Does the file exist?
  if(fileExists(argv[1]) != 1) {
    fprintf(stderr, "%s", "Unable to access file. Does it exist?\n");
    fprintf(stderr, "%s%s%s", "File: ", argv[1], "\n");
    exit(1);
  }
  // Do we have read permission?
  if(fileReadable(argv[1]) != 1) {
    fprintf(stderr, "%s", "Could not open file. Do you have permission?\n");
    fprintf(stderr, "%s%s%s", "File: ", argv[1], "\n");
    exit(1);
  }
}
