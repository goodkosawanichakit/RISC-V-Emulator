#include "riscv.h"
#include <stdio.h>

int main() {
  RISCV_CPU cpu = {0};
  cpu.regs[1] = 5;

  printf("--- Simulation Start ---\n");

  // Load Program
  // ADDI: x2 = x1 + 10
  uint32_t inst_addi = 0x00A08113;
  cpu_exec(&cpu, inst_addi);

  // uint32_t inst_jal = ...;
  // cpu_exec(&cpu, inst_jal);

  printf("--- Simulation End ---\n");
  printf("x1: %d, x2: %d\n", cpu.regs[1], cpu.regs[2]);

  return 0;
}
