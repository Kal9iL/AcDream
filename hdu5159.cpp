#include <cstdio>
#include <iostream>

using namespace std;

double getpow(double x,double b)
{
    double temp = 1;
    for(int i = 1;i <= b;i ++)
    {
        temp = temp * x;
    }
    return temp;
}

int main()
{
    int t;
    int x,b;
    scanf("%d",&t);
    for(int Case = 1;Case <= t ;Case ++)
    {
        scanf("%d%d",&x,&b);
        //double ans = 1;
        double tot = getpow(x,b);
        //cout<< tot <<endl;
        double re;
        double temp = tot ;
        double cont = 0;
        //cout <<"tot = "<< temp << endl;
        for(int i = 1;i <= b;i ++)
        {
            re = temp / x;
            //cout << "  " << re << endl;
            cont += re;
            temp = temp - re;
        }
        //cout <<"cont = " <<cont<<endl;
        double sum = 1.0 * (1 + x) * x / 2;
        //cout << "sum = " <<sum << endl;
        printf("Case #%d: %.3f\n",Case,cont / tot * sum);
    }
    return 0;
}

