#include<iostream>
#include "SinglyLinkedList.cpp"

class Stack{
    private:
        SinglyLinkedList* top;
        int length = 0;

    public:
        Stack(int val){
            top = new SinglyLinkedList(val);
            length++;
        }

        int peek(){
            return top->getNodeVal(1);
        }

        void push(int val){
            top->insertAtStart(val);
            length++;
        }

        int pop(){
            int v = top->getNodeVal(1);
            top->deleteFromStart();
            length--;
            cout<<endl<<"popped value: "<<v<<endl;
            return v;
        }

        int getLength(){
            return top->getLength();
        }

        void print(){
            top->print();
        }
        
};

int main(){
    Stack* top = new Stack(5);
    top->push(4);
    top->push(3);
    top->push(2);
    top->push(1);

    top->print();

    cout<<top->pop()<<endl;
    top->print();
    
    cout<<top->pop()<<endl;
    top->print();
    
    return 0;
}
