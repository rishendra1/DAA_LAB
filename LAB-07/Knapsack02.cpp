#include <iostream>
using namespace std;

void fractional_knapsack2(int n, int capacity, int weight[], int profit[]) {
    double maxprofit = 0;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (profit[i] < profit[j]) {
                int v = profit[i];
                profit[i] = profit[j];
                profit[j] = v;

                int w = weight[i];
                weight[i] = weight[j];
                weight[j] = w;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            capacity -= weight[i];
            maxprofit += profit[i];
        } else {
            maxprofit += profit[i] * ((double)capacity / weight[i]);
            break;
        }
    }
    cout<<"Total Profit of method 3 : "<<maxprofit<<endl;
}

int main() {
    int capacity, n, i;
    cout<<"Enter number of items: ";
    cin>>n;
    cout<<"Enter the capacity of the knapsack: ";
    cin>>capacity;
    int profit[n], weight[n];
    for (i = 0; i < n; i++) {
        cout<<"Enter the weight and value of item "<<i + 1<<": ";
        cin>>weight[i]>>profit[i];
    }
    fractional_knapsack2(n, capacity, weight, profit);
    return 0;
}
