#include<iostream>

using namespace std;

int merge(int a[],int first, int mid, int last){
    int n1,n2;
    n1 = mid - first + 1;
    n2 = last - mid;
    int L[100],R[100];
    int i,j;
    for(i = 0 ; i < n1 ; i++){
        L[i] = a[first + i];
    }
    for(j = 0 ; j < n2 ; j++){
        R[j] = a[mid + 1 + j];
    }
    int k = first;
    i = 0, j = 0;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            a[k] = L[i];
            i++;
            k++;
        }
        else{
            a[k] = R[j];
            j++;
            k++;
        }
    }
    while(i < n1)
    {
        a[k] = L[i];
        k++; i++;
    }
    
    while(j<n2)
    {
        a[k] = R[j];
        k++; j++;
    }
}
void Merge_Sort(int a[],int first, int last){
    if(first < last){
        int mid = (first + last) / 2;
        Merge_Sort(a,first,mid);
        Merge_Sort(a,mid + 1,last);
        merge(a,first,mid,last);
    }
}
int main(){
    int n,a[100];
    cout<<"Enter size of array: ";
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        cout<<"Enter element: ";
        cin>>a[i];
    }
    Merge_Sort(a,0,n - 1);
    for(int j = 0 ; j < n ; j++){
        cout<<a[j]<<" ";
    }
}
