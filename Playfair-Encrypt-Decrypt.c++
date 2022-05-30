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

char matrix[6][6];
map<char,pair<int,int>> matrixForQuiclyAcss;

int prepareTOProcess(string &text)
{
    int i;
    int n=text.length();
    int newlen=0;
    for (i = 0; i < n; i++) {
       if(isalpha(text[i])) {
           if(isupper(text[i])) {
               text[i]+=32;
           }
           text[newlen++] = text[i];
       }
    }
    return newlen;
}

void generateMatrix(string &key,int n) {

    set<char> vis;
    int x=0,y=0;

    //// insert key
    for(int i=0;i<n;i++) {

        int prevLen = vis.size();
        vis.insert(key[i]);
        if(prevLen != vis.size()) {
            if(y==5) {
                x++;
                y=0;
            }
            if(key[i]=='i' || key[i]=='j') {
                matrix[x][y]='i';
                matrixForQuiclyAcss['i'] = {x, y};
                vis.insert('i');
                vis.insert('j');
            } else {
                matrix[x][y]=key[i];
                matrixForQuiclyAcss[key[i]]={x, y};
            }
            y++;
        }
    }

    /// complete matricx
    for(char c='a';c<='z';c++){
        int prevLen = vis.size();
        vis.insert(c);
        if(prevLen != vis.size()) {
            if(y==5) {
                x++;
                y=0;
            }
            if(c=='i' || c=='j') {
                matrix[x][y]='i';
                matrixForQuiclyAcss['i'] = {x, y};
                vis.insert('i');
                vis.insert('j');
            } else {
                matrix[x][y]=c;
                matrixForQuiclyAcss[c]={x, y};
            }
            y++;
        }
    }

}

void showTheMatrix(){
    cout<<"\nthe used matrix\n/////////////////\n";
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            cout<<matrix[i][j]<<"  ";
        }
        cout<<"\n";
    }
    cout<<"/////////////////\n";
}

int mod5(int a) { return (a % 5); }

string EncryptThatTwoChars(char a, char b){

    auto posOfA = matrixForQuiclyAcss[a];
    auto posOfB = matrixForQuiclyAcss[b];

    string res ="";

    if (posOfA.first ==posOfB.first) {
        res+= matrix[posOfA.first][mod5(posOfA.second + 1)];
        res+= matrix[posOfA.first][mod5(posOfB.second + 1)];
    }
    else if (posOfA.second ==posOfB.second) {
        res+= matrix[mod5(posOfA.first + 1)][posOfA.second];
        res+= matrix[mod5(posOfB.first + 1)][posOfA.second];
    }
    else {
        res+= matrix[posOfA.first][posOfB.second];
        res+= matrix[posOfB.first][posOfA.second];
    }
    return res;
}

string PlayfairEncrypt(string &text ,string &key) {

    int textLength = prepareTOProcess(text);
    int keyLength = prepareTOProcess(key);

    generateMatrix(key,keyLength);

    /// to not make any outofboundres to be safe always
    text+="zzzzzzz";
    text[textLength]='z';
    text[textLength+1]='z';

    string result = "";

    for(int i=0;i<textLength;) {
        if(text[i]=='x' && text[i+1]=='x'){
            cout<<"we can't cyper that text case occure (xx in text)";
            return "";
        } else if (text[i]==text[i+1]) {
            result+= EncryptThatTwoChars(text[i],'x');
            i++;
        } else {
            result+= EncryptThatTwoChars(text[i],text[i+1]);
            i+=2;
        }
    }

    return result;

}


string DecryptThatTwoChars(char a, char b){

    auto posOfA = matrixForQuiclyAcss[a];
    auto posOfB = matrixForQuiclyAcss[b];

    string res ="";

    if (posOfA.first ==posOfB.first) {
        res+= matrix[posOfA.first][mod5(posOfA.second - 1 +5)];
        res+= matrix[posOfA.first][mod5(posOfB.second - 1 +5)];
    }
    else if (posOfA.second ==posOfB.second) {
        res+= matrix[mod5(posOfA.first - 1 +5)][posOfA.second];
        res+= matrix[mod5(posOfB.first - 1 +5)][posOfA.second];
    }
    else {
        res+= matrix[posOfA.first][posOfB.second];
        res+= matrix[posOfB.first][posOfA.second];
    }
    return res;
}

string PlayfairDecrypt(string &text ,string &key) {

    int textLength = text.length();
    if(textLength%2!=0) {
        cout<<"sorry! we can't decrypt that text case it's not wright \n"
              <<"it must be even number of chars";
    }

    int keyLength = prepareTOProcess(key);
    generateMatrix(key,keyLength);

    string result = "";
    for(int i=0;i<textLength;i+=2) {
        if(text[i]==text[i+1]){
            cout<<"we can't decrypt that text case occure to same letters continuse\n"
                  <<"and for sure that is impossiple to occure in playfair";
            return "";
        }else {
            result+= DecryptThatTwoChars(text[i],text[i+1]);
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
            cout << "enter Key :"; getline(cin, key);
            cout << "plain-text is :" << PlayfairDecrypt(cypertext,key) << "\n";
            showTheMatrix();
        } else if (c.length() == 1 && c[0] - '0' == 2) {
            cin.ignore ();
            cout << "enter plainText :"; getline(cin, plainText);
            cout << "enter Key :"; getline(cin, key);
            cout << "cyper-text is :" << PlayfairEncrypt(plainText,key) << "\n";
            showTheMatrix();
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