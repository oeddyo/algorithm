/*
ID: xieke.b1
PROB: fence4
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
FILE* fin=fopen("fence4.in","r");
FILE* fout=fopen("fence4.out","w");
const double eps=1e-5;
int n,ans[305],ansNum=0;
struct Point
{
    double x,y;
    Point(){}
    Point(double x0, double y0)
    {
        x=x0,y=y0;
    }
}person,vertex[305];
int dblcmp(double a)
{
    if(a==0) return 0;
    return a>0?1:-1;
}
double max(double a, double b)
{
    return a>b?a:b;
}
double min(double a, double b)
{
    return a<b?a:b;
}
double cross(Point a, Point b)
{
    return a.x*b.y-a.y*b.x;
}
double cross(Point o, Point a, Point b)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
double dot(Point a, Point b, Point o)
{
    return (a.x-o.x)*(b.x-o.x)+(a.y-o.y)*(b.y-o.y);
}
double dist2(Point a, Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool inter(Point a, Point b, Point c, Point d)
{
    return max(a.x,b.x)>min(c.x,d.x)
        and max(a.y,b.y)>min(c.y,d.y)
        and max(c.x,d.x)>min(a.x,b.x)
        and max(c.y,d.y)>min(a.y,b.y)
        and dblcmp(cross(a,b,c)*cross(a,b,d))<0
        and dblcmp(cross(c,d,a)*cross(c,d,b))<0;
}
bool getInter(Point a, Point b, Point c, Point d, Point &p)
{
    if(not inter(a,b,c,d))
    {
        return false;
    }
    double d0,d1,d2;
    d0=(a.x-b.x)*(d.y-c.y)-(a.y-b.y)*(d.x-c.x);
    d1=cross(c,d)*(a.x-b.x)-cross(a,b)*(c.x-d.x);
    d2=cross(a,b)*(d.y-c.y)-cross(c,d)*(b.y-a.y);
    p.x=d1/d0,p.y=d2/d0;
    return true;
}
void getNearest(double xx, double yy)
{
    Point temp(xx,yy),interP;
    temp.x+=(temp.x-person.x)*1e8;
    temp.y+=(temp.y-person.y)*1e8;
    double minDist=1e10;
    int p=204;
    for(int i=0;i<n;i++)
    {
        if(not getInter(person,temp,vertex[i],vertex[i+1],interP))
        {
            continue;
        }
        double t=dist2(person,interP);
        if(t<minDist)
        {
            minDist=t;
            p=i;
        }
    }
    ans[p]=1;
}
int main()
{
    fscanf(fin,"%d%lf%lf",&n,&person.x,&person.y);
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%lf%lf",&vertex[i].x,&vertex[i].y);
        ans[i]=0;
    }
    vertex[n].x=vertex[0].x, vertex[n].y=vertex[0].y;
    bool flag=false;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(inter(vertex[i],vertex[i+1],vertex[j],vertex[j+1]))
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            break;
        }
    }
    if(flag)
    {
        fprintf(fout,"NOFENCE/n");
    }
    else
    {
        int temp;
        for(int i=0;i<n;i++)
        {
            getNearest(vertex[i].x-1e-4, vertex[i].y-3e-5);
            getNearest(vertex[i].x+1e-4, vertex[i].y+1e-4);
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i])
            {
                ansNum++;
            }
        }
        fprintf(fout,"%d/n",ansNum);
        for(int i=0;i<n-2;i++)
        {
            if(ans[i])
            {
                fprintf(fout,"%.0lf %.0lf %.0lf %.0lf/n",vertex[i].x,vertex[i].y,vertex[i+1].x,vertex[i+1].y);
            }
        }
        if(ans[n-1])
        {
            fprintf(fout,"%.0lf %.0lf %.0lf %.0lf/n",vertex[n].x,vertex[n].y,vertex[n-1].x,vertex[n-1].y);
        }
        if(ans[n-2])
        {
            fprintf(fout,"%.0lf %.0lf %.0lf %.0lf/n",vertex[n-2].x,vertex[n-2].y,vertex[n-1].x,vertex[n-1].y);
        }
    }
    return 0;
}
