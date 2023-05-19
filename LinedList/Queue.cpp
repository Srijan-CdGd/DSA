#include <iostream>
#include "SinglyLinkedList.cpp"

class Queue{
    private:
        SinglyLinkedList* start = NULL;
        SinglyLinkedList* end = NULL;
        int length = 0;
    
    public:
        Queue(int val){
            start = new SinglyLinkedList(val);
            end = start->getTail();
            length++;
        }

        void insert(int val){
            start->insertAtEnd(val);
            end = start->getTail();
            length++;
        }

        int remove(){
            int v = start->getNodeVal(length);
            start->deleteFromStart();
            length--;
            return v;
        }

        int getLength(){
            return length;
        }

        void print(){
            start->print();
        }
};

int main(){
    Queue* q = new Queue(1);
    q->insert(2);
    q->insert(3);
    q->insert(4);
    q->print();
    cout<<"Length of the current queue: "<<q->getLength()<<endl;
    cout<<q->remove()<<endl;
    q->print();
    cout<<q->remove()<<endl;
    q->print();
    cout<<q->remove()<<endl;
    q->print();
    cout<<"Length of the current queue: "<<q->getLength()<<endl;
    return 0;
}