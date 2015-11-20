#include <stdio.h>
#include <stdlib.h>
#include <cpu.h>

instr_t itable[256] = {{"BRK", 1, NoAddr, 2, 0, NULL},
                       {"CLR", 2, NoAddr, 3, 1, NULL},
                       {"JMP", 2, Implied, 2, 1, NULL},
		       
		       /*last entry*/
                       {NULL, 0, NoAddr, 0, 0, NULL}};

int main(int argc, char *argv[]) {

  instr_t *entry = &itable[0];
  while (entry->name) {
    instr_t ins = *entry;
    printf("instruction details => name [%s] \t len [%d] \t mode [%d] \t "
           "cycles [%d] \t b_cycles [%d] \n",
           ins.name, ins.size, ins.mode, ins.cycles, ins.cycles_b);

    entry++;
  }
  return 0;
}
