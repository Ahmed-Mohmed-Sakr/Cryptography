#include<bits/stdc++.h>
#define Sakr_ ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0);
#define ll  long long
using namespace std;
/**
 * by:Ahmed Sakr (sakr_) with AZA ;
 * freopen("input.txt","r",stdin);
 * freopen("output.txt","w",stdout);
 * __builtin_popcountll();
**/


string ceaserEncryptDecrypt(string &plainText , int key) {
    string result = "";

    int i, n = plainText.length();
    for (i = 0; i < n; i++) {
        if(isalpha(plainText[i])) {
            if (islower(plainText[i])) {
                result += char((plainText[i] + key - 97) % 26 + 97);
            } else {
                result += char((plainText[i] + key - 65) % 26 + 65);
            }
        }
    }

    return result;
}

void solveit() {
    string plainText, cypertext, c, x;
    int key;

    ////////////////simple interface///////////////////////
    while (true) {
        cout << "<1> (cypertext to plaintext).\n<2> (plaintext to cypertext).\nEnter( 1 or 2):";
        cin >> c;
        if (c.length() == 1 && c[0] - '0' == 1) {
            cin.ignore ();
            cout << "enter cypertext :"; getline(cin, cypertext);
            cout << "enter Key :"; cin >> key;
            cout << "plain-text is :" << ceaserEncryptDecrypt(cypertext, 26 - (key % 26)) << "\n";
        } else if (c.length() == 1 && c[0] - '0' == 2) {
            cin.ignore ();
            cout << "enter plainText :"; getline(cin, plainText);
            cout << "enter Key :"; cin >> key;
            cout << "cyper-text is :" << ceaserEncryptDecrypt(plainText, (key % 26)) << "\n";
        } else {
            cout << "wrong - choose one or two only\n";
        }
        cout << "To continue enter (1) :";
        cin >> x;
        ///system("clear");
        if (!(x.length() == 1 && x[0] - '0' == 1)) break;
    }
    ////////////////////////////////////////////////////////
}

int main() {
    ///Sakr_

    int t = 1;
    ////cin>>t;
    while (t--) {
        solveit();
    }
}