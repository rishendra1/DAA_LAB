#include <stdio.h> 
#include <limits.h> 
 
int max(int a, int b, int c) { 
    return (a > b ? (a > c ? a : c) : (b > c ? b : c)); 
} 
 
int maxCrossingSum(int arr[], int low, int mid, int high) { 
    int sum = 0; 
    int left_sum = INT_MIN; 
    for (int i = mid; i >= low; i--) { 
        sum += arr[i]; 
        if (sum > left_sum) 
            left_sum = sum; 
    } 
 
    sum = 0; 
    int right_sum = INT_MIN; 
    for (int i = mid + 1; i <= high; i++) { 
        sum += arr[i]; 
        if (sum > right_sum) 
            right_sum = sum; 
    } 
 
    return left_sum + right_sum; 
} 
 
int maxSubArraySum(int arr[], int low, int high) { 
    if (low == high) 
        return arr[low]; 
 
    int mid = (low + high) / 2; 
 
    return max( 
        maxSubArraySum(arr, low, mid), 
        maxSubArraySum(arr, mid + 1, high), 
        maxCrossingSum(arr, low, mid, high) 
    ); 
} 
 
int main() { 
    int n; 
    printf("Enter the number of elements: "); 
    scanf("%d", &n); 
 
    int arr[n]; 
    printf("Enter the array elements: "); 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
    } 
 
    int max_sum = maxSubArraySum(arr, 0, n - 1); 
printf("Maximum subarray sum is %d\n", max_sum); 
return 0; 
} 
