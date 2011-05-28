#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;

class CubeStickers
{
public:
    string isPossible(vector <string> sticker);
};

map<string,int> num_stickers;

string CubeStickers::isPossible(vector <string> sticker)
{
    vector<string>::iterator it;

    for( it=sticker.begin(); it != sticker.end(); ++it )
    {
        
        if( num_stickers.count(*it) > 0 )
        {
            if( num_stickers[*it] < 2 )
            {
                num_stickers[*it] ++;
            }
        }
        else
        {
            pair<string,int> p(*it,1);
            num_stickers.insert(p);
        }
    }

    map<string,int>::iterator mit;
    int possible_sticker_num = 0;

    for( mit=num_stickers.begin(); mit!=num_stickers.end(); ++mit )
    {
        possible_sticker_num += mit->second;
    }
    
    return possible_sticker_num >= 6 ? "YES":"NO";
}

#if 1
int main(void)
{
    CubeStickers c;
    vector<string> v;

    v.push_back("aaaa");
    v.push_back("red");
    v.push_back("red");
    v.push_back("b");
    v.push_back("b");
    v.push_back("b");
    v.push_back("c");
    v.push_back("d");
    v.push_back("e");
    v.push_back("f");
    v.push_back("g");
    
    cout << c.isPossible(v) << endl;
}
#endif
