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

string transpositionEncrypt(string &text ,string &key) {

    int i,j;
    int cols = key.length();
    int rows = (text.length() / cols) + ((text.length()%cols) !=0);

    char arr[rows][cols];
    map<char,int> keyMap;

    ///save key
    for(i=0;i<cols;i++) {
        keyMap[key[i]] = i;
    }

    ///put on array
    int index=0;
    char c = 'a';
    for(i=0;i<rows;i++) {
        for(j=0;j<cols;) {
            if(text[index] == '\0') {
                arr[i][j]=c;
                c++;
                j++;
            } else if (isalpha(text[index]) || text[index]==' ') {
                arr[i][j]=text[index];
                j++;
            }
            index++;
        }
    }
    ////now get cyper message
    string result ="";

    for(auto it=keyMap.begin();it!=keyMap.end();it++) {
        j = it->second;
        for(i=0;i<rows;i++) {
            result +=arr[i][j];
        }
    }

    return result;
}

string transpositionDecrypt(string &text ,string &key) {

    int i,j;
    int cols = key.length();
    int rows = text.length() / cols;

    if((text.length()%cols) !=0) {
        cout << "worng on cyper text \n "
                "because the text and key have reminder (c.t % k) !=0\n"
                "check your key and yor cyper text again";
        return "";
    }

    char arr[rows][cols];
    map<char,int> keyMap;

    ///save key
    for(i=0;i<cols;i++) {
        keyMap[key[i]] = i;
    }

    ///put on array
    int index=0;
    for(auto it=keyMap.begin();it!=keyMap.end();it++) {
        j = it->second;
        for(i=0;i<rows;i++) {
            arr[i][j] = text[index];
            index++;
        }
    }

    ////now get plain message
    string result ="";
    for(i=0;i<rows;i++) {
        for(j=0;j<cols;j++) {
            result+=arr[i][j];
        }
    }


    return result;
}

void solveit() {
    string plainText, cypertext, c, x;
    string key;
    cout<<"key must don't have repete chars\n\n";
    ////////////////simple interface///////////////////////
    while (true) {
        cout << "<1> (cypertext to plaintext).\n<2> (plaintext to cypertext).\nEnter( 1 or 2):";
        cin >> c;
        if (c.length() == 1 && c[0] - '0' == 1) {
            cin.ignore ();
            cout << "enter cypertext :"; getline(cin, cypertext);
            cout << "enter Key :"; cin >> key;
            cout << "plain-text is :" << transpositionDecrypt(cypertext,key) << "\n";
        } else if (c.length() == 1 && c[0] - '0' == 2) {
            cin.ignore ();
            cout << "enter plainText :"; getline(cin, plainText);
            cout << "enter Key :"; cin >> key;
            cout << "cyper-text is :" << transpositionEncrypt(plainText, key ) << "\n";
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