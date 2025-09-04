#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node Node;
Node *Hash_Table[100];
int index(int value){
    return (value % 100);
}
void insert(int value){
    int a = index(value);
    Node *temp = (Node *)malloc(sizeof(Node)); 
    temp -> data = value;
    temp->next = Hash_Table[a];
    Hash_Table[a] = temp;
    cout<<"Value: "<<value<<" inserted successfully\n";
}

void search(int value){
    int found = 0;
    int a = index(value);
    Node *temp;
    temp = Hash_Table[a];
    while(temp != nullptr){
        if(temp -> data == value){
            found = 1;
            break;
        }
        temp = temp -> next;
    }
    if(found == 1){
        cout<<"Value Found\n";
    }
    else{
        cout<<"Value not found\n";
    }
}
void deletion(int key) {
    int i = index(key);
    Node* temp = Hash_Table[i];
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == key) {
            if (prev == NULL) {
                Hash_Table[i] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("%d deleted.\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout<<key<<" not found\n";
}
void display(){
    int i;
    Node *temp;
    for( i = 0 ; i < 100  ; i++){
        cout<<i<<": ";
        temp = Hash_Table[i];
        while(temp != nullptr){
            cout<<"-> "<<temp -> data;
            temp = temp -> next;
        }
        cout<<"\n";
    }
}
int main(){
    int t,n,a;
    while(1){
        cout<<"What do you want to do: \n1. Insert\n2. Delete\n3. Search\n4. Display\n5. exit";
        cin>>n;
        if(n == 1){
            cout<<"Enter value: ";
            cin>>t;
            insert(t);
        }
        else if(n == 2){
            cout<<"Enter Value: ";
            cin>>t;
            deletion(t);
        }
        else if(n == 3){
            cout<<"Enter value: ";
            cin>>t;
            search(t);
        }
        else if(n == 4){
            display();
        }
        else if(n == 5){
            break;
        }
        else{
            cout<<"Invalid operation\n";
        }
    }
}
