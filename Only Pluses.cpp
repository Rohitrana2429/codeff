#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        // Maximum number of increments allowed
        int max_increments = 5;

        // Function to find the maximum product
        auto maxProduct = [&](int a, int b, int c, int increments) {
            int max_product = a * b * c;
            for (int i = 0; i <= increments; ++i) {
                for (int j = 0; j <= increments - i; ++j) {
                    int k = increments - i - j;
                    int current_product = (a + i) * (b + j) * (c + k);
                    max_product = max(max_product, current_product);
                }
            }
            return max_product;
        };

        int result = maxProduct(a, b, c, max_increments);
        cout << result << endl;
    }
    return 0;
}
