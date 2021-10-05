#include<stdlib.h>
#include<stdarg.h>
#include<math.h>

#include"quantum.h"
#include"operation.h"
#include"calculate.h"

void zero_b(qubit *q)
{ 
  complex c1 ,c2;
  c1.real = 1;
  c1.img = 0;
  c2.real = c2.img = 0;
  q->alpha = c1;
  q->beta = c2;
}

void one_b(qubit *q)
{
  complex c1,c2;
  c1.real = c1.img = 0;
  c2.real = 1;
  c2.img = 0;
  q->alpha = c1;
  q->beta = c2;
}
void zero_zero(qubit *q)
{
  complex c1,c2;
  c1.real = c1.img = c2.real = c2.img = 0;
  q->alpha = c1;
  q->beta = c2;
}


complex *getHadamard()
{
  int row = 2;
  int col = 2;
  complex *h = (complex *)calloc(row * col,sizeof(complex));
  for(int i = 0;i<(row * col);i++){
    h[i].real = 1/sqrt(2),h[i].img = 0;
  }
  h[3].real = -1 * h[3].real;
  //for(int i = 0;i<(row*col);i++)
 // {printf("%f+%fi",h[i].real,h[i].img);}
  return h;
}

complex **getHadamard_2d()
{
  int row = 2;
  int col = 2;
  complex **h = (complex **)calloc(row+1,sizeof(complex*));
  for(int i =0;i<row+1;i++)
  {h[i]=(complex *)calloc(col+1,sizeof(complex*)); }
  for(int i = 0;i<col;i++){
     for(int j = 0;j<row;j++)
       {
          h[i][j].img = 0;
          h[i][j].real = 1/sqrt(2);
         
      }  
      printf("\n");
   }
  h[1][1].real = -h[1][1].real;
  for(int i =0;i<row;i++)
  {
    for(int j = 0;j<col;j++){
      printf("%f+%fi  ",h[i][j],h[i][j]);
    }
    printf("\n");
  }
return h;
}

complex **getPauli_I_2d()
{
  int row = 2;
  int col = 2;
  complex **h = (complex **)calloc(row+1,sizeof(complex*));
  for(int i =0;i<row+1;i++)
  {h[i]=(complex *)calloc(col+1,sizeof(complex*)); }
  h[0][0].real = h[1][1].real=1;
 h[0][0].img = h[1][1].img = h[0][1].real=h[0][1].img=h[1][0].real=h[1][0].real = 0; 
  for(int i = 0;i<col;i++){
     for(int j = 0;j<row;j++)
       { 
          printf("%f+%fi ",h[i][j].real,h[i][j].img);
      }  
      printf("\n");
   }

return h;
}


complex **getPauli_X_2d()
{
  int row = 2;
  int col = 2;
  complex **h = (complex **)calloc(row+1,sizeof(complex*));
  for(int i =0;i<row+1;i++)
  {h[i]=(complex *)calloc(col+1,sizeof(complex*)); }
  h[1][0].real = h[0][1].real=1;
  h[0][0].real = h[0][0].img = h[0][1].img=h[1][0].img=h[1][1].real=h[1][1].img = 0; 
  for(int i = 0;i<col;i++){
     for(int j = 0;j<row;j++)
       { 
          printf("%f+%fi ",h[i][j].real,h[i][j].img);
      }  
      printf("\n");
   }

return h;
}



complex **getPauli_Y_2d()
{
  int row = 2;
  int col = 2;
  complex **h = (complex **)calloc(row+1,sizeof(complex*));
  for(int i =0;i<row+1;i++)
  {h[i]=(complex *)calloc(col+1,sizeof(complex*)); }
  h[1][0].img=-1 ;
  h[0][1].img=1;
  h[0][0].real = h[0][0].img = h[0][1].real=h[1][0].real=h[1][1].real=h[1][1].img = 0; 
  for(int i = 0;i<col;i++){
     for(int j = 0;j<row;j++)
       { 
          printf("%f+%fi ",h[i][j].real,h[i][j].img);
      }  
      printf("\n");
   }

return h;
}


