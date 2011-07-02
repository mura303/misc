#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string line;
    while( getline(cin,line) )
    {
        stringstream input( line );
        int max_num, min_num, n;

        input >> n;

        max_num = min_num = n;
        
        while( input >> n )
        {
            max_num = max( n, max_num );
            min_num = min( n, min_num );
        }
        cout << "min:" << min_num << ", max:" << max_num << endl;
    }
    
}
