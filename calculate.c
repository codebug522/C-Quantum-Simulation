#include "calculate.h"
#include "quantum.h"
#include <stdlib.h>
#include <math.h>
void swap_qubit_b(qubit *q)
{
  complex alpha = q->alpha;
  q->alpha = q->beta;
  q->beta = alpha;


}



void no_swap_b(qubit *q)
{
  return;

}

double get_complex_number(complex c)
{
  return sqrt(pow(c.real,2)+pow(c.img,2));


}

complex add(complex c1,complex c2)
{
  complex res;
  res.real = c1.real+c2.real;
  res.img = c1.img+c2.img;
  return res;

}

complex scalar_multiply(double scalar,complex c)
{
   complex res;
   res.real = scalar * c.real;
   res.img = scalar * c.img;
   return res;

}


complex vector_multiply(complex c1,complex c2)
{
  complex res;
  res.real = (c1.real * c2.real)+(-1)*(c1.img * c2.img);
  res.img = (c1.real * c2.img)+(c2.real * c1.img);
  return res;
   
}

complex *tensor_multiply(complex *m1,int r1,int c1,complex *m2,int r2,int c2)
{
  complex *inner = (complex *)calloc((r1*r2) * (c1*c2),sizeof(complex));
  int count = 0;
 for(int i = 0;i<r1;i++){
    for(int j = 0;j<c1;j++){
      for(int k = 0;k<r2;k++){
       for(int l =0;l<c2;l++){
          inner[(i*r1*r2*c2)+((c1*k*r2)+l)+j*c2] = vector_multiply(m1[i*r1+j], m2[k*r2+l]);
          printf("%f+%fi\n",inner[(i*r1*r2*c2)+((c1*k*r2)+l)+j*c2].real,inner[(i*r1*r2*c2)+((c1*k*r2)+l)+j*c2].img);
         // count++;
        }
      }
   }
  }
  return inner;
}

complex **tensor_multiply_2d(complex **m1,int r1,int c1,complex **m2,int r2,int c2) 
{
   complex **inner = (complex *)calloc(((r1+1)*(r2+1)),sizeof(complex*));
  for(int i =0;i<(r1+1)*(r2+1);i++)
  {inner[i]=(complex *)calloc(((c1+1)*(c2+1)),sizeof(complex*));}
 //  for(int i = 0;i<r1;i++){
   // for(int j = 0;j<c1;j++){
     // for(int k = 0;k<r2;k++){
       //for(int l =0;l<c2;l++){
         // inner[i*r2+k][j*c2+l] = vector_multiply(m1[i][j], m2[k][l]);
         //printf("%f+%fi\n",inner[(i*r1*r2*c2)+((c1*k*r2)+l)+j*c2].real,inner[(i*r1*r2*c2)+((c1*k*r2)+l)+j*c2].img);
          //}
      //}
   //}
  //}
  for(int i = 0;i<r1*r2;i++)
    for(int j = 0;j<c1*c2;j++)
      inner[i][j]=vector_multiply(m1[i/r2][j/c2], m2[i%r2][j%c2]);
for(int i = 0;i<c1*c2;i++){
  for(int j = 0;j<r1*r2;j++)
  {
  printf("%f+%fi  ",inner[i][j].real,inner[i][j].img);
  }
  printf("\n");
}

  return inner;
}

complex **matrix_multiply_2d(complex **m1,int r1,int c1,complex **m2,int r2,int c2)
{
    if(c1==r2){

    complex **res_matrix = (complex *)calloc((r1+1),sizeof(complex *));
    for(int i = 0;i<r1+1;i++)
    {res_matrix[i]=(complex *)calloc((c2+1),sizeof(complex*));}
    complex res_s;
    res_s.real = 0;
    res_s.img = 0;
    for(int i = 0;i<r1;i++){
      for(int j = 0;j<c2;j++){
        for(int k = 0;k<c1;k++)
        {
          res_s = add(res_s,vector_multiply(m1[i][k],m2[k][j]));
        }
        res_matrix[i][j] = res_s;
        res_s.img = res_s.real = 0;
      }
    }
    for(int i = 0;i<r1;i++){
      for(int j = 0;j<c2;j++){
        printf("%.3f+%.3fi ",res_matrix[i][j].real,res_matrix[i][j].img);
      }
      printf("\n");
    }
    return res_matrix;

    }
    
    else{
      printf("The shape of the matrix is illegal");
      return 0;

    }
}






