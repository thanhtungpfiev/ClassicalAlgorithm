/**********************************************************************
 *
 * author tung.dao tung.dao@lge.com
 *
 * date 10/20/2021
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <bits/stdc++.h>
using namespace std;
const int max_n = 200005, mod = 1000000007;
long long dp[max_n];
int main(){
    for(int i=0; i<9; i++) dp[i] = 2;
    dp[9] = 3;
    for(int i=10; i<max_n; i++){
        dp[i] = (dp[i-9] + dp[i-10])%mod;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n, m;
        scanf("%d%d",&n,&m);
        long long ans = 0;
        while(n > 0){
            int x = n%10;
            ans += ((m + x < 10) ? 1 : dp[m + x - 10]);
            ans %= mod;
            n/=10;
        }
        printf("%lld\n",ans);
    }
}
