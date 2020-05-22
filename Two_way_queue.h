#ifndef TWO_WAY_QUEUE_H_INCLUDED
#define TWO_WAY_QUEUE_H_INCLUDED

#include <iostream>

using namespace std;

template<typename T>
class Two_way_queue
{
private:
    size_t size;
    size_t count;
    T * data;
public:
    Two_way_queue();
    Two_way_queue(size_t size);
    Two_way_queue(const Two_way_queue &twq);
    ~Two_way_queue();

    Two_way_queue<T> & operator=(const Two_way_queue<T> &twq);

    bool pushBack(T value);
    bool pushFront(T value);
    void popBack(T value);
    void popFront(T value);
    void topBack(T &value) const;
    void topFront(T &value) const;
    void clear();
    bool isEmpty()const;
    size_t Size()const;
    void print() const;
};

template<typename T>
Two_way_queue<T>::Two_way_queue()
{
    size = 1;
    count = 0;
    data = new T[size];
}

template<typename T>
Two_way_queue<T>::Two_way_queue(size_t size)
{
    if(size < 1)
    {
        size = 1;
    }

    this->size = size;
    this->count = 0;
    this->data = new T[size];
}

template<typename T>
Two_way_queue<T>::Two_way_queue(const Two_way_queue &twq)
{
    this->size = twq.size;
    this->count = twq.count;
    this->data = new T[twq.size];

    for(size_t i=0;i<twq.count;i++)
    {
        this->data[i]=twq.data[i];
    }
}

template<typename T>
Two_way_queue<T>::~Two_way_queue()
{
    if(data) delete [] data;
}

template<typename T>
Two_way_queue<T> & Two_way_queue<T>::operator=(const Two_way_queue<T> &twq)
{
    if(data) delete [] data;

    this->size = twq.size;
    this->count = twq.count;
    this->data = new T[twq.size];

    for(size_t i=0;i<twq.count;i++)
    {
        this->data[i]=twq.data[i];
    }
}

template<typename T>
bool Two_way_queue<T>::pushBack(T value)
{
    if(count < size)
    {
        data[count] = value;
        ++count;
        return true;
    }
    return false;

}


template<typename T>
bool Two_way_queue<T>::pushFront(T value)
{
    int i;
    for (i=count;i>0; i--)
    {
      data[i]=data[i-1];
    }
    if(count < size)
    {

        data[0] = value;
        ++count;
        return true;
    }
    return false;

}



template<typename T>
void Two_way_queue<T>::popFront(T value)
{

        data[0] = value;

}

template<typename T>
void Two_way_queue<T>::popBack( T value)
{


        data[count-1] = value;

}

template<typename T>
void Two_way_queue<T>::topFront(T &value) const
{

        value = data[0];

}

template<typename T>
void Two_way_queue<T>::topBack(T &value) const
{

        value = data[count-1];

}


template<typename T>
void Two_way_queue<T>::clear()
{
    count = 0;
}

template<typename T>
size_t Two_way_queue<T>::Size()const
{
    return size;
}

template<typename T>
bool Two_way_queue<T>::isEmpty()const
{
    return count == 0;
}

template<typename T>
void Two_way_queue<T>::print() const
{
    cout << "Two-way queue size: " << size << ", count: " << count << endl;
    for(size_t i=0;i<count;i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

#endif // TWO_WAY_QUEUE_H_INCLUDED
