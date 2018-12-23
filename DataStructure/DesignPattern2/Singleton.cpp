#include"stdafx.h"
#include"Design.h"
class Printer;
class Lock
{
public:
    Lock() { Printer::l.lock(); }
    ~Lock() { Printer::l.unlock(); }
};
class Printer
{
    char * p=nullptr;
    Printer() {}
    Printer(Printer&) {}
    static Printer* instance;
    static atomic<int> count;
    static mutex l;
public:
    friend class Lock;
    static Printer* getInstance()
    {
        if (instance == NULL)
        {
            Lock l;
            if (instance == NULL) {
                instance = new Printer;
            }
        }
        return instance;
    }
    void display() { cout << "Demo of singlton " << count++ << endl; fflush(stdout); }
};
Printer* Printer::instance;
mutex Printer::l;
atomic<int> Printer::count = 0;
void print()
{
    for(int i=0;i<5;i++)
    Printer::getInstance()->display();
}
void SinglotonDemo()
{
    thread first1(print);
    thread first2(print);
    thread first3(print);
    first1.join();
    first2.join();
    first3.join();
}