#include <iostream>
#include <string>
using namespace std;

int superDigit_better(string n, int k) {
    long long sum = 0;
    for(char digit : n)
    {
        sum += digit - '0';
    }
    sum *= k;

    while (sum > 9)
    {
        long long newSum = 0;
        while (sum > 0)
        {
            newSum += sum % 10;
            sum /= 10;
        }
        sum = newSum;
    }
    
    cout << sum;
    return static_cast<int>(sum);
   
}

int superDigit(string number)
{
    if (number.length() == 1)
    {
        return stoi(number);
    }

    int sum = 0;
    for (char digit : number)
    {
        sum += digit - '0';
    }

    return superDigit(to_string(sum));

 /* if (number < 10)
    {
        return number;
    }

    int remainder = number % 10;
    number = number / 10;
    int Snumber = remainder + superDigit(number);
    return superDigit(Snumber); */

}

int main()
{
    string n, p;
    int k;
    cin >> n >> k;
    for(int i=0; i < k; i++)
    {
        p = p + n;
    }
    // int ip = stoi(p);
    cout << superDigit(p);
}