#include "riscv.h"
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>

void exec_addi(RISCV_CPU *cpu, uint32_t inst) {
  uint32_t rd = GET_RD(inst);
  uint32_t rs1 = GET_RS1(inst);
  int32_t imm = GET_IMM_I(inst);

  cpu->regs[rd] = cpu->regs[rs1] + imm;
  printf("DEBUG: ADDI x%d = x%d + x%d -> %d\n", rd, rs1, imm, cpu->regs[rd]);
}

void exec_sw(RISCV_CPU *cpu, uint32_t inst) {
  uint32_t rs1 = GET_RS1(inst);
  uint32_t rs2 = GET_RS2(inst);
  int32_t imm = GET_IMM_S(inst);
  uint32_t addr = cpu->regs[rs1] + imm;

  printf("DEBUG: SW Mem [%d] = %d\n", addr, cpu->regs[rs2]);
}

void exec_jal(RISCV_CPU *cpu, uint32_t inst) {
  uint32_t rd = GET_RD(inst);
  int32_t imm = GET_IMM_J(inst);

  if (rd != 0)
    cpu->regs[rd] = cpu->pc + 4;
  cpu->pc = cpu->pc + imm;

  printf("DEBUG: JAL to 0x%X\n", cpu->pc);
}

void exec_load(RISCV_CPU *cpu, uint32_t inst) { return; }
