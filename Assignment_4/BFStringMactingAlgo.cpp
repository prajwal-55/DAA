#include<bits/stdc++.h>
using namespace std;

int BF(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
            j++;
        if (j == m)
            return i;
    }
    return -1;
}

int main() {
    string text = "The quick brown fox jumps over the lazy dog";
    string pattern = "the";
    int position = BF(text, pattern);
    if (position == -1)
        cout << "Pattern not found" << endl;
    else
        cout << "Pattern found at position: " << position << endl;
    return 0;
}