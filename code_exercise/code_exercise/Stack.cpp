#include <vector>
#include <iostream>
using namespace std;

bool isDigit(char c)
{
    return c>='0' && c<='9';
}
int evalSubfix(char * subfix)
{
    if(!subfix) throw invalid_argument("null argument.");
    vector<int> operand;
    char*p = subfix;
    while(*p)
    {
        if(isDigit(*p))
        {
            int v = 0;
            while(isDigit(*p))
            {
                v=10*v+*p-'0';
                p++;
            }
            operand.push_back(v);
        }
        else if(*p==' '||*p=='\t')
        {
            p++;
        }
        else
        {
            int y = operand.back();
            operand.pop_back();
            int x = operand.back();
            operand.pop_back();
            switch (*p)
            {
            case '+':
                operand.push_back(x+y);
                break;
            case '-':
                operand.push_back(x-y);
                break;
            case '*':
                operand.push_back(x*y);
                break;
            case '/':
                operand.push_back(x/y);
                break;
            }
            p++;
        }
    }
    if(operand.size()==1) 
        return operand.back();
    throw invalid_argument("invalid subfix expression.");
}
void testEvalSubfix()
{
    cout<<evalSubfix("1 2 +4*")<<endl;
}

bool opCompare(char a, char b)
{
    if(a!='+'&& a!='-'&&a!='*'&&a!='/'&&b!='+'&&b!='-'&&b!='*'&&b!='/') 
        throw invalid_argument("invalid operator.");
    if(a=='*'||a=='/') return true;
    if(a=='+'||a=='-') return false;
    
}
char * midfixToSubfix(char* midfix)
{
    if(!midfix) throw invalid_argument("null argument");
    vector<char> op;
    char * subfix = new char[2*strlen(midfix)];
    char *p= midfix, *q =subfix;
    while(*p)
    {
        if(isDigit(*p))
        {
            while(*p && isDigit(*p))
                *q++=*p++;
            *q++=' ';
        }
        else if(*p ==' '||*p=='\t')
            p++;
        else
        {
            if(op.size()<1) 
                op.push_back(*p);
            else if(opCompare(*p, op.back()))
                op.push_back(*p);
            else
            {    
                while(op.size()>0 && !opCompare(*p, op.back()))
                {
                    *q++ = op.back();
                    *q++=' ';
                    op.pop_back();
                }
                op.push_back(*p);
            }
            p++;
        }
    }
    if(op.size()>0) 
        *q++=op.back();
    *q='\0';
    return subfix;
}
void testMidfixToSubfix()
{
    char * a= midfixToSubfix("1+20*3-5");
    cout<<a;
}

void testEvalMidfix()
{
    char * a= "1+20*3-5";
    cout<<a<<endl;
    cout<<evalSubfix(midfixToSubfix("1+20*3-5"))<<endl;
}