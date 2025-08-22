#include<iostream>

using namespace std;

int MAX = 100;
struct stack{
    int a[100],
    top;
};
void init(stack *s){
    s -> top = -1;
}
typedef struct stack stack;
void push(stack *s,int value){
    if(s -> top == MAX - 1){
        cout<<"Stack is Fulled";
    }
    else{
        (s -> top)++;
        s -> a[s -> top] = value;
        cout<<"Value "<<value<<" is pushed into the stack.";
    }
    cout<<"\n";
}
void peek(stack *s){
    if(s -> top == -1){
        cout<<"Empty Stack.";
    }
    else{
        cout<<"Peek Value: "<<s -> a[s -> top];
    }
    cout<<"\n";
}
int pop(stack *s){
    int popped_val;
    if(s -> top == -1){
        return -1;
    }
    else{
        popped_val = s -> a[s -> top];
        (s -> top)--;
        return popped_val;
    }
}
void display(stack *s){
    if(s -> top == -1){
        cout<<"Empty Stack.";
    }
    else{
        int i;
        for(i = s -> top ; i >= 0 ; i--){
            cout<<s -> a[i]<<" ";
        }
    }
    cout<<"\n";
}
int main(){
    stack s;
    init(&s);
    int n;
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);
    push(&s,5);
    display(&s);
    n = pop(&s);
    cout<<"Value popped: "<<n<<"\n";
    display(&s);
}
