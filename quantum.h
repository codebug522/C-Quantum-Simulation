#ifndef QUANTUM_H
#define QUANTUM_H


#define THRESHOLD  0.99
enum Qubit_State{ZERO,ONE,ZERO_ZERO,SUPERPOSITION};
/*one qubit defination*/
typedef struct complex_number{
  double real;
  double img;
}complex;
typedef struct qubit{
  complex alpha;
  complex beta;
}qubit;
/*n qubits defination*/
typedef struct quantum_register{
qubit *q;
struct quantum_register *link;
}quantum_register;


#endif
