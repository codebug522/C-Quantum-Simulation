#include<stdio.h>
#include"quantum.h"
#include"qubit_ini.h"
#include<math.h>
#include<stdlib.h>
complex **get_n_qubit_ini()
{
  int n;
  int temp = 1;
  scanf("%d",&n);
  char s[n+1];
  for(int i = 0;i<n+1;i++)
  {
     s[i]=' ';
  }
  complex **qubit_n_ini = (complex *)calloc(pow(2,n)+1,sizeof(complex *));
  for(int i = 0;i<pow(2,n)+1;i++)
  {qubit_n_ini[i]=(complex *)calloc(2,sizeof(complex*));}
    for(int i =0;i<pow(2,n);i++){
    qubit_n_ini[i][0].real = qubit_n_ini[i][0].img = 0; 
  qubit_n_ini[0][0].real = 1;
    }
  for(int i = 0;i<pow(2,n);i++){
    for(int j = 0;j<n;j++)
  { 
    if((i&(temp<<j))!=0)
      s[n-j-1]='1';
    else 
      s[n-j-1]='0';
    
  }
   //printf("%s",s);
  printf("%.3f+%.3fi|%s>+",qubit_n_ini[i][0].real,qubit_n_ini[i][0].img,s);

  }
    return  qubit_n_ini;
}
