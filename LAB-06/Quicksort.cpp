#include<iostream>

using namespace std;

int partition(int a[],int low, int high){
    int i,j,pivot,temp;
    pivot = a[high];
    i = low - 1;
    for(j = low; j< high ; j++){
        if (a[j] <= pivot){
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;
    return i+1;
}
void QuickSort(int a[] , int low, int high){
    if(low < high){
        int piv = partition(a,low,high);
        QuickSort(a,low,piv - 1);
        QuickSort(a,piv + 1, high);
    }
}
int main(){
    int a[100],i,n;
    cout<<"Enter size: ";
    cin>>n;
    for(i = 0 ; i < n ; i++){
        cout<<"Enter elements- ";
        cin>>a[i];
    }
    QuickSort(a,0,n-1);
    
    cout<<"After sorting - \n";
    for(i = 0 ; i < n ; i++){
        cout<<a[i]<<" ";
    }
}
