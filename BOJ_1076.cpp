#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int ll;

int main()
{
    fastio;

    map<string ,int> color; // 저항값 저장
    string resis_color1; // 첫번째 색 입력
    string resis_color2; // 두번째 색 입력
    string resis_color3; // 세번째 색 입력

    color.insert(make_pair("black", 0));
    color.insert(make_pair("brown", 1));
    color.insert(make_pair("red", 2));
    color.insert(make_pair("orange", 3));
    color.insert(make_pair("yellow", 4));
    color.insert(make_pair("green", 5));
    color.insert(make_pair("blue", 6));
    color.insert(make_pair("violet", 7));
    color.insert(make_pair("grey", 8));
    color.insert(make_pair("white", 9));
    
    cin >> resis_color1 >> resis_color2 >> resis_color3;

    ll result;

    result = ( color.find(resis_color1)->second ) *10 +  ( color.find(resis_color2)->second ) ;

    int pow_num = 1;
    for(int i = 0; i < color.find(resis_color3)->second ; i++)
    {
        pow_num *= 10;
    }
    
    result *= pow_num;
    
    cout << result << '\n';

    return 0;
}