#ifndef OPCODES_H
#define OPCODES_H

typedef enum {
  OP_LUI = 0x37,    // FMT: U , OPCODE: 0110111, HEX: 37
  OP_AUIRC = 0x17,  // FMT: U , OPCODE: 0010111, HEX: 17
  OP_JAL = 0x6F,    // FMT: UJ, OPCODE: 1101111, HEX: 6F
  OP_JALR = 0x67,   // FMT: I , OPCODE: 1100111, HEX: 67/0
  OP_BRANCH = 0x67, // FMT:
  OP_LOAD = 0x03,
  OP_STORE = 0x23,
  OP_ALU_I = 0x13,
  OP_ALU_R = 0x33,
  OP_SYSTEM = 0x73
} Opcode;

#endif // OPCODES_H
