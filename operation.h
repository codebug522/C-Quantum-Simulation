#ifndef OPERATION_H
#define OPERATION_H
#include<stdio.h>
#include"quantum.h"


void zero_b(qubit *);
void one_b(qubit *);
void zero_zero(qubit *);
complex *getHadamard();
complex **getHadamard_2d();
complex **getPauli_I_2d();
complex **getPauli_X_2d();
complex **getPauli_Y_2d();
complex **getPauli_Z_2d();
complex **getCnot_2d();
complex **getPhaseShift_2d(double);

qubit *create_qubit(enum Qubit_State);

int num_of_qubits(quantum_register *qreg);
void add_to_register(quantum_register **qreg,enum Qubit_State state);
quantum_register *create_quantum_register(int ,enum Qubit_State);
void clean_q(quantum_register *qreg);
void hadamard(qubit *);
#endif