complex **getPauli_Z_2d()
{
  int row = 2;
  int col = 2;
  complex **h = (complex **)calloc(row+1,sizeof(complex*));
  for(int i =0;i<row+1;i++)
  {h[i]=(complex *)calloc(col+1,sizeof(complex*)); }
  h[0][0].real=1 ;
  h[1][1].img=-1 ;
  h[0][0].img = h[0][1].real = h[0][1].img=h[1][0].real=h[1][1].img=h[1][1].real = 0; 
  for(int i = 0;i<col;i++){
     for(int j = 0;j<row;j++)
       { 
          printf("%f+%fi ",h[i][j].real,h[i][j].img);
      }  
      printf("\n");
   }

return h;
}

complex **getPhaseShift_2d(double angle)
{
  int row =2;
  int col =2;
    complex **h = (complex **)calloc(row+1,sizeof(complex*));
  for(int i =0;i<row+1;i++)
  {h[i]=(complex *)calloc(col+1,sizeof(complex*)); }
  h[0][0].real = 1;
  h[0][1].real = h[0][1].img = h[1][0].real = h[1][0].img = 0;
  h[1][1].real = cos(angle);
  h[1][1].img = sin(angle);
  return h;
}
complex **getCnot_2d()
{
  int row = 4;
  int col = 4;
  complex **h = (complex**)calloc(row+1,sizeof(complex*));
  for(int i =0;i<col+1;i++)
  {h[i]=(complex *)calloc(col+1,sizeof(complex *));}
  for(int i = 0;i<4;i++)
    for(int j = 0;j<4;j++){
      h[i][j].img = h[i][j].real = 0;
    }
  h[0][0].real = h[1][1].real=h[2][3].real = h[3][2].real = 1;
  return h;
}





qubit *create_qubit(enum Qubit_State state){
  qubit *q = (qubit *)malloc(sizeof(qubit));
  switch (state){
    case ZERO:
      zero_b(q);
      break;
    case ONE:
      one_b(q);
      break;
    case ZERO_ZERO:
      zero_zero(q);
      break;
    case SUPERPOSITION:
      printf("supering.....");
      break;
     default:
      break;
  }
  return q;
}

int num_of_qubits(quantum_register *qreg){
  int count = 0;
  if(qreg == NULL){return -1;}
  while(qreg != NULL){
  count++;
  qreg = qreg->link;
  }
  return count;
 }


complex *getQubit(quantum_register **qreg)
{
  complex *weight_value = (complex *)malloc(sizeof(complex));
  
}

void add_to_register(quantum_register **qreg,enum Qubit_State state)
{
  if(*qreg == NULL){
    (*qreg) = (quantum_register *)malloc(sizeof(quantum_register));
    (*qreg)->link = NULL;
    (*qreg)->q = create_qubit(state);
  }

  else{
    quantum_register *temp = *qreg;
    while(temp->link != NULL)
      temp = temp->link;
    temp->link = (quantum_register *)malloc(sizeof(quantum_register));
    temp->link->link = NULL;
    temp->link->q = create_qubit(state);
  
  }

}

quantum_register *create_quantum_register(int num_of_qubits,enum Qubit_State state)
{
  quantum_register *qreg = NULL;
  for(int i = 0;i<=num_of_qubits;i++)
  {
    add_to_register(&qreg,state);  
  }
  return qreg;
}

void clean_q(quantum_register *qreg)
{ 
  free(qreg);
}

void hadamard(qubit *q)
{
  complex *h  = getHadamard();
  complex alpha,beta;
  alpha = add(vector_multiply(h[0],q->alpha),vector_multiply(h[1],q->beta));
  beta = add(vector_multiply(h[2],q->alpha),vector_multiply(h[3],q->beta));
  q->alpha = alpha;
  q->beta = beta;
  free(h);
}

