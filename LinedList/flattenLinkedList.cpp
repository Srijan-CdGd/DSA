#include<iostream>

using namespace std;
struct Node{
    int data;
    Node* next;
    Node* btm;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->btm = NULL;
    }

    Node(){
        this->data = 0;
        this->next = NULL;
        this->btm = NULL;
    }
};

Node* merge(Node* a, Node* b){
    Node* temp = new Node();
    Node* res = temp;
    while(a!= NULL && b!= NULL){
        if(a->data < b->data){
            temp->btm = a;
            a=a->btm;
            temp = temp->btm;
        }else{
            temp -> btm = b;
            b = b->btm;
            temp = temp->btm;
        }
    }
    if(a) temp->btm = a;
    else temp->btm = b;
    return res->btm;
}

Node* flatten(Node* head){
    if(head == NULL || head->next == NULL) return head;

    head->next = flatten(head->next);

    head = merge(head, head->next);

    return head;
}

int main(){
    int n;
    cin >> n;
    Node* head = new Node(0);
    Node* temp = head;
    Node* tmp = head;
    for(int i = 0; i < n; i++){
        int m;
        cin>>m;
        cin>>tmp->data;
        tmp->next = new Node();
        temp = tmp;
        for(int j = 0; j < m-1; j++){
            int k;
            cin>>k;
            temp->btm = new Node(k);
            temp = temp ->btm;
        }
        tmp = tmp->next;
    }

    head = flatten(head);
    cout<<head<<" "<<head->data<<endl;
    
    tmp = head;

    while(tmp){
        temp = tmp;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->btm;
        }
        tmp = tmp->next;
        cout<<endl;
    }
    cout<<endl;

    head = head -> btm;
    
    while(head){
        cout<<head->data<<" ";
        head = head->btm;
    }
}