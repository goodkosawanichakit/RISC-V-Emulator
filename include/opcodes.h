#ifdef OPCODES_H
#define OPCODES_H

typedef enum {
  OP_LUI    = 0x37,
  OP_AUIRC  = 0x17,
  OP_JAL    = 0x6F,
  OP_JALR   = 0x67,
  OP_BRANCH = 0x67,
  OP_LOAD   = 0x03,
  OP_STORE  = 0x23,
  OP_ALU_I  = 0x13,
  OP_ALU_R  = 0x33,
  OP_SYSTEM = 0x73
} Opcode;

#endif // OPCODES_H
