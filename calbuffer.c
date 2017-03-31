#include<stdio.h>
#include<stdlib.h>

#define STACKMAX 100
int stackindex=0;
static double stack[STACKMAX];

void  push_val(double c)
{
    if(stackindex>=STACKMAX)
    {      printf("stack overflow\n");
           exit(-1);
      }
    else
         stack[stackindex++]=c;        
}

double pop_val()
{
    if(stackindex==0)
    {
        printf("stack is empty\n");
        exit(-1);
     }
     else
        return stack[--stackindex];

}

void clear()
{
  stackindex=0;
}

int isempty()
{
  return (stackindex==0)?1:0;

}
