#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void var1(int *p,int h,int w)
{
 for (int i=0;i<h;i++)
    for (int j=0;j<w;j++)
       p[i*w+j]=abs(i-j)+1;
}
void var2(int *p,int h, int w)
{
  int uh=0,lw=0,dh=h-1,rw=w-1,f=1,c=1,x=0,y=0;
    for (int n=0;n<h*w;n++)
    { p[y*w+x]=c;
      c++;
      switch(f)   //1 - вправо, 2 вниз, 3 - влево, 4 -  вверх
      {
 case 1:
x++;
if (x==rw)
{
    f=2;
    uh++;
}
break;
case 2:
y++;
if (y==dh)
{
    f=3;
    rw--;
}
break;
case 3:
x--;
if (x==lw)
{
    f=4;
    dh--;
}
break;
case 4:
y--;
if (y==uh)
{
    f=1;
    lw++;
}
break;
    }
   }
}
int main()
{ int *p,h,w,c;
printf("Enter n,m \n");
scanf("%d %d",&h,&w);
p=malloc(sizeof(int)*h*w);
printf("\n Choose variant: \n 1. \n 2. \n");
scanf("%d",&c);
switch(c)
{
case 1 :
     var1(p,h,w);
     break;
case 2 :
    var2(p,h,w);
    break;
}
for (int i=0;i<h;i++)
{
    printf("\n");
    for (int j=0;j<w;j++) printf("%d ",p[i*w+j]);
}
}

