#ifndef RISCV_H
#define RISCV_H

#include <stdint.h>
#include <stdbool.h>

#define MEM_SIZE 1024 * 1024 

typedef struct {
    uint32_t regs[32];        // x0 - x31
    uint32_t pc;              // Program Counter
    uint8_t memory[MEM_SIZE]; // RAM
} RISCV_CPU;

#define GET_OPCODE(inst)  ((inst) & 0x7F)           	// Operation Code
#define GET_RD(inst)      (((inst) >> 7) & 0x1F)    	// Destination Register
#define GET_FUNCT3(inst)  (((inst) >> 12) & 0x7)    	// FUNCT3
#define GET_RS1(inst)     (((inst) >> 15) & 0x1F)   	// Source Register 1
#define GET_RS2(inst)     (((inst) >> 20) & 0x1F)   	// Source Register 2
#define GET_FUNCT7(inst)  (((inst) >> 25) & 0x7F)   	// FUNCT7

#define GET_IMM_I(inst)   ((int32_t)(inst) >> 20)
#define GET_IMM_S(inst)   ((int32_t)((inst) & 0xFE000000) >> 20 | ((inst >> 7) & 0x1F))
#define GET_IMM_B(inst)   ((int32_t)((inst) & 0x80000000) >> 19 | ((inst) & 0x80) << 4 | ((inst) >> 20) & 0x7E0 | ((inst) >> 7) & 0x1E)
#define GET_IMM_J(inst)   ((int32_t)((inst) & 0x80000000) >> 11 | ((inst) & 0x000FF000) | (((inst) >> 20) & 0x1) << 11 | (((inst) >> 21) & 0x3FF) << 1);
#define GET_IMM_U(inst)   ((inst) & 0xFFFFF000)

void cpu_exec(RISCV_CPU* cpu, uint32_t inst);

#endif // !RISCV_H
