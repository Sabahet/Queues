#include <iostream>
#include <string>
using namespace std;

int MAX =100;

struct Customer{
    string CustomerName[15];
    int ArrivalTime;
    int ServiceTime;
    int FinishTime;
    
};

struct FCFSQueue{
    Customer CustomerList[100];
    int length;
    
};

bool IsEmpty(FCFSQueue);
int GetLength(FCFSQueue);
void Enqueue(FCFSQueue&, Customer);
void Dequeue(FCFSQueue&, Customer&);



int main() {
    
    FCFSQueue myQueue;
    myQueue.length=0;
    Customer newCus;
    newCus.CustomerName[0]="Tatiana";
    newCus.ArrivalTime = 1;
    newCus.ServiceTime=0;
    newCus.FinishTime = 0;
    
    Enqueue(myQueue,newCus);
    cout << myQueue.CustomerList[myQueue.length-1].CustomerName[0] << " has arrived" << endl;
    
       newCus.CustomerName[0]="Sab";
       newCus.ArrivalTime = 3;
       newCus.ServiceTime=0;
       newCus.FinishTime = 0;
    
    Enqueue(myQueue,newCus);
    cout << myQueue.CustomerList[myQueue.length-1].CustomerName[0] << " has arrived" << endl;

    
    Dequeue(myQueue, newCus);
     cout << newCus.CustomerName[0] << " is Leaving" << endl;
    
    Dequeue(myQueue, newCus);
     cout << newCus.CustomerName[0] << " is Leaving" << endl;
    
    Dequeue(myQueue, newCus);
     
    
    return 0;
}


bool IsEmpty(FCFSQueue queue)
{
    if(queue.length==0){
        return true;
    }else{
        return false;
    }

}


int GetLength(FCFSQueue queue)
{
    return queue.length;
}


void Enqueue(FCFSQueue &queue, Customer cus)
    {
        if(queue.length < 100){
            //I tried using a global variable named MAX instead of 100 but it didnt work :)
            
            queue.CustomerList[queue.length] = cus;
            queue.length++;
        }else{
            
            cout << "Unfortunaltey your Queue is full. Try removing some customers! " << endl;
            
        }

    }


void Dequeue(FCFSQueue &queue, Customer &cus){
    
    if(queue.length >0){
        cus = queue.CustomerList[0];
        queue.length--;
        
        for(int i=0; i<=queue.length; i++){
            queue.CustomerList[i] = queue.CustomerList[i+1];
    
        }
        
    }else{
        cout << "The Queue is empty! " << endl;
        
    }
    
}



