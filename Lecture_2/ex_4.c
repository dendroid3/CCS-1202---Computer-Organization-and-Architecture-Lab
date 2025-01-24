#include <stdio.h>
 
#define MEMORY_SIZE 10  // Size of the memory array as a contant

// Memory and CPU Register
int memory [MEMORY_SIZE];
int register1;

void memoryToRegister (int address) {
  // Check if memory address is within the valid range

  if (address >= 0 && address < MEMORY_SIZE) {
    memory[address] = register1;
    printf("Data %d transferred from memory[%d] to register\n", register1, address);
  } else {
    printf("Memory address out of range\n");
  }
}

void initializeMemory () {
  for (int i = 0; i < MEMORY_SIZE; i++) {
    memory[i] = i * 10;
  } 
}

int main () {
  initializeMemory ();

  printf("Initialize Memory\n");

  for (int i = 0; i < MEMORY_SIZE; i++) {
    printf("memory[%d] = %d\n", i, memory[i]);
  }

  // Transfer data from memory[2] to register
  memoryToRegister(2);

  // Modify the data in the register (eg add 50 to the value)
  register1 += 50;

  // Transfer data from register to memory[5]
  memoryToRegister(5);

  // Display the updated contents of memory after transfer
  printf("Memory after transfer\n");
  for (int i = 0; i < MEMORY_SIZE; i++) {
    printf("memory[%d] = %d\n", i, memory[i]);
  }

  return 0;
}
