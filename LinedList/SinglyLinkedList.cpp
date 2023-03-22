#include <iostream>
using namespace std;

class Node {
    private:
        int val;
        Node* next;

    public:
        Node(int n) {
            val = n;
            next = NULL;
        }
        Node(int n, Node* add){
            val = n;
            next = add;
        }
        static void insertAtStart(Node* &head, int val){
        Node* n = new Node(val, head);
        head = n;
        }

        static void insertAtEnd(Node* &tail, int val){
            Node* n = new Node(val);
            tail->next = n;
            tail = tail->next;
        }

        static void print(Node* &head){
            while(head){
                cout<<head -> val<<" ";
                head = head -> next;
            }
            cout<<endl;
        }

        // static void insertAtMiddle(Node* &head, int n, int val){
        //     Node* nn = head;
        //     while(n > 0){
        //         nn = nn->next;
        //         n--;
        //     };
        //     Node* newNode = new Node(val, nn->next);
        //     nn->next = newNode;
        // }
};

// int main(){
//     Node* head = new Node(0);
//     Node* tail = head;
//     Node::insertAtStart(head, 6);
//     Node::insertAtStart(head, 7);
//     Node::insertAtStart(head, 8);
//     Node::insertAtStart(head, 9);
//     Node::insertAtStart(head, 10);
//     Node::insertAtEnd(tail,1);
//     Node::insertAtEnd(tail,2);
//     Node::insertAtEnd(tail,3);
//     Node::insertAtEnd(tail,4);
//     Node::insertAtEnd(tail,5);
//     Node::print(head);
// }