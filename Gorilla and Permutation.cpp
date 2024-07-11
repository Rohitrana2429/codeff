#include <iostream>
using namespace std;
 
void generatePermutation() {
    int testCases;
    cin >> testCases;
 
    while (testCases--) {
        int total, segmentSize, dummyVar;
        cin >> total >> segmentSize >> dummyVar;
 
        int sequence[total];
 
        for (int i = 0; i < total - segmentSize; ++i) {
            sequence[i] = total - i;
        }
 
        for (int i = total - segmentSize; i < total; ++i) {
            sequence[i] = i - (total - segmentSize) + 1;
        }
 
        for (int i = 0; i < total; ++i) {
            cout << sequence[i] << " ";
        }
        cout << "\n";
    }
}
 
int main() {
    generatePermutation();
    return 0;
}
