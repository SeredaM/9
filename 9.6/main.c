#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int nod(int a, int b)
{
    a=abs(a);
    b=abs(b);
if ((a==0)||(b==0)) return 1;
while (a!=b)
{
if (a>b)
{
a=a-b;
}
else
{
b=b-a;
}
}
return a;
}
void backw(int *m, int *w, int h)
{ int d;
    for (int i=h-1;i>=1;i--)
        for (int j=i-1;j>=0;j--)
        {
        d=nod(m[h*j+i],m[h*i+i]);
          for(int k=0;k<h;k++)
            w[h*j+k]=(w[h*j+k]*m[h*i+i] - w[h*i+k]*m[h*j+i])/d;
        m[h*j+i]=0;
        }
}
void forw(int *m, int *w, int h)
{
    int a,d;
     for (int i=0;i<h-1;i++)
        for (int j=i+1;j<h;j++)
        {
         a=m[h*j+i];
         d=nod(a,m[h*i+i]);
         if (a!=0)
            for (int k=i;k<h;k++)
        {
            w[h*j+k] =  (w[h*j+k]*m[h*i+i] - a*w[h*i+k])/d;
            m[h*j+k]= ((m[h*j+k]*m[h*i+i]) - (a*m[h*i+k]))/d;
        }
        }
}
void gauss(int *m, int *w, int h)
{
    forw(m,w,h);
    backw(m,w,h);

}

int main()
{
   int *m,*w,h;
   printf("Enter size: \n");
   scanf("%d",&h);
   printf("\nEnter matrix: \n");
  m = malloc(sizeof(int)*h*h);
  w = malloc(sizeof(int)*h*h);
   for (int i=0;i<h;i++)
    for (int j=0;j<h;j++)
    {
     if (j==i)
     {
     w[i*h+j]=1;
     }
     else
     w[i*h+j] = 0;
     scanf("%d",&m[i*h+j]);
    }
   gauss(m,w,h);
   printf("Inverse matrix:\n");
   for (int i=0;i<h;i++)
    {
    printf("\n");
    for (int j=0;j<h;j++)
        if (w[i*h+j]==0) printf("0 ");
         else if (m[i*h+i]==1) printf("%d ",w[i*h+j]);
           else printf("%d/%d ",w[i*h+j],m[i*h+i]);
    }
    printf("\nCheck:\n");
    gauss(w,m,h);
    for (int i=0;i<h;i++)
    {
    printf("\n");
    for (int j=0;j<h;j++)
        if (m[i*h+j]==0) printf("0 ");
         else if (w[i*h+i]==1) printf("%d ",m[i*h+j]);
           else printf("%d/%d ",m[i*h+j],w[i*h+i]);
    }
    return 0;
}
