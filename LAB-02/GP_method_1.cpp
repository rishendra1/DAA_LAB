#include<iostream>
#include<cmath>
using namespace std;

double Sum(int a,int r,int n){
    double result = 0;
    int i = 0;
    for(i = 1; i <= n ; i++){
        result += a;
        a = a * r;
    }
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
//Time complexity of Sum() = O(n)
