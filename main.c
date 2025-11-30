#include <stdio.h>
#include "riscv.h"

void cpu_exec(RISCV_CPU* cpu, uint32_t inst) 
{
	uint32_t opcode = GET_OPCODE(inst);
	cpu->regs[0] = 0;
  
	switch (opcode) {
		case 0x13:  {
			uint32_t rd = GET_RD(inst);
      uint32_t rs1 = GET_RS1(inst);
      uint32_t funct3 = GET_FUNCT3(inst);
      int32_t imm = GET_IMM_I(inst);
			if (funct3 == 0x0) {
				int32_t imm = GET_IMM_I(inst);
				cpu->regs[rd] = cpu->regs[rs1] + imm;
				printf("DEBUG: Executing ADDI x%d, x%d, %d\n", rd, rs1, imm);
			}
			break;
		}
		case 0x23: {
			uint32_t rs1 = GET_RS1(inst);
			uint32_t rs2 = GET_RS2(inst);
			uint32_t funct3 = GET_FUNCT3(inst);
			int32_t imm = GET_IMM_S(inst);

			uint32_t addr = cpu->regs[rs1] + imm;
			uint32_t val = cpu->regs[rs2];

			if (funct3 == 0x2) {
				if (addr + 4 <= MEM_SIZE) {
					cpu->memory[addr] = (val)           & 0xFF;
					cpu->memory[addr + 1] = (val >> 8)  & 0xFF;
					cpu->memory[addr + 2] = (val >> 16) & 0xFF;
					cpu->memory[addr + 3] = (val >> 24) & 0xFF;
					printf("DEBUG: SW [Addr: %d] = %d (from x%d)\n", addr, val, rs2);
				}
			} else {
				printf("Error: Segmentation Fault at address %d\n", addr);
			}
			break;
		}
		case 0x63: {

			break;
		}
		default:
			printf("Error: Unkown Opcode 0x%X\n", opcode);
			break;
	}
}

int main() {
	RISCV_CPU cpu = {0};
	
	cpu.regs[1] = 5;
	
	uint32_t instruction = 0x00102223;
	
	//printf("Before: x1=%d, x2=%d\n", cpu.regs[1], cpu.regs[2]);
	
	cpu_exec(&cpu, instruction);

	//printf("After: x1=%d, x2=%d\n", cpu.regs[1], cpu.regs[2]);

	return 0;

}
