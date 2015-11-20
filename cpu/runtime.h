#include <cpu.h>
#ifndef _RUNTIME_H_
#define _RUNTIME_H_
struct cpu ;

typedef void
    *n_addr; // A representation of Address/location on NES RAM/VRAM

typedef struct {
  struct cpu *cpu;
  int status;
} runtime_t;

#endif
