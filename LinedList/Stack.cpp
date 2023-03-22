#include<iostream>
#include "SinglyLinkedList.cpp"

class Stack{
    private:
        Node* peek = new Node(0);
    public:
        void push(int val){
            Node* nn = new Node(val, peek);

        }
};

int main(){
    return 0;
}