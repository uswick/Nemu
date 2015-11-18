#include <stdlib.h>
#ifndef
#define _CPU_H

typedef struct {
  uint16_t PC; // program counter - 16bit address
  uint8_t SP;  // stack pointer - 8bit
  uint8_t A;   // Accumilator - 8bit
  uint8_t X;   // X Register
  uint8_t Y;   // Y Register
  uint8_t P;   // Status register
} cpu_t;

#endif
