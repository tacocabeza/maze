#include "process.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {

  int opt;
  bool verbose = false;

  char *path = "";

  while ((opt = getopt(argc, argv, "v")) != -1) {
    switch (opt) {
    case 'v':
      verbose = true;
      break;
    default:
      exit(EXIT_FAILURE);
    }
  }

  printf("verbose mode %d\n", verbose);

  for (int i = optind; i < argc; i++) {
    printf("Non-option argument %s\n", argv[i]);
    path = argv[i];
  }

  if (*path == 0) {
    printf("Missing required argument <path_to_maze_png>\nExiting..\n");
    exit(EXIT_FAILURE);
  }

  read_png(path);

  exit(EXIT_SUCCESS);
}
