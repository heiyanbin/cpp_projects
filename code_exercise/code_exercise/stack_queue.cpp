template <typename T>
class Stack
{
    static const int default_size = 100;
    int size;
    T *a[];
    int top;

public:
    Stack() :top(-1)
    {
        size = default_size; 
        a= new T[size];
    }
    Stack(int n) :size(n),:top(-1)
    {
        a= new T[size];
    }
    ~Stack()
    {
        if(a) delete[] a;
    }
    void push(T item)
    {
        if(top+1>size-1) throw exception("stack overflow.");
        top=top+1;
        a[top]=item;
    }
    T pop()
    {
        if(top<0) throw exception("empty stack.");
        return a[top--];
    }
    bool isEmpty()
    {
        return top<0;
    }
};

template <typename T>
struct Node 
{
    T data;
    Node *next;
    Node(T value):data(value){}
};
template <typename T>
class Stack2
{
    Node<T> * top;
public:
    void push(T item)
    {
        if(!top)
        {
            top = new Node(item);
        }
        else
        {
            Node<T> * newNode = new Node(item);
            newNode->next=top;
            top=newNode;
        }
    }
    T pop()
    {
        if(!top) throw new exception("empty stack could not pop.");
        T item = top->data;
        Node<T> * node  = top;
        top=node->next;
        delete node;
        return node->data;
    }
    bool isEmpty()
    {
        return top==NULL;
    }
};

template <typename T>
class Queue
{
    int size, front, rear;
    T a[];
    static const int DEFAULT_SIZE = 100;
public:
    Queue():size(DEFAULT_SIZE),front(-1),rear(-1)
    {
        a = new T[size];
    }
    Queue(int n):size(n),front(-1),rear(-1)
    {
        a = new T[size];
    }
    ~Queue()
    {
        if(a) delete[] a;
    }

    void enQueue(T item)
    {
        if((rear+1/)%size==front) throw new exception("Full.");
        rear=(rear+1)%size;
        a[rear]=item;
    }
    T deQueue()
    {
        if(front==rear) throw new exception("Empty.");
        front=(front+1)%size;
        return a[front];
    }
    bool isEmpty()
    {
        return front==rear;
    }
    bool isFull()
    {
        return front+1==rear;
    }
};

template <typename T>
class Queue2
{
    Node<T> * front, rear;
public:
    Queue2():front(NULL),rear(NULL){}
    void enQueue(T item)
    {
        Node<T> * newNode = new Node<T>(item);
        if(!rear)
        {
            rear = newNode;
            front = newNode;
        }
        else
        {
            rear->next = newNode;
            rear=newNode;
        }
    }

    T deQueue()
    {
        if(front==NULL) throw new exception("Empty Queue.");
        T item = front->data;
        Node<T>* node = front;
        front =front->next;
        delete node;
    }
};

template <typename T>
class ArrayList
{
    int block_size;
    int block_count;
    int block_offset;
    Node<T*> *head , *rear;
public:
    ArrayList():block_size(100),block_count(1),block_offset(-1)
    {
        head = new Node<T*>(new T[block_size]);
        rear=head;
    }
    T get(int i)
    {
        int block_num = i/block_size;
        int offset = i%/block_size;
        Node<T*> *p= head;
        for(int i= 0;i<block_num;i++)
            p=p->next;
        return p->data[offset];
    }
    void add(T item)
    {
        if(block_offset>=blok_size-1)
        {
            rear->next = new Node<T*>(new T[block_size]);
            rear = rear->next;
            rear->data[0]=item;
            block_offset=0;
        }
        else
        {
            block_offset++;
            rear->data[block_offset] =item;
        }
    }
};