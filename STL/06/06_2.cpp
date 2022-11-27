#include <iostream>
#include <queue>

using namespace std;

class Proces {
public:
    Proces(int, int);
    int getId() const {return id;}
    int getPrioritet() const {return prioritet;}
private:
    int id;
    int prioritet;
};

Proces::Proces(int id, int prioritet)
{
    this->id = id;
    this->prioritet = prioritet;
}

// overloading na operatorot < za da moze 
// prioritetniot red da pravi sporedba na klasa Proces
bool operator<(const Proces &p1, const Proces &p2)
{
    return p1.getPrioritet() < p2.getPrioritet();
}


int main()
{
    priority_queue<Proces> priority;

    priority.push(Proces(1, 50));
    priority.push(Proces(2, 30));
    priority.push(Proces(3, 100));
    priority.push(Proces(4, 5));
    priority.push(Proces(5, 400));

    while(!priority.empty())
    {
        Proces p = priority.top();
        cout << "Process id: " << p.getId() <<
             "\tProcess priority: " << p.getPrioritet()
             << endl;
        priority.pop(); 
    }

    return 0;
}