#include<math.h>
#include"gate.h"
#include"quantum.h"
#include"calculate.h"
#include"operation.h"

qubit *and(qubit *p,qubit *q)
{
  qubit *res = NULL;
  if(get_complex_number(p->alpha)>=THRESHOLD)
  {
    if(get_complex_number(q->alpha)>=THRESHOLD)
    {
      res = create_qubit(ZERO);
    }
     else if(get_complex_number(q->beta)>=THRESHOLD)
    {
      res = create_qubit(ZERO);
    }
    else 
    printf("Illegal");
  }
  else if(get_complex_number(p->beta)>=THRESHOLD)
  {
    if(get_complex_number(q->alpha)>=THRESHOLD)
    {
      res = create_qubit(ZERO);
    }
    else if(get_complex_number(q->beta)>=THRESHOLD)
    {
      res = create_qubit(ONE);
    }
    else 
      printf("Illegal");
  }
  else 
  printf("Illegla");
  return res;

}

void cnot(qubit *p,qubit *q)
{
  if(get_complex_number(p->alpha)>=THRESHOLD){
    if(q!=NULL)
      swap_qubit_b(q);
  }
  else if(get_complex_number(p->beta)>=THRESHOLD){
    no_swap_b(q);
  }
}


void toffoli(qubit *p,qubit *q,qubit *r)
{

  qubit *res=and(p,q);
  cnot(res,r);
}

void phase_shift(qubit *q,double angle)
{
  complex c1;
  c1.real = cos(angle);
  c1.img = sin(angle);
  q->beta = vector_multiply(q->beta,c1);
}


