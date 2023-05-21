/*Queue from scratch as the name says QueueS.*/

#include<iostream>
using namespace std;

template <class Q>
class QueueS
{
private:
    class Node{
        public:
            Q val;
            Node* next;
    };
    Node* start = NULL;
    Node* end = NULL;

    int length = 0;

public:
    QueueS(){
        start = new Node();
        start->val = '~';
        end = start;
    }

    QueueS(Q val){
        start = new Node();
        start->val = val;
        start->next = NULL;
        end = start;
        length++;
    };

    void enqueue(Q n){
        if(start == NULL){
            QueueS<Q> (n);
            return;
        }

        if(start->val == '~'){
            start->val = n;
            length++;
            return;
        }

        Node* nn = new Node();
        nn->val = n;
        end -> next = nn;
        end = end->next;
        length++;
    }

    Q dequeue(){
        try{
            if(length == 0){
                throw -1;
            }
            if(start->next == NULL){
                Q n = start->val;
                start->val = '~';
                start == NULL;
                length--;cout<<"Last element dequeued"<<endl;
                return n;
            }

            Node* nn = start;
            Q n = start->val;
            start = start->next;
            free(nn);
            length--;
            return n;
        } catch (int e){
            switch (e)
            {
            case -1:
                cout<<"Queue empty cannot dequeue"<<endl;
                break;
                
            default:
                break;
            }
        }
    }
    int getLength(){
        return length;
    }

    void print(){
        if(length == 0){
            cout<<"Queue Empty"<<endl;
            return;
        }
        Node* temp = start;
        while(temp != NULL){
            cout << temp->val <<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    QueueS<char> q;
    q.enqueue('s');
    q.enqueue('r');
    q.enqueue('i');
    q.enqueue('j');
    q.enqueue('a');
    q.enqueue('n');
    q.print();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();


    return 0;
}