#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int dp[10000] = {0, };

int wine(int n, int S[]){
    dp[0] = S[0];
    dp[1] = S[0]+S[1];
    dp[2] = max({S[0]+S[1],S[0]+S[2],S[1]+S[2]});
    
    for(int i = 3; i<n; i++){
        dp[i] = max({S[i]+S[i-1]+dp[i-3], S[i]+dp[i-2],dp[i-1]});
    }
    return dp[n-1];
}

int main(){
    fastio;

    int n;
    int result;
        
    cout << "입력:";
    cin >> n;

    int S[10000] = {0, };
    for(int i = 0 ; i < n; i++){
        cin >> S[i];
    }
    
    result = wine(n, S);
    
    cout << result << '\n';
}
