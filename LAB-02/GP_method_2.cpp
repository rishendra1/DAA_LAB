#include<iostream>
#include<cmath>
using namespace std;
//Sum function is used to calculate the sum of n terms of a Geometric Progression
double Sum(int a,int r,int n){
    double result;
    result = double((a*(pow(r,n)- 1)));
    result = double(result/(r - 1));
    return result;
}
int main(){
    int a,r,n;
    double sum;
    cout<<"Enter first term: ";
    cin>>a;
    cout<<"Enter common ratio: ";
    cin>>r;
    cout<<"Enter no. of terms: ";
    cin>>n;
    sum = Sum(a,r,n);
    cout<<"Result: "<<sum;

}
//Time complexity of this code is  = O(log n)
