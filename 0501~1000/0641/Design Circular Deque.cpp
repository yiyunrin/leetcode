// use circular array
class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        n = k + 1;
        deque = vector<int> (n);
        head = 0, tail = 0;
    }
    
    bool insertFront(int value) {
        if(this->isFull())
            return false;
        deque[head] = value;
        head = (head - 1 + n) % n;
        return true;
    }
    
    bool insertLast(int value) {
        if(this->isFull())
            return false;
        tail = (tail + 1) % n;
        deque[tail] = value;
        return true;
    }
    
    bool deleteFront() {
        if(this->isEmpty())
            return false;
        head = (head + 1) % n;
        return true;
    }
    
    bool deleteLast() {
        if(this->isEmpty())
            return false;
        tail = (tail - 1 + n) % n;
        return true;
    }
    
    int getFront() {
        if(this->isEmpty())
            return -1;
        return deque[(head + 1) % n];
    }
    
    int getRear() {
        if(this->isEmpty())
            return -1;
        return deque[tail];
    }
    
    bool isEmpty() {
        if(head == tail)
            return true;
        return false;
    }
    
    bool isFull() {
        if(head == (tail + 1) % n)
            return true;
        return false;
    }
private:
    int head, tail, n;
    vector<int> deque;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
