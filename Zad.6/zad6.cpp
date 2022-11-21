#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class LK {
public:
    void wczytaj();
    void dodawanie(int a1, int a2, char lk);
private:
    vector<char> LK; vector<int> K1; vector<int> K2;
};

void mvBr(vector<char>& br, string zi, int mv) {
    mv++;
    char* brTem = new char[4];
    for (int i = 0; i < 4; i++)
        brTem[i] = br[i];
    for (int i = mv; i < 4; i++) {
        br[i - mv] = brTem[i];
    }
    delete[] brTem;
    for (int i = 0; i < mv; i++)
        br.pop_back();
    for (int i = 0; i < zi.size(); i++) {
        br.push_back(zi[i]);
    }
}

void dodSk(char*& sk, string zi, int mv) {
    char* brTem = new char[4];
    for (int i = 0; i < 4; i++)
        brTem[i] = sk[i];
    int temp = 3 - mv; int j = 3;
    if (mv < 4) {
        for (int i = 3; i >= mv; i--) {
            sk[temp] = brTem[j]; j--;
            temp--;
        }
    }
    temp = 0;
    for (int i = 3 - (zi.size() - 1); i < 4; i++) {
        sk[i] = zi[temp]; temp++;
    }
}


string seaPs(vector<char> br, char* sk, int& is) {
    is = 0;
    int ps_is = is; int flIu = 0;
    string ps = ""; string psTp = "";

    if (br.size() == 4) {
        for (int i = 0; i < 4; i++) {
            if (sk[i] == ' ') {
                continue;
            }
            else if (br[ps_is] != sk[i]) {
                ps_is = 0; flIu = 0;
                for (int i = 0; i < psTp.size(); i++) {
                    if (psTp.empty() != 1) {
                        psTp.pop_back();
                    }
                }
            }
            else if (br[ps_is] == sk[i]) {
                ps_is++;
                psTp.push_back(sk[i]);
                if (ps.size() <= psTp.size()) {
                    if (flIu == 0) {
                        is = i; flIu = 1;
                    }
                    ps = psTp;
                }
            }
        }
    }
    if (ps.empty() == 1) {
        is = 0;
    }
    return ps;
}

int main() {
    string ts;
    char* sk = new char[4]; char a = 'z';
    for (int i = 0; i < 4; i++) sk[i] = ' ';
    vector<char> br; queue<char> sl;

    cout << "Podaj ciag znakow do zakodowania: " << endl;
    cin >> ts;

    for (int i = 0; i < ts.size(); i++)
        sl.push(ts[i]);
    for (int i = 0; i < 4; i++) {
        br.push_back(sl.front()); sl.pop();
    }
    LK kd; char LK;
    string pLy = ""; string BrtoSl = "";
    kd.dodawanie(0, 0, br[0]);
    pLy.push_back(sl.front()); sl.pop();

    for (int i = 0; i < pLy.size(); i++) BrtoSl.push_back(br[i]);
    mvBr(br, pLy, 0); pLy = "";
    dodSk(sk, BrtoSl, BrtoSl.size());

    int is = 0;

    while (sl.empty() != 1) {
        is = 0;
        BrtoSl = seaPs(br, sk, is);
        LK = br[BrtoSl.size()];
        kd.dodawanie(is, BrtoSl.size(), LK);
        BrtoSl.push_back(br[BrtoSl.size()]);
        dodSk(sk, BrtoSl, BrtoSl.size());
        pLy = "";

        if (sl.empty() != 1) {
            for (int i = 0; i < BrtoSl.size(); i++) {
                if (sl.size() != 0) {
                    pLy.push_back(sl.front()); sl.pop();
                }
                else {
                    break;
                }
            }
            mvBr(br, pLy, pLy.size() - 1);
        }
    }
    is = 0;
    BrtoSl = seaPs(br, sk, is);
    LK = br[BrtoSl.size()];
    kd.dodawanie(is, BrtoSl.size(), LK);
    BrtoSl.push_back(br[BrtoSl.size()]);
    dodSk(sk, BrtoSl, BrtoSl.size());

    string lBr = "";
    if (sl.empty() == 1) {
        for (int i = BrtoSl.size(); i < 4; i++)
            lBr.push_back(br[i]);
        for (int i = 0; i < 4; i++)
            br.pop_back();
        for (int i = 0; i < lBr.size(); i++)
            br.push_back(lBr[i]);
    }

    is = 0;
    for (int i = 0; i < 4; i++) {
        int fa = br.size();
        if (sk[i] == br[is]) {
            lBr.push_back(br[is]); is++;

            if (is == fa) {
                kd.dodawanie(i, lBr.size() - 1, '_');
                break;
            }

        }
        else {
            lBr = "";
        }
    }
    kd.wczytaj(); string ps = "";
    return 0;
}

void LK::wczytaj() {
    cout << endl;
    cout << "Ciag kodujacy:";
    cout << endl;
    for (int i = 0; i < K1.size(); i++) {
        cout << "(" << this->K1[i] << "," << this->K2[i] << "," << this->LK[i] << "), ";
    }
    cout << endl;
}

void LK::dodawanie(int a1, int a2, char lk) {
    this->K1.push_back(a1); this->K2.push_back(a2); this->LK.push_back(lk);
}
