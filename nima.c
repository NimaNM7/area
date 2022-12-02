// in this editation we explain our code

#include <stdio.h>
#include <math.h>

double max(double a,double b)
{
    if (a>b)
        return a;
    else if (b > a)
        return b;
    else if (a==b)
        return a;
}


double tool(int a,int b,int c,int d)
{
    return pow(pow((a-c),2) + pow((b-d),2),0.5);
}

// this function calculates the circumfrence of the foursquare
double circum(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8)
{
    return  tool(a1,a2,a3,a4) + tool(a3,a4,a5,a6) + tool(a5,a6,a7,a8) + tool(a7,a8,a1,a2);
}

// this function calculates the area of the foursquare
double are(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8)
{
    double a = tool(a1,a2,a3,a4);
    double b = tool(a3,a4,a5,a6);
    double c = tool(a1,a2,a5,a6);
    // calculating the area of half of foursquare (a triangle) with heron formula
    double p1 = (a+b+c)/2;
    double d  = tool(a5,a6,a7,a8);
    double e = tool(a7,a8,a1,a2);
    double p2 = (d+e+c)/2;

    double S1 = pow(p1*(p1-a)*(p1-b)*(p1-c),0.5);
    double S2 = pow(p2*(p2-e)*(p2-d)*(p2-c),0.5);

    return S1 + S2;
}

int main()
{
    int n,a1,a2,a3,a4,a5,a6,a7,a8;
    double big = 0;
    scanf("%d",&n);

    for (int i = 0;i<n;i++)
    {
        scanf("%d %d %d %d %d %d %d %d",&a1,&a2,&a3,&a4,&a5,&a6,&a7,&a8);
        printf("%.02lf \n",area(a1,a2,a3,a4,a5,a6,a7,a8));
        printf("%.02lf\n",circum(a1,a2,a3,a4,a5,a6,a7,a8));

        // this part is for calculating the most ratio of area to circumfrence
        double ratio =  area(a1,a2,a3,a4,a5,a6,a7,a8) / circum(a1,a2,a3,a4,a5,a6,a7,a8);

        big = max(big,ratio);
    }

    printf("%.02lf\n",big);

    return 0;
}