#include <bits/stdc++.h>

using namespace std;
typedef tuple<int, int, int> point;

class Compare {
public:
    bool operator()(point& a, point& b)
    {
        return get<2>(a) > get<2>(b);
    }
};

int main()
{


}
