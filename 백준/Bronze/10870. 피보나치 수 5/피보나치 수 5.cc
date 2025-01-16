#include<stdio.h>
int fibo(int);

int main()
{
 int n;
 scanf("%d", &n);
 printf("%d", fibo(n));
}

int fibo(int N)
{
  if(N==1)
  return 1;
    
  else if(N==0)
  return 0;

  else
  return fibo(N-1)+fibo(N-2);
}