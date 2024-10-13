#include<bits/stdc++.h>
using namespace std;

//Brief Overview of the code
/*
In this Project I have created encryption , decryption code with the 
help of fibonacci series and XOR operation. 
In this we give an input string and the keysize for the fibonacci series.
Here, each character of the string has some ASCII value which is converted to 
binary first and then Xored with the fibonacci numbers to generated another 
ASCII number which is then converted to the alphabet and process continues for other character.

HERE WE HAVE FINISHED THE ENCRYPTION 

For decryption we again do Xor with the newly generated alphabets to get
those original alphabets 


*/

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

vector<int> solve1(int n) {
    vector<int> fib;

    for (int i = 0; i < n; i++) {
        fib.push_back(fibonacci(i));
    }

    return fib;
}

string solve2(string& message, vector<int>& key) {
    string encrypted = message;

    int keySize = key.size();
    
    for (int i = 0; i < message.size(); i++) {
        encrypted[i] = message[i] ^ key[i % keySize]; 
    }
    
    return encrypted;
}


string solve3(string& ans, vector<int>& key) {
    return solve2(ans, key);
}

int main() {
    string message;
    cout << "Enter the message: ";
    getline(cin, message);

    int keySize;
    cout << "Enter the keySize of Fibonnacci series: ";
    cin >> keySize;

    vector<int> fibonacciKey = solve1(keySize);

    string ans = solve2(message, fibonacciKey);

    cout << "Encrypted message: " << ans << endl;

    string ans2 = solve3(ans, fibonacciKey);

    cout << "Decrypted message: " << ans2 << endl;

    return 0;
}