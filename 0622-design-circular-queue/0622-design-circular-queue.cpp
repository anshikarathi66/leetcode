class MyCircularQueue {
public:
    int* arr;
    int size;
    int front;
    int rear;
    
    MyCircularQueue(int k) {
        arr = new int[k];
        size=k;
        front=-1;
        rear=-1;
    }
    
    bool enQueue(int value) {
        //first element
        if(front==-1 && rear==-1){
            front = 0;
            rear = 0;
            arr[rear] = value;
            return true;
        }
        //rest elements while rear+1<size
        else if(rear+1<size && rear+1 != front){
            rear++;
            arr[rear] = value;
            return true;
        }
        else if(rear+1>=size && front != 0){
            rear=0;
            arr[rear] =  value;
            return true;
        }
        
        return false;
    }
    
    bool deQueue() {
        //if no element
        if(front == -1 && rear == -1){
            return false;
        }
        //one element
        else if(front == rear){
            front = -1;
            rear = -1;
            return true;
        }
        //for rest
        else if(front+1>=size){
            front = 0;
            return true;
        }
        else if(front+1<size){
            front++;
            return true;
        }
        
        return false;
    }
    
    int Front() {
        if(front == -1){
            return -1;
        }
        else{
            return arr[front];
        }
    }
    
    int Rear() {
        if(rear == -1)
            return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front == -1 && rear == -1){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(rear+1 == front || (rear+1 >= size && front==0) || (front+1 >=size && rear==0)){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */