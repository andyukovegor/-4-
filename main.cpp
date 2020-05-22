#include <iostream>
#include "Two_way_queue.h"

int main()
{
    Two_way_queue<int> twq(5);
    twq.print();

    twq.pushBack(14);
    twq.print();
    twq.pushBack(4);
    twq.print();
    twq.pushFront(2001);
    twq.print();
    twq.popFront(2);
    twq.print();



    Two_way_queue<char> twq1(5);
    twq1.pushBack('L');
    twq1.pushBack('A');
    twq1.pushBack('B');
    twq1.pushBack('A');
    twq1.pushBack('4');
    twq1.print();


    return 0;
}
