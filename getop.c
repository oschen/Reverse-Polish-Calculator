#include<stdio.h>
#include<ctype.h>

#define NUMBER '0'
#define FUNCNAME 'x'

extern int getch(void);
extern void ungetch(int);

int getop(char a[])
{
  int c;
  int i=0;
  while((a[0]=c=getch())==' '||c=='\t')
       ;
  a[1]='\0';
  if(isalpha(c))
  {  while(isalpha(a[++i]=c=getch()))
        ;
    a[i]='\0';
    if(c!=EOF)
      ungetch(c);
    if(i==1)
      return a[0];
    else
      return FUNCNAME;
  }

  if(!isdigit(c)&&c!='-'&&c!='.')
    return c;

  if(c=='-')
     if(isdigit(c=getch())||c=='.')
       {  a[++i]=c; }
     else
      {
        if(c!=EOF)
           ungetch(c);
        return '-';
      }
  if(isdigit(c))
    while(isdigit(a[++i]=c=getch()))
        ;
  if(c=='.')
    while(isdigit(a[++i]=c=getch()))
        ;

  a[i]='\0';
  if(c!=EOF)
    ungetch(c);
   return NUMBER;

}
