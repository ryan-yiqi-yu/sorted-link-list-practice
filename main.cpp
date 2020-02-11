//FINAL EDIT
#include <iostream>
using namespace std;

class SortedLinkedList{
private:
    struct node{
        int data;
        node *NextLink = NULL;
    };
    node *front = NULL;
    node *rear = NULL;
    node *search1 = NULL;
    node *search2 = NULL;
    int count = 0;
    
public:
    bool IsEmpty(){
        if (front == NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void userLoadList(){
        int x;
        cout<<"Enter an integer: ";
        cin>>x;
        while(x!=-1){
            insert(x);
            cout<<"Current list: ";
            printlistdata();
            cout<<"Enter an integer: ";
            cin>>x;
        }
        cout<<"Final list: ";
        printlistdata();
        
    }
    void insert(int NewValue){
        node *NewNode = new node;
        NewNode->data = NewValue;
        count++;
        if (IsEmpty()){
            front = NewNode;
            rear = NewNode;
            return;
        }
        //Smallest value in list
        else if (NewValue <= front->data){
               NewNode->NextLink = front;
               front = NewNode;
               
           }
        //Largest value in list
        else if (NewValue >= rear->data){
            rear->NextLink = NewNode;
            rear = NewNode;
        }
        
        else{
            search1 = front;
            search2 = front->NextLink;
            for (int i = 0; i <count-1; i++){
                //somewhere in between
                if(NewValue <= search2->data && NewValue >= search1->data){
                    search1->NextLink = NewNode;
                    NewNode->NextLink = search2;
                    
                    break;
                }
                search1 = search2;
                search2 = search2->NextLink;
            }
                
            }
    }
    
    void printlistdata(){
        search1 = front;
        cout<<"{";
        while(search1 != NULL){
            cout<<search1->data<<", ";
            search1 = search1->NextLink;
        }
        cout<<"}"<<endl<<endl;
        
    }
    
};


int main(){
    SortedLinkedList test;
    test.userLoadList();
}
