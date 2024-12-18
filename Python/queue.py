class Queue:
    def __init__(self):
        self.queue=[]

    def push(self, item):
        self.queue.append(item)

    def dequeue(self):
        if self.isempty():
            print("Queue is empty")
            return None
        return self.queue.pop(0)

    def peek(self):
        if self.isempty():
            print("Queue is empty")
            return None

        return self.queue[0]

    def isempty(self):
        return len(self.queue)==0

    def size(self):
        return len(self.queue)



q=Queue()

q.push(5)
q.push(10)
q.push(15)


print("front element is: ", q.peek())
print("dequeued element is: ", q.dequeue())
print("is queue empty: ", q.isempty())
print("size of queue: ", q.size())

    
        
