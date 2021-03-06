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


class Solution {

public:
    void SOL_01() {
        int n, a, b; 
        cin >> n >> a >> b; 
        vector<int> arr(n + 1, 2);

        int temp;
        for (int i = 0; i < a; i++) {
            cin >> temp;
            arr[temp] = 1;
        }
        for (int i = 0; i < b; i++)
            cin >> temp;
        
        for (int i = 1; i <= n; i++)
            cout << arr[i] << " ";

        
        cout << endl;
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
