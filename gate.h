#ifndef gate_h
#define gate_h

#include<stdio.h>
#include "quantum.h"
void phase_shift(qubit *,double);
void toffoli(qubit *,qubit *,qubit *);
void cnot(qubit *,qubit *);
//qubit *and(qubit *,qubit *);
#endif
