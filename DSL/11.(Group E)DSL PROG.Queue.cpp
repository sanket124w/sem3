/*Queues are frequently used in computer programming, and a
typical example is the creation of a job queue by an operating
system. If the operating system does not use priorities, then the
jobs are processed in the order they enter the system. Write C++
program for simulating job queue. Write functions to add job and
delete job from queue.*/


#include<iostream>
using namespace std;

class queueJob
{
    private:
        int front;
        int rear;
        int size;
        int Queue[100];

    public:
        queueJob(int size)
        {
            front=-1;
            rear=-1;
            this->size=size;
            
        }

        int isEmpty();
        int isFull();
        void enQueue(int ele);
        void deQueue();
        int getFront();
        void display();

};


int queueJob::isEmpty()
{
    return(front==rear)?1:0;
}


int queueJob::isFull()
{
    return(rear==size-1)?1:0;
}

void queueJob::enQueue(int ele)
{
    if(!isFull())
    {
        rear++;
        Queue[rear]=ele;
    }
}

void queueJob::deQueue()
{
    int ele;
    if(!isEmpty())
    {
        front++;
        ele=Queue[front];
        cout<<ele<<" Element Deleted !!"<<endl;
    }
}

int queueJob::getFront()
{
    if(!isEmpty())
    {
        return(Queue[front+1]);
    }
}

void queueJob::display()
{
    int i;
    cout<<"Job Queue is :";
    for(i=front+1;i<=rear;i++)
    {
        cout<<Queue[i]<<endl;
    }
}



int main()
{
    int size,ch,x;
    cout<<"Enter the size of the Queue :";
    cin>>size;
    queueJob qj(size);
    do
    {
        cout<<"------------------------------------------------------------------------------"<<endl;
        cout<<"\tMENU"<<endl;
        cout<<"1. Add Job to Queue\n2. Delete Job to Queue\n3. Display Job Queue\n4. Exit"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        cout<<"------------------------------------------------------------------------------"<<endl;
        
        switch(ch)
        {
            case 1: cout<<"Enter the job data to insert :";
                    cin>>x;
                    qj.enQueue(x);
                    break;
            
            case 2: qj.deQueue();
                    break;

            case 3: qj.display();
                    break;
            
            case 4: exit(0);
        }

    } while (ch>=1 && ch<=4);
    

    return 0;
}

//Output
/*
------------------------------------------------------------------------------
        MENU
1. Add Job to Queue
2. Delete Job to Queue
3. Display Job Queue
4. Exit
Enter your choice :1
------------------------------------------------------------------------------
Enter the job data to insert :10
------------------------------------------------------------------------------
        MENU
1. Add Job to Queue
2. Delete Job to Queue
3. Display Job Queue
4. Exit
Enter your choice :3
------------------------------------------------------------------------------
Job Queue is :10
------------------------------------------------------------------------------
        MENU
1. Add Job to Queue
2. Delete Job to Queue
3. Display Job Queue
4. Exit
Enter your choice :4
------------------------------------------------------------------------------
*/

