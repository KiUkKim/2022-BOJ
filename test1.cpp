#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector< float > v;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        float f;
        cin >> f;
        v.push_back(f);
    }

    long long i = 1;
    while( 1 ){
        bool b = true;
        for(int j = 0; j < n; j++){
            // 지금 i가 v[j]에 대해 답이 되는 지 확인
            
            
            // ex) 0.125 * 8 = 1과 같이 딱 떨어지는 경우 답이 되므로 패스
            if( (int)(v[j] * i * 1000) % 1000 == 0 ) continue;

            // ( (v[j]*i의 정수값) / i )의 소수점 3자리 까지와 v[j]가 같을 경우 답이 됨
            // 아닐 경우 b = false
            int t = ceil(v[j] * i);
            int f = ( (float)t / (float)i ) * 1000;
            if( f != v[j]*1000 ){
                b = false;
                break;
            }
        }
        
        // 만약 모든 v[j]에 대해 통과했다면 답
        if( b ) break;
        i++;
    }

    cout << i << endl;
}
