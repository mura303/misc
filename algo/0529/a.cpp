#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

//vector<int> test_in = {7,7,3,3,7,7,3,3};

int table[] = {0,1,2,2,1,2,3,2};


class CubeAnts
{
public:
    int getMinimumSteps( vector <int> pos );
};

int CubeAnts::getMinimumSteps( vector<int> pos )
{
    vector<int>::iterator it;
    int r = 0;
    for( it = pos.begin(); it != pos.end(); ++it )
    {
        r = max( r, table[*it] );
    }
    return r;
}

#if 0
int main(void)
{
    CubeAnts c;
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(4);
    v.push_back(6);
    v.push_back(7);
    cout << c.getMinimumSteps(v) << endl;
}
#endif
