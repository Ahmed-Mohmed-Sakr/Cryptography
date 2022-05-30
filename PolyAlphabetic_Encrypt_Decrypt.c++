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


char EncryptDecrypt(char tChar , int key) {

    if (islower(tChar)) {
        tChar = char(((tChar + key - 97) % 26) + 97);
    } else {
        tChar = char(((tChar + key - 65) % 26) + 65);
    }

    return tChar;
}

string PolyAlphabeticEncrypt(string &text , string &key) {

    string result = "";
    int keylen = key.length();
    int count = 0;
    int textlen = text.length();
cout<<"\n";
    for (int i = 0; i < textlen; i++) {
        count = (count % keylen);

        if (isalpha(text[i])) {
            if (islower(key[count])) {
                result += EncryptDecrypt(text[i], (key[count] - 'a'));
            } else {
                cout<<count<<"   "<<key[count]<<"    "<<(key[count] - 'A')<<"\n";
                result += EncryptDecrypt(text[i], (key[count] - 'A'));
            }
            count++;
        }
    }
    return result;
}

string PolyAlphabeticDecrypt(string &text , string &key) {

    string result = "";
    int keylen = key.length(), count = 0;
    int textlen = text.length();

    for (int i = 0; i < textlen; i++) {
        count = (count % keylen);

        if (islower(key[count])) {
            result += EncryptDecrypt(text[i], 26 - ((key[count] - 'a')));
        } else {
            result += EncryptDecrypt(text[i], 26 - ((key[count] - 'A')));
        }
        count++;
    }
    return result;
}



void solveit() {
    string plainText, cypertext, c, x;
    string key;

    ////////////////simple interface///////////////////////
    while (true) {
        cout << "<1> (cypertext to plaintext).\n<2> (plaintext to cypertext).\nEnter( 1 or 2):";
        cin >> c;
        if (c.length() == 1 && c[0] - '0' == 1) {
            cin.ignore ();
            cout << "enter cypertext :"; getline(cin, cypertext);
            cout << "enter Key :"; cin >> key;
            cout << "plain-text is :" << PolyAlphabeticDecrypt(cypertext,key) << "\n";
        } else if (c.length() == 1 && c[0] - '0' == 2) {
            cin.ignore ();
            cout << "enter plainText :"; getline(cin, plainText);
            cout << "enter Key :"; cin >> key;
            cout << "cyper-text is :" << PolyAlphabeticEncrypt(plainText,key) << "\n";
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