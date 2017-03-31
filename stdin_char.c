#include<stdio.h>
#define MAXBUFFER 100

int inbuffer[MAXBUFFER];
int bufferindex=0;

int getch()
{
   return (bufferindex==0)?getchar():inbuffer[--bufferindex] ;   
}

void ungetch(int c)
{
   if(bufferindex>=MAXBUFFER)
     printf("buffer is full\n");
   else
     inbuffer[bufferindex++]=c;
}
