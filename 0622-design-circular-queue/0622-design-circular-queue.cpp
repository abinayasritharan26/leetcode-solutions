class MyCircularQueue {
public:
    int *arr;
    int front;
    int rear;
    int count;
    int capacity;

    MyCircularQueue(int k) {
        capacity = k;
        arr = new int[k];

        front = 0;
        rear = 0;
        count = 0;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;

        arr[rear] = value;
        rear = (rear + 1) % capacity;
        count++;

        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;

        front = (front + 1) % capacity;
        count--;

        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;

        return arr[front];
    }

    int Rear() {
        if (isEmpty())
            return -1;

        return arr[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        if (count == 0)
            return true;
        else
            return false;
    }

    bool isFull() {
        if (count == capacity)
            return true;
        else
            return false;
    }
};