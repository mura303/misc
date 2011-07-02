#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{

    vector<int> numbers;
    
    for( int i=1; i<1000; i++ )
    {
        if( i % 3 == 0 || i % 5 == 0 )
        {
            numbers.push_back(i);
        }
    }
    cout << accumulate(numbers.begin(), numbers.end(), 0 ) << endl;
    
}
