#include <iostream>
#include <string>
 
int main() {
    int numberOfTestCases;
    std::cin >> numberOfTestCases;
 
    while (numberOfTestCases--) {
        int casseroleLength, initialPieces, finalPieces;
        std::cin >> casseroleLength >> initialPieces >> finalPieces;
 
        std::string monkActions;
        std::cin >> monkActions;
 
        int currentPieceIndex = initialPieces - 1;
        int wastedPieces = 0, failedOperations = 0;
 
        for (char action : monkActions) {
            if (action == 'L') {
                currentPieceIndex = initialPieces;  
            } else if (action == 'W') {
                if (currentPieceIndex <= 0) {
                    wastedPieces++;
                }
            } else { 
                if (currentPieceIndex <= 0) {
                    failedOperations++;
                }
            }
            currentPieceIndex--;
        }
 
        if (wastedPieces > finalPieces) {
            failedOperations++;
        }
 
        std::cout << (failedOperations != 0 ? "NO" : "YES") << std::endl;
    }
 
    return 0;
}
