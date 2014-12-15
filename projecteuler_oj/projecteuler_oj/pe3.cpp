#include <cmath>
#include <iostream>
using namespace std;
bool isPrime(int x)
{
    int upper= sqrt(x);
    for(int i=2;i<=upper;++i)
        if((x%i)==0)
            return false;
     return true;
}
int pe3()
{
    long long s = 600851475143;
    int f=2,maxf=2;;
    for(;f<=s;f++)
    {
        if(isPrime(f))
        {  
            while((s%f)==0)
            {
                maxf=f;
                cout<<f<<endl;
                s=s/f;
            }
        }
    }
    return maxf;
}
