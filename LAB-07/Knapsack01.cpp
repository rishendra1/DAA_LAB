#include <iostream>
using namespace std;

void fractional_knapsack(int n, int capacity, int weight[], int profit[]) {
    double ratio[n], tprof = 0;
    int i, j;
    for (i = 0; i < n; i++) {
        ratio[i] = (double)profit[i] / weight[i];
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                double temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                int v = profit[i];
                profit[i] = profit[j];
                profit[j] = v;

                int w = weight[i];
                weight[i] = weight[j];
                weight[j] = w;
            }
        }
    }

    int currweight = 0;
    for (i = 0; i < n; i++) {
        if (currweight + weight[i] <= capacity) {
            currweight += weight[i];
            tprof += profit[i];
        } else {
            int remain = capacity - currweight;
            tprof += (double)profit[i] / weight[i] * remain;
            break;
        }
    }
    cout<<"Maximum Profit: "<<tprof<<"\n";
}
int main() {
    int capacity,n,i;
    cout<<"Enter number of items: ";
    cin>>n;
    cout<<"Enter the capacity of the knapsack: ";
    cin>>capacity;
    int profit[n], weight[n];
    for (i = 0; i < n; i++) {
        cout<<"Enter the weight and value of item " << i + 1<<": ";
        cin>>weight[i]>>profit[i];
    }
    fractional_knapsack(n, capacity, weight, profit);
    return 0;
}
