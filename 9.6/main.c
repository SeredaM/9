#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void change(int i,float *w, float *m,int h)
{
    int k=i+1;
    float t;
    while (m[k*h+i]==0) k++;
    if (k<h-1)
    for (int j=0; j<h; j++)
    {
      t=m[h*i+j];
      m[h*i+j]=m[k*h+j];
      m[k*h+j]=m[h*i+j];
      t=w[h*i+j];
      w[h*i+j]=w[k*h+j];
      w[k*h+j]=w[h*i+j];
    }
}
void backw(float *m, float *w, int h)
{
    float d;
    for (int i=h-1;i>=1;i--)
        for (int j=i-1;j>=0;j--)
        {
        d=m[h*j+i]/m[h*i+i];
          for(int k=0;k<h;k++)
            w[h*j+k]=(w[h*j+k] - w[h*i+k]*d);
        m[h*j+i]=0;
        }
}
void forw(float *m, float *w, int h)
{
    float a,d;
     for (int i=0;i<h-1;i++)
        for (int j=i+1;j<h;j++)
        {
         if (abs(m[h*i+i])<0.0001) change(i,w,m,h);
         a=m[h*j+i];
         d=m[h*j+i]/m[h*i+i];
         if (a!=0)
            for (int k=0;k<h;k++)
        {
            w[h*j+k] = w[h*j+k] - d*w[h*i+k];
            m[h*j+k]= (m[h*j+k]) - d*m[h*i+k];
        }
        }
}
void gauss(float *m, float *w, int h)
{
    forw(m,w,h);
    backw(m,w,h);
    for (int i=0;i<h;i++)
    {
     for (int j=0;j<h;j++)
        w[i*h+j]=w[i*h+j]/m[i*h+i];
     m[i*h+i]=1;
    }



}

int main()
{
   float *m,*w;
   int h;
   printf("Enter size: \n");
   scanf("%d",&h);
   printf("\nEnter matrix: \n");
  m = malloc(sizeof(float)*h*h);
  w = malloc(sizeof(float)*h*h);
   for (int i=0;i<h;i++)
    for (int j=0;j<h;j++)
    {
     if (j==i)
     {
     w[i*h+j]=1;
     }
     else
     w[i*h+j] = 0;
     scanf("%f",&m[i*h+j]);
    }
   gauss(m,w,h);
   printf("Inverse matrix:\n");
   for (int i=0;i<h;i++)
    {
    printf("\n");
    for (int j=0;j<h;j++)
        printf("%.3f ",w[i*h+j]);
    }
    printf("\nCheck:\n");
    gauss(w,m,h);
    for (int i=0;i<h;i++)
    {
    printf("\n");
    for (int j=0;j<h;j++)
        printf("%.3f ",m[i*h+j]);
    }
    return 0;
}
