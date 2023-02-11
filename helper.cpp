#include "includes/leetcode.h"
using namespace std;

void foo()
{
}

class Student {
public:
    void enroll() const
    {
        int a = 9;

        cout << a << endl;
    }

    const int foo()
    {
        return 9;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Student ramesh;
    int a = ramesh.foo();

    cout << a << endl;

    return 0;
}
