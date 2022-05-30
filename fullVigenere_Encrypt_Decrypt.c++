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

/**
 * full vigenere
 * that algorithm work on the basic (26*26) matrix
 * using to methods shown blow on implemintation
 * these methods work exactly like way that we use in matrix analysis
 */



string fullVigenereEncryption(string &text ,string &key) {

    int c=0;
    string result="";
    int keylen=key.length();
    int textlen =text.size();

    for(int i=0;i<textlen;i++) {
        c=(c%keylen);
        if(isalpha(text[i])) {

            if(isupper(text[i])) text[i]+=32;
            if(isupper(key[c])) text[c]+=32;

            result += (char)((((text[i]-'a')+(key[c]-'a'))%26)+'a');

            c++;
        }
    }
    return result;

}

string fullVigenereDecryption(string &text ,string &key) {

    int c=0;
    string result="";
    int keylen=key.length();
    int textlen =text.size();

    for(int i=0;i<textlen;i++) {
        c=(c%keylen);
        if(isalpha(text[i])) {

            if(isupper(text[i])) text[i]+=32;
            if(isupper(key[c])) text[c]+=32;

            result += (char)((((text[i]-'a')-(key[c]-'a') + 26)%26)+'a');

            c++;
        }
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
            cout << "plain-text is :" << fullVigenereDecryption(cypertext,key) << "\n";
        } else if (c.length() == 1 && c[0] - '0' == 2) {
            cin.ignore ();
            cout << "enter plainText :"; getline(cin, plainText);
            cout << "enter Key :"; cin >> key;
            cout << "cyper-text is :" << fullVigenereEncryption(plainText,key) << "\n";
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