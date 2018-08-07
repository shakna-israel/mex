#ifndef MEX_UTILS

#ifdef _WIN32
#include <Windows.h>
#else
#include <sys/stat.h>
#endif

int fileExists(const char* filename) {
  #ifndef _WIN32
  struct stat o;
  int result = stat(filename, &o);
  return result == 0;
  #else
  return GetFileAttributes(filename) != INVALID_FILE_ATTRIBUTES;
  #endif
}

int fileReadable(const char* filename) {
  FILE* fptr = fopen(filename, "r");
  if(fptr != NULL) {
    fclose(fptr);
    return 1;
  } else {
    return 0;
  }
}

#define MEX_UTILS
#endif
