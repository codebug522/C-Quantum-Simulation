/*
============================================================================================
////////////////////////////////////////////////////////////////////////////////////////////
////                    _ooOoo_
////               o8888888o
////                   88" . "88
////                   (| -_- |)
////                   O\  =  /O
////                ____/`---'\____
////              .'  \\|     |//  `.
////             /  \\|||  :  |||//  \
////            /  _||||| -:- |||||-  \
////            |   | \\\  -  /// |   |
////            | \_|  ''\---/''  |   |
////            \  .-\__  `-`  ___/-. /
////          ___`. .'  /--.--\  `. . __
////       ."" '<  `.___\_<|>_/___.'  >'"".
////      | | :  `- \`.;`\ _ /`;.`/ - ` : | |
////      \  \ `-.   \_ __\ /__ _/   .-` /  /
//// ======`-.____`-.___\_____/___.-`____.-'======
////                    `=---='
//// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
////   Yo!!what are you fucking doing Now?    Coding Bug!!
///////////////////////////////////////////////////////////////////////////////////////////
============================================================================================
DONE:
TODO:
INFO:
    Author :CodeBug
    Email  :xu520zhu@gmail.com
    Date   :2019-12-09 11:18:21
Reference:
    1:
    2:
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "quantum.h"
#include"calculate.h"
#include"operation.h"
#include"gate.h"
#include"qubit_ini.h"

int main()
{
 // printf("two quibts test on Hadmard gate\n");
 
//complex **hadamard1 = (complex *)calloc(3,sizeof(complex*));
//for(int i =0;i<3;i++)
//   {hadamard1[i]=(complex *)calloc(3,sizeof(complex*));}
//
//  hadamard1=getHadamard_2d();
//  //free(hadamard1);
//  for(int i = 0;i<2;i++)
//  {
//    for(int j = 0;j<2;j++)
//    {
//      printf("%f+%fi  ",hadamard1[i][j].real,hadamard1[i][j].img);
//    }
//    printf("\n");
// // }
 
//  complex **hadamard2 = (complex *)calloc(3,sizeof(complex*));
//for(int i =0;i<3;i++)
//   {hadamard2[i]=(complex *)calloc(3,sizeof(complex*));}
//hadamard2 = getPauli_I_2d();
//printf("*************\n");
//complex **kronck = (complex *)calloc(4,sizeof(complex*));
//for(int i =0;i<4;i++)
//   {kronck[i]=(complex *)calloc(6,sizeof(complex*));}
//kronck = tensor_multiply_2d(hadamard2,2,2, hadamard1,2,2); 
//
//complex **kronck1 = (complex *)calloc(4,sizeof(complex*));
//for(int i =0;i<4;i++)
//   {kronck1[i]=(complex *)calloc(6,sizeof(complex*));}
//kronck1 = tensor_multiply_2d(hadamard2,2,2, hadamard1,2,2);
//
printf("*****************start ***********************\n");
complex **n_qubit_zero = (complex *)calloc(17,sizeof(complex*));
for(int i =0;i<17;i++)
 {n_qubit_zero[i]=(complex *)calloc(2,sizeof(complex*));}
n_qubit_zero = get_n_qubit_ini();

complex **hadamard_gate = (complex *)calloc(3,sizeof(complex*));
for(int i =0;i<3;i++)
 {hadamard_gate[i]=(complex *)calloc(3,sizeof(complex*));}

complex **Pauli_Y_gate = (complex *)calloc(3,sizeof(complex*));
for(int i =0;i<3;i++)
 {Pauli_Y_gate[i]=(complex *)calloc(3,sizeof(complex*));}

complex **Pauli_Z_gate = (complex *)calloc(3,sizeof(complex*));
for(int i =0;i<3;i++)
 {Pauli_Z_gate[i]=(complex *)calloc(3,sizeof(complex*));}

complex **Pauli_I_gate = (complex *)calloc(3,sizeof(complex*));
for(int i =0;i<3;i++)
 {Pauli_I_gate[i]=(complex *)calloc(3,sizeof(complex*));}

complex **Pauli_X_gate = (complex *)calloc(3,sizeof(complex*));
for(int i =0;i<3;i++)
 {Pauli_X_gate[i]=(complex *)calloc(3,sizeof(complex*));}

complex **PhaseShift_gate = (complex *)calloc(3,sizeof(complex*));
for(int i =0;i<3;i++)
 {PhaseShift_gate[i]=(complex *)calloc(3,sizeof(complex*));}

complex **Cnot_gate = (complex *)calloc(5,sizeof(complex*));
for(int i =0;i<5;i++)
 {Cnot_gate[i]=(complex *)calloc(5,sizeof(complex*));}


hadamard_gate = getHadamard_2d();
Pauli_X_gate = getPauli_X_2d();
Pauli_I_gate = getPauli_I_2d();
Pauli_Y_gate = getPauli_Y_2d();
Pauli_Z_gate = getPauli_Z_2d();
PhaseShift_gate = getPhaseShift_2d(PI/3);
Cnot_gate = getCnot_2d();


complex **step1_1= (complex *)calloc(5,sizeof(complex*));
for(int i =0;i<5;i++)
 {step1_1[i]=(complex *)calloc(5,sizeof(complex*));}
complex **step1_2= (complex *)calloc(9,sizeof(complex*));
for(int i =0;i<9;i++)
 {step1_2[i]=(complex *)calloc(9,sizeof(complex*));}
complex **step1_3= (complex *)calloc(17,sizeof(complex*));
for(int i =0;i<17;i++)
 {step1_3[i]=(complex *)calloc(17,sizeof(complex*));}
complex **res_step_1 = (complex *)calloc(17,sizeof(complex*));
for(int i =0;i<17;i++)
{res_step_1=(complex *)calloc(2,sizeof(complex*));}

step1_1 = tensor_multiply_2d(Pauli_Z_gate,2,2,hadamard_gate,2,2);
step1_2 = tensor_multiply_2d(step1_1,4,4,Pauli_X_gate,2,2);
step1_3 = tensor_multiply_2d(step1_2,8,8,hadamard_gate,2,2);

res_step_1=matrix_multiply_2d(step1_3,16,16,n_qubit_zero,16,1);

complex **step2_1= (complex *)calloc(5,sizeof(complex*));
for(int i =0;i<5;i++)
 {step2_1[i]=(complex *)calloc(5,sizeof(complex*));}
complex **step2_2= (complex *)calloc(5,sizeof(complex*));
for(int i =0;i<5;i++)
 {step2_2[i]=(complex *)calloc(5,sizeof(complex*));}
complex **step2_3= (complex *)calloc(17,sizeof(complex*));
for(int i =0;i<17;i++)
 {step2_3[i]=(complex *)calloc(17,sizeof(complex*));}
 complex **res_step_2 = (complex *)calloc(17,sizeof(complex*));
for(int i =0;i<17;i++)
{res_step_2=(complex *)calloc(2,sizeof(complex*));}


step2_1 = tensor_multiply_2d(hadamard_gate,2,2,Pauli_Y_gate,2,2);
step2_2 = tensor_multiply_2d(step2_1,4,4,Cnot_gate,4,4);
//step2_3 = tensor_multiply_2d(step2_2,8,8,PhaseShift_gate,2,2);

res_step_2=matrix_multiply_2d(step2_2,16,16,res_step_1,16,1);

























  return 0;
}















