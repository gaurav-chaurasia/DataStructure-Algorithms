#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define MAX_CHAR 256
#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin>>x; while(x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second
#define MOD 1000000007

class Solution {

public:
    void SOL_01() {
        int n, sum; cin >> n >> sum;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        int dp[n + 1][sum + 1];

        for (int i = 0, j = 0; j <= sum; j++) dp[i][j] = 0;
        for (int i = 0, j = 0; i <= n; i++) dp[i][j] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = (dp[i][j - arr[i - 1]] + dp[i - 1][j]) % MOD;
                }
                else {
                    dp[i][j] = dp[i - 1][j] % MOD;
                }
            }
        }
        
        cout << dp[n][sum] % MOD << endl;
    }

};

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution* SOL = new Solution();
    
    SOL->SOL_01();
    
    delete SOL;
    return 0;
}
