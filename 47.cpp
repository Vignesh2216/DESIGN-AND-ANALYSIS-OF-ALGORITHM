// You are using GCC
#include <iostream>
#include <string>
using namespace std;

void computeLPSArray(string pat, int M, int lps[]) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = len;
                i++;
            }
        }
    }
}

void KMPSearch(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();
    int lps[M];
    computeLPSArray(pat, M, lps);
    bool found = false;
    int i = 0;
    int j = 0;
    while (i < N )
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
        if (j == M)
        {
            found = true;
            cout << "Found at " << (i - j) << endl;
            j = lps[j - 1];
        }
    }
    if (!found)
        cout << "Not Found" << endl;
}

int main() {
    string txt, pat;
    cin >> txt >> pat;
    KMPSearch(pat, txt);
    return 0;
}