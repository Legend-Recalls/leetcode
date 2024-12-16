#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1){
            return 1;
        }
        int prev0 = 1;
        int prev1 = 1;

        for(int i = 2; i <= n;i++){
            int current = prev0 + prev1;
            prev0 = prev1;
            prev1 = current;
        }

        return prev1;

    }
};

int main(){
    Solution solution;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = solution.climbStairs(n);
    cout << result;
}