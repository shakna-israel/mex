#include <stdio.h>
#include <string.h>

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
  if(argc < 2 || argc > 2 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
    help();
  }
}
