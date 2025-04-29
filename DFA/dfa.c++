#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Épít egy DFA-t (állapotátmeneti táblát) a mintára
vector<vector<int>> buildDFA(const string& pattern) {
    int M = pattern.length();
    const int R = 256; // ASCII karakterek száma
    vector<vector<int>> dfa(R, vector<int>(M, 0));

    dfa[pattern[0]][0] = 1; // első karakter

    int X = 0; // visszatérési állapot, ha nem illeszkedik
    for (int j = 1; j < M; ++j) {
        for (int c = 0; c < R; ++c)
            dfa[c][j] = dfa[c][X]; // visszautak
        dfa[pattern[j]][j] = j + 1; // haladás
        X = dfa[pattern[j]][X]; // frissítés
    }
    return dfa;
}

// Minta keresése a szövegben a DFA segítségével
int search(const string& text, const string& pattern) {
    auto dfa = buildDFA(pattern);
    int i, j;
    int N = text.length(), M = pattern.length();
    for (i = 0, j = 0; i < N && j < M; ++i) {
        j = dfa[text[i]][j];
    }
    if (j == M) return i - M; // megtalálta a mintát
    return -1; // nem találta
}

int main() {
    string text = "helloabcworld";
    string pattern = "abc";

    int pos = search(text, pattern);

    if (pos != -1)
        cout << "Minta megtalálva a(z) " << pos << ". pozíciónál.\n";
    else
        cout << "Minta nem található.\n";

    return 0;
}