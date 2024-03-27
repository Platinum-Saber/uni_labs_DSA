#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int countWays(int X, int N, int currentNum) {
    if (X == 0) {
        return 1; // Found a combination
    }

    int ways = 0;
    for (int i = currentNum + 1; pow(i, N) <= X; i++) {
        ways += countWays(X - pow(i, N), N, i);
    }

    return ways;
}

int main() {
    int X, N;
    cout << "Enter the value of X: ";
    cin >> X;

    cout << "Enter the value of N: ";
    cin >> N;

    int ways = countWays(X, N, 0);

    cout << "Number of ways to express " << X << " as the sum of unique " << N << "-th powers: " << ways << endl;

    return 0;
}
