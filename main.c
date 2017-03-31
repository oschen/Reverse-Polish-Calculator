#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define OPMAX 100
#define NUMBER '0'
#define FUNCNAME 'x'
#define PI 3.1415926
void mathfunc(char []);
int getop(char []);
void push_val(double);
double pop_val();
void clear();
int isempty();
extern int stackindex;

int main()
{
  int c;
  double temp,op;
  char s[OPMAX];
  double variable[26];
  double num,v;
  int var;
  for(int i=0;i<26;i++)
     variable[i]=0.0;

  while((c=getop(s))!=EOF)
  {
     switch(c)
     {
      case NUMBER:
         push_val(atof(s));
         break;
      case FUNCNAME:
           //printf("function is %s\n",s);
           mathfunc(s);
           break;
    /*  case 'c':
           clear();
           break;
      case 's':
           temp=pop_val();
           op=pop_val();
           push_val(temp);
           push_val(op);
           break;
      case 'd':
           temp=pop_val();
           push_val(temp);
           push_val(temp);
           break;     */
      case '=':
          pop_val();
          if(var>'Z'||var<'A')
               printf("no such variable, A-Z expected\n");
           else
               variable[var-'A']=pop_val();
          break;
      case '?':
           temp=pop_val();
           push_val(temp);
           printf("top element is %f\n",temp);
           break;
      case '+':
         push_val(pop_val()+pop_val());
         break;
      case '-':
         temp=pop_val();
         push_val(pop_val()-temp);
         break;
      case '%':
         temp=pop_val();
         push_val(fmod(pop_val(),temp));
         break;
      case '*':
         push_val(pop_val()*pop_val());
         break;
      case '/':
         temp=pop_val();
         if(temp==0)
         {    printf("divide zero error\n");
              putchar('\n');
              clear();
         }
          else
            push_val(pop_val()/temp);
            break;
       case '\n':
           if(!isempty())
            {
               v=pop_val();
               printf("%f\n",v);

              }
           break;
       default:
           if(c>='A'&&c<='Z')
               push_val(variable[c-'A']);
           else if(c=='v')
               push_val(v);
           else
              printf("unknown commands %c\n",c);

          }
       var=c;
      }

   }

void mathfunc(char a[])
{
   double num;
   if(strcmp(a,"cos")==0)
       push_val(cos(pop_val()*PI/180));
   else if(strcmp(a,"sin")==0)
   {    num=pop_val();
        push_val(sin(num*PI/180));
        printf("sin is called for %f\n",num);
   }
   else if(strcmp(a,"exp"))
       push_val(exp(pop_val()));
   else if(strcmp(a,"pow"))
     { num=pop_val();
       push_val(pow(pop_val(),num));
    }
   else
       printf("operation can not support yet\n");
}
