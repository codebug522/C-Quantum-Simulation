#ifndef CALCULATE_H
#define CALCULATE_H

#include <stdio.h>
#include <stdlib.h>
#include "quantum.h"

#define PI 3.1415926

void swap_quit_b(qubit *);
void np_swap_b(qubit *);
double get_complex_number(complex);
complex add(complex,complex);
complex scalar_multiply(double,complex);
complex vector_multiply(complex,complex);
complex *tensor_multiply(complex *,int,int ,complex *,int ,int);
complex **tensor_multiply_2d(complex **,int,int ,complex **,int ,int);
complex **matrix_multiply_2d(complex **,int ,int ,complex **,int ,int );

#endif

