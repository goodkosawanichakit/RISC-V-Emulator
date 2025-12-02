#include "opcodes.h"
#include "riscv.h"
#include <inttypes.h>
#include <stdio.h>
#include <sys/types.h>

void exec_addi(RISCV_CPU *cpu, uint32_t inst);
void exec_sw(RISCV_CPU *cpu, uint32_t inst);
void exec_jal(RISCV_CPU *cpu, uint32_t inst);

void cpu_exec(RISCV_CPU *cpu, uint32_t inst) {
  uint32_t opcode = GET_OPCODE(inst);
  cpu->regs[0] = 0;

  switch (opcode) {
  case OP_ALU_I: // 0x13
    exec_addi(cpu, inst);
    break;

  case OP_STORE: // 0x23
    exec_sw(cpu, inst);
    break;

  case OP_JAL: // 0x6F
    exec_jal(cpu, inst);
    break;

  default:
    printf("Unknown Opcode: 0x%X\n", opcode);
    break;
  }
}
