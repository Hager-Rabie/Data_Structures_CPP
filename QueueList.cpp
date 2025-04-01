   #include<bits/stdc++.h>
    using namespace std;
 #define endl "\n"

 void FOI () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

 
    class  SimpleQueue {
    private:
      int rear , front , size;
       int * Queue ;
       public:
      SimpleQueue(int s)   {
        size = s;
         rear = front = -1 ;
          Queue = new int [size] ;
      }
       bool isEmpty() {
        return (rear == -1 && front == -1) ;
       }
       bool isFull() {
        return (rear==size-1) ;
       }
       void enQueue(int item) {
          if(isFull()) {
            cout << "queue is full" << "\n" ;
            return ;
          }
          if(isEmpty()) {
            cout << "queue is empty" << "\n" ;
            front = rear = 0;
          }
          else{
            rear++;
          }
          Queue[rear] = item ;
       }
       int Front() {
        if(isEmpty()) {
          cout << "queue is empty" << "\n" ;
          return -1 ;
        }
        return Queue[front] ;
       }
       int Rear() {
        if(isEmpty()) {
          cout << "queue is empty" << "\n" ;
          return -1 ;
        }
        return Queue[rear] ;
       }
       int Dequeue() {
        int x =0;
        if(isEmpty()) {
          cout << "queue is empty" << "\n" ;
          return -1 ;
        }
         else if (front == rear) {
          x = Queue[front] ;
             front = rear = -1 ;
             
         }
           else{
              x = Queue[front] ;
             front++;
           }
           return x ;
       }
       void display() {
        if(isEmpty()) {
          cout << "queue is empty" << "\n" ;
          return  ;
        }
          for(int i=front ; i<=rear ;i++) {
            cout << Queue[i] << " " ;
          }
           cout << "\n" ;
       }
   
  };
  
 class CircularQueue{
     private:
      int*q;
      int _size , rear , front ;
      public:
       CircularQueue(int size) {
         size = size ;
          front = rear = -1 ;
           q = new int [_size] ;
       }
       bool isEmpty() {
        return (front ==-1 &&rear ==-1) ;
       }
        bool isFull() {
          return ((rear+1)%_size == front) ;
        }
        void enQueue(int item) {
          if(isFull()) {
            cout << "queue is full" << "\n" ;
            return ;
          }
          if(isEmpty()) {
            cout << "queue is empty" << "\n" ;
            front = rear = 0;
          }
          else{
            rear = (rear+1)%_size ; 
          }
          q[rear] = item ;
       }
       int Dequeue() {
        int x =0;
        if(isEmpty()) {
          cout << "queue is empty" << "\n" ;
          return -1 ;
        }
         else if (front == rear) {
             x = q[front] ;
             front = rear = -1 ;
             
         }
           else{
              x = q[front] ;
             front= (front+1)%_size;
           }
           return x ;
       }
       void Display() {
        if(isEmpty()) {
          cout << "queue is empty" << "\n" ;
         return ;
        }
        for(int i= front;i!=rear;(i+=1)%_size){
          cout << q[i] << "\n" ;
        }
        cout << q[rear] << "\n" ;
       }
        int Front() {
          if(isEmpty()) {
            cout << "queue is empty" << "\n" ;
           return -1;
          }
          return q[front] ;
        }
        int Rear() {
          if(isEmpty()) {
            cout << "queue is empty" << "\n" ;
           return -1;
          }
           return q[rear] ;
        }
        ~CircularQueue() {
          delete [] q ;
        }
 };
  
int main() {
    FOI () ;
  
	return 0;
}
