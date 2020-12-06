#include <stdio.h>
#include <stdlib.h>
void change(int i,int w, int *m)
{
    int k=i+1,t;
    while (m[k*w+i]==0) k++;
    if (k<w-1)
    for (int j=0; j<w; j++)
    {
      t=m[w*i+j];
      m[w*i+j]=m[k*w+j];
      m[k*w+j]=m[w*i+j];
    }
}
void backw(int *m, int w, int h)
{
    for (int i=h-1;i>=1;i--)
        for (int j=i-1;j>=0;j--)
          { for (int k=0;k<i;k++)
            m[w*j+k]=m[w*j+k]*m[w*i+i];
            m[w*j+w-1]= m[w*j+w-1]*m[w*i+i] - m[w*i+w-1]*m[w*j+i];
            m[w*j+i]=0;
           }
}
void forw(int *m, int w, int h)
{
    int a;
     for (int i=0;i<h-1;i++)
        for (int j=i+1;j<h;j++)
        {
         if (m[w*i+i]==0) change(i,w,m);
         a=m[w*j+i];
         if (a!=0)
            for (int k=i;k<w;k++)
        {
            m[w*j+k]= ((m[w*j+k]*m[w*i+i]) - (a*m[w*i+k]));
        }
        }
}
void gauss(int *m, int w, int h)
{
    forw(m,w,h);
    backw(m,w,h);
}

int main()
{
   int n,*m,w,h;
   double a;
   printf("Enter amount of variables: \n");
   scanf("%d",&n);
   printf("\nEnter equations: \n");
  m = malloc(sizeof(int)*n*(n+1));
   h=n;
   w=n+1;
   for (int i=0;i<n;i++)
    for (int j=0;j<n+1;j++)
     scanf("%d",&m[i*w+j]);
   gauss(m,w,h);
   for (int i=0;i<h;i++)
    {
        a=m[w*i+w-1]/m[w*i+i];
        printf("\n x[%d]=%.3f \n ",i,a);
    }
    return 0;
}
