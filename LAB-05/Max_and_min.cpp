#include<stdio.h> 
 
typedef struct  
{ 
    int min; 
    int max; 
}pairs; 
 
pairs getMinMax(int * arr,int l,int h) 
{ 
    pairs p,left,right; 
 
    if(l==h) 
    { 
        p.min=p.max=arr[l]; 
        return p; 
    } 
    else if(l==h+1) 
    { 
        if(arr[l]<arr[h]) 
        { 
            p.min=arr[l]; 
            p.max=arr[h]; 
        } 
        else{ 
            p.min=arr[h]; 
            p.max=arr[l]; 
        } 
        return p; 
    } 
    else{ 
        int mid=(l+h)/2; 
        left=getMinMax(arr,l,mid); 
        right=getMinMax(arr,mid+1,h); 
 
     p.min = (left.min < right.min) ? left.min : right.min; 
     p.max = (left.max > right.max) ? left.max : right.max; 
 
    return p; 
    } 
} 
int main() 
{ 
    int i,n; 
    printf("Enter no.of elements:"); 
    scanf("%d",&n); 
    int arr[n]; 
    printf("Enter the elements:"); 
    for(i=0;i<n;i++) 
    { 
        scanf("%d",&arr[i]); 
    }    
     
    pairs result=getMinMax(arr,0,n-1); 
 
    printf("Minimum = %d\n", result.min); 
    printf("Maximum = %d\n", result.max); 
    return 0; 
     
} 
