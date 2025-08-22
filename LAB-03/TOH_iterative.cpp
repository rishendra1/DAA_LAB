#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int n;
    cout<<"Enter number of disks: ";
    cin>>n;

    int moves = pow(2, n) - 1; 
    char src = 'I', aux = 'J', dest = 'K';
    if (n % 2 == 0) {
        char temp = dest;
        dest = aux;
        aux = temp;
    }
    printf("The sequence of moves:\n");
    for (int i = 1; i <= moves; i++) {
        int disk = __builtin_ctz(i) + 1;  
        if (i % 3 == 1)
            cout<<"Move disk "<<disk<<" from "<<src<<" to "<<dest<<"\n";
        else if (i % 3 == 2)
            cout<<"Move disk "<<disk<<" from "<<src<<" to "<<aux<<"\n";
        else
            cout<<"Move disk "<<disk<<" from "<<aux<<" to "<<dest<<"\n";
    }

    return 0;
}
