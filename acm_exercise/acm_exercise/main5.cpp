#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n>100||n<1) throw exception();
    char (*a)[10000] = new char[n][10000];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        int p=0,q=1;
        while(a[i][q])
        {
            if(a[i][q]==']')
            {
                if(a[i][p]!='[')
                {
                    break;
                }
                else
                    p--;
            }
            else if(a[i][q]==')')
            {
                if(a[i][p]!='(')
                {
                    break;
                }
                else p--;
            }
            else if(a[i][q]=='('||a[i][q]=='[')
            {
                p++;
                a[i][p]=a[i][q];
            }
            else
                break;
            q++;
        }
        if(p==-1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

            