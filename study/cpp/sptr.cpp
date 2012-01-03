#include <boost/shared_ptr.hpp>
#include <iostream>

using namespace std;

class Hoge
{
public:
    Hoge(){ cout << "hoge ctr" << endl; }
    ~Hoge(){ cout << "hoge dtr" << endl; }
};


int main()
{
    boost::shared_ptr<Hoge> p(new Hoge);
}
        
    

