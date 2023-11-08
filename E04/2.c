#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char **argv){
  int a[100];

  srand(time(0));

  for(int i = 0; i < 100; ++i)
    a[i] = 10 + rand() % (80 - 10 + 1);

  for(int i = 0; i < 100; ++i)
    printf("%d ", a[i]);

  printf("\n");

  return 0;
}

