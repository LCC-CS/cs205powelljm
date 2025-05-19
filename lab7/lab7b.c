#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_ROUNDS 10

void usage() {
  printf("Usage:\n");
  printf("\t./large_arrays DIM [ROUNDS]\n\n");
  printf("DIM    - Number elements in each dimension\n");
  printf("ROUNDS - Number of times to fill the array (default: %d)\n", DEFAULT_ROUNDS);
}

int main(int argc, char *argv[]) {
  unsigned long size;
  unsigned long rounds = DEFAULT_ROUNDS;
  if (argc < 2) {
    usage();
    exit(0);
  }

  size = atol(argv[1]);
  unsigned long (*array)[size][size];

  // Set rounds if listed
  if (argc > 2) rounds = atol(argv[2]);
  
  // Create a 3 dimension array
  array = (unsigned long(*)[size][size])malloc(size * size * size * sizeof(unsigned long));

  if (array == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }

  printf("\nFilling a Large Array\n");
  printf("- Dimensions: %ld*%ld*%ld\n", size, size, size);
  printf("- Rounds: %ld\n\n", rounds);
  
  // Fill the array multiple times
  for (unsigned long round = 0; round < rounds; round++) {

    /****************************************************************************
     * Modified loop order: i (outer), j (middle), k (inner) for better cache   *
     * locality, as k is the innermost index, accessing contiguous memory.      *
     ****************************************************************************/

    // Fill the array
    for (unsigned long i = 0; i < size; i++) {
      for (unsigned long j = 0; j < size; j++) {
        for (unsigned long k = 0; k < size; k++) {
          array[i][j][k] = i * j * k;
        }
      }
    }
    
  } // End of rounds
  
  // Free the array memory
  free(array);

  return 0;
}
