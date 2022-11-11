#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int ab;
void pokaz(vector<string> a){
    for (int i = 0; i < a.size(); i++){
        cout << i + 1 << ". " << a[i] << endl;
    }
}

string ct(char a1){
    string a; a.push_back(a1);
    return a;
}

string cs(string b, char c){
    string a = b; char a1 = 'a'; a += ct(c);
    return a;
}

string cps(char b, char c){
    string a = ct(b); char a1 = 'a'; a += ct(c);
    return a;
}

bool szukanie(vector<string> sl, string a, int& n){
    int i = 0;
    while (i < sl.size()) {
        if (sl[i] == a) {
            n = (i + 1); return true;
        } i++; }
    return false;
}

int main(){
    vector<int> is; char znak;
    string me, sme, tz;
    vector<string> dy;
    cout << "Podaj wiadomosc:\n";
    cin >> me; sme = me;
    sort(sme.begin(), sme.end());
    znak = sme[0];
    tz.push_back(znak); dy.push_back(tz); tz.pop_back();

    cout << "Slownik podstawowy:" << endl;
    for (int i = 1; i < sme.size(); i++){
        if (sme[i] != znak){
            znak = sme[i];
            tz.push_back(znak); dy.push_back(tz); tz.pop_back();
        }
    }

    pokaz(dy); ab = dy.size();
    cout << "-------------------" << endl;

    char b = me[0]; char c;
    string cp = ""; int tis = 0;
    for (int i = 1; i < me.size(); i++){
       c = me[i];
        if (cp == ""){
            if (szukanie(dy, cps(b, c), tis) == true){
                cp = cps(b, c);
            }
            else{
                szukanie(dy, ct(b), tis);
                dy.push_back(cps(b, c)); is.push_back(tis); b = c;
            }
        }
        else {
            if (szukanie(dy, cs(cp, c), tis) == true){
                cp = cs(cp, c);
            }
            else{
                dy.push_back(cs(cp, c)); is.push_back(tis);
                b = c; cp = "";
            }
        }}

    cout << "Slownik pelny:" << endl;
    for (int i = 0; i < dy.size(); i++){
        cout << i + 1 << ". " << dy[i] << endl;
    }
    cout << "------------------" << endl;

    if (cp == ""){
        szukanie(dy, ct(b), tis); is.push_back(tis);
    }
    else{
        szukanie(dy, cp, tis);
    }
    cout << "Zakodowana wiadomosc:" << endl;
    for (int i = 0; i < is.size(); i++){
        cout << is[i] << " ";
    }
}
