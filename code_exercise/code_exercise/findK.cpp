#include "lib.h"


int partition(int a[], int n)
{
	if(!a||n<1) return -1;
    if(n==1)
        return 0;
    
    int i= 0, j=n-1;
    int x = a[0];
	while(i<j)
	{
		while (a[j]>=x && i< j) {
            j--;
        }
        if (i<j) {
            a[i]=a[j];
            i++;
        }
        while (a[i]<x && i<j) {
            i++;
        }
        if(i<j){
            a[j]=a[i];
            j--;
        }
	}
	a[i]=x;
            
    return i;
}
int findK(int a[], int n, int k)
{
	if(!a||n<1||k>n) return -1;
    
    int j = partition(a,n);
	if(k-1<j)
        return findK(a,j+1,k);
	else if(k-1>j)
        return findK(a+j+1,n-j-1, k-j-1);
    else return a[j];
        
}
void testFindK()
{
    int a[] ={3,2,1,4,7,6,5};
	int k = findK(a,7,4);
	
    std::cout << k<< std::endl;
}






         
