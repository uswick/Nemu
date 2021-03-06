#ifndef _CPU_H_
#define _CPU_H_
#include <stdlib.h>
#include <runtime.h>

typedef struct cpu {
  uint16_t PC; // program counter - 16bit address
  uint8_t SP;  // stack pointer - 8bit
  uint8_t A;   // Accumilator - 8bit
  uint8_t X;   // X Register
  uint8_t Y;   // Y Register
  uint8_t P;   // Status register
} cpu_t;

typedef enum {
  ZeroPage = 0,
  ZeroPageX,
  ZeroPageY,
  AbsoluteX,
  AbsoluteY,
  Indirect,
  Implied,
  Accum,
  Relative,
  XIndirect,
  YIndirect,
  IndirectX,
  IndirectY,
  NoAddr
} addr_mode_t;

typedef int (*i_executor)(void *runtime, n_addr op1, n_addr op2);

/*
 * A type describing each intruction in 6502 microprocessor
 * */
typedef struct {
  const char *name; // name for the instruction
  int size;         // instruction size in bytes = opcode + operand/s
  addr_mode_t mode; // addressing mode
  int cycles;       // execution cpu cycles
  int cycles_b;     // additional cpu cycles if page_boundry is crossed
  i_executor exec;  // function implementing the execution of instruction
} instr_t;
#endif
