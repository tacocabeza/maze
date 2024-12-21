#include "process.h"
#include "stdio.h"

void read_png(char *filename) {
  printf("reading file: %s\n", filename);

  FILE *file;

  if ((file = fopen(filename, "r"))) {
    fclose(file);
    printf("Read File %s\n", filename);
  } else {
    printf("File %s does not exist!\n", filename);
  }
}
