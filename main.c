#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("Hello World!\n");

  int opt;
  bool verbose = false;

  char *path;

  while ((opt = getopt(argc, argv, "vf:")) != -1) {
    switch (opt) {
    case 'v':
      verbose = true;
      break;
    case 'f':
      path = optarg;
      break;
    case ':':
      printf("Option needs a value\n");
      break;
    case '?':
      if (optopt == 'f')
        fprintf(stderr, "Option -%c requires an argument.\n", optopt);
      else if (isprint(optopt))
        fprintf(stderr, "Unknown option `-%c'.\n", optopt);
      else
        fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
      exit(EXIT_FAILURE);
    default:
      exit(EXIT_FAILURE);
    }
  }
  printf("verbose=%d; png path: %s\n", verbose, path);

  exit(EXIT_SUCCESS);
}
