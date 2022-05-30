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

char matrix[5][5];
map<char,pair<int,int>>matrixToQuiclyAcss;

void getMatrixReady() {

    char c='a';

    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            if(c=='q') {
                matrix[i][j]=c;
                matrixToQuiclyAcss[c] = {i, j};
                matrixToQuiclyAcss['z'] = {i, j};
            }else {
                matrix[i][j]=c;
                matrixToQuiclyAcss[c] = {i, j};
            }
            c++;
        }
    }
}

string CompositionEncrypt(string &text) {

    int textlen = text.length();
    vector<int> arr;

    for(int i=0;i<textlen;i++) {
        if(isalpha(text[i])) {

            if(isupper(text[i]))
                text[i]+=32;

            arr.push_back(matrixToQuiclyAcss[text[i]].first);
            arr.push_back(matrixToQuiclyAcss[text[i]].second);
        }
    }

    string result="";

    int arrlen = arr.size()/2;
    for(int i=0;i<arrlen;i++) {
        result+= matrix[arr[i]][arr[i+arrlen]];
    }

    return result;

}

string CompositionDecrypt(string &text) {

    int textlen = text.length();
    vector<int> arr(textlen*2+5);

    for(int i=0;i<textlen;i++) {
        if (isupper(text[i]))
            text[i] += 32;

        arr[i] = matrixToQuiclyAcss[text[i]].first;
        arr[i + textlen] = matrixToQuiclyAcss[text[i]].second;

    }

    string result="";

    int arrlen = textlen*2;
    for(int i=0;i<arrlen;i+=2) {
        result+= matrix[arr[i]][arr[i+1]];
    }

    return result;

}

void solveit() {

    getMatrixReady();

    string plainText, cypertext, c, x;
    string key;

    ////////////////simple interface///////////////////////
    while (true) {
        cout << "<1> (cypertext to plaintext).\n<2> (plaintext to cypertext).\nEnter( 1 or 2):";
        cin >> c;
        if (c.length() == 1 && c[0] - '0' == 1) {
            cin.ignore ();
            cout << "enter cypertext :"; getline(cin, cypertext);
            ////cout << "enter Key :"; cin >> key;
            cout << "plain-text is :" << CompositionDecrypt(cypertext) << "\n";
        } else if (c.length() == 1 && c[0] - '0' == 2) {
            cin.ignore ();
            cout << "enter plainText :"; getline(cin, plainText);
            ////cout << "enter Key :"; cin >> key;
            cout << "cyper-text is :" << CompositionEncrypt(plainText) << "\n";
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
