#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent the CPU with registers and a program counter
typedef struct {
    int register1; // General purpose register 1
    int register2; // General purpose register 2 (Unused in this code)
    int program_counter;
} CPU;

// Function to fetch, decode, and execute an instruction
void fetchDecodeExecute (CPU *cpu, char *instruction) {
  int operand1, operand2;
  char operation;

  sscanf(instruction, "%c %d %d", &operation, &operand1, &operand2);
  printf("The operation is: %c, operand1: %d, operand2: %d\n", operation, operand1, operand2);

  // Execute the instruction based on the operation
  switch (operation) {
    case 'a':
      cpu->register1 = operand1 + operand2;
      break;
    case 's':
      cpu->register1 = operand1 - operand2;
      break;
    case 'm':
      cpu->register1 = operand1 * operand2;
      break;
    case 'd':
      cpu->register1 = operand1 / operand2;
      break;
    default:
      printf("Invalid operation\n");
      return;
  }

  cpu->program_counter++;
}

int main () {
  CPU cpu = {0};
  char instruction[20];

  // Infinite loop to fetch, decode, and execute instructions until user exits
  while (1) {
    printf("Enter an instruction (e.g., 'a 1 2' to add 1 and 2): or 'exit' to exit\n");
    fgets(instruction, 20, stdin);

    // Exit the loop if the user enters 'exit'
    if (strncmp(instruction, "exit", 4) == 0) {
      break;
    }

    fetchDecodeExecute(&cpu, instruction);
    printf("Result in register: %d, program counter %d\n", cpu.register1, cpu.program_counter);  
  }

  return 0;
}
