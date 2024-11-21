#include <iostream>
#include <windows.h>
#include <vector>
#include <map>
#include <ctime>
#include <set>

using namespace std;

class base {
protected:
    map <string, int> NaP; /// Name and Points
    char arena[15][20];
    vector <int> XHead;
    vector <int> YHead;
    int SL = 1; /// Snake Length
    string name;
    char ST; /// Snake Type
public:
    base() {
        for (int i = 0; i < 20; i++) arena[0][i] = '#';
        for (int i = 1; i < 14; i++) {
            for (int j = 0; j < 20; j++) {
                if (j == 0 || j + 1 == 20) arena[i][j] = '#';
                else arena[i][j] = ' ';
            }
        }
        for (int i = 0; i < 20; i++) arena[14][i] = '#';
        XHead.push_back(5);
        YHead.push_back(5);
    }
    ~base() {
        XHead.clear();
        YHead.clear();
        NaP.clear();
    }
    void operator =(string vardas) { /// Name entry
        name = vardas;
        NaP[name] = 0;
    }
    void GS() { /// Game start
        cout << "The game will start in :" << endl;
        Sleep(500);
        cout << 1 << endl;
        Sleep(500);
        cout << 2 << endl;
        Sleep(500);
        cout << 3 << endl;
        Sleep(500);
        system("cls");
        Sleep(250);
    }

    void printing() {
        system("cls");
        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 20; j++) cout << arena[i][j];
            cout << endl;
        }
        NaP[name] = (SL - 1) * 10;
        for (auto i : NaP) {
            if (i.first == name) cout << "Points : " << i.second << endl;
        }
        Sleep(250);
    }

    void setST(char symbol) {
        ST = symbol;
        arena[*XHead.begin()][*YHead.begin()] = ST;
    }

    char getST() {
        return ST;
    }
};

class game : public base {
private:
    char D; /// direction
    int DP = 0; /// direction point
    vector <pair<int, int>> food_place; /// places for food
    int rr = 0; /// random number
public:
    ~game() {
        food_place.clear();
    }
    void key_entry() {
        if (GetAsyncKeyState(VK_DOWN)) {
            D = 'D';
            DP = 1;
        }
        if (GetAsyncKeyState(VK_UP)) {
            D = 'U';
            DP = -1;
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
            D = 'R';
            DP = 1;
        }
        if (GetAsyncKeyState(VK_LEFT)) {
            D = 'L';
            DP = -1;
        }
    }
    void game_running() {
        if (SL == 1) {
            key_entry();
            if (D == 'D' || D == 'U') {
                if (arena[*XHead.begin() + DP][*YHead.begin()] == ' ') {
                    arena[*XHead.begin()][*YHead.begin()] = ' ';
                    *XHead.begin() += DP;
                    arena[*XHead.begin()][*YHead.begin()] = ST;
                }
                else if (arena[*XHead.begin() + DP][*YHead.begin()] == 'x') {
                    SL++;
                    XHead.insert(XHead.begin(), *XHead.begin() + DP);
                    YHead.insert(YHead.begin(), *YHead.begin());
                    for (int i = 0; i < SL; i++) arena[XHead[i]][YHead[i]] = ST;
                    randomiser();
                }
                else rr = -1;
            }
            if (D == 'R' || D == 'L') {
                if (arena[*XHead.begin()][*YHead.begin() + DP] == ' ') {
                    arena[*XHead.begin()][*YHead.begin()] = ' ';
                    *YHead.begin() += DP;
                    arena[*XHead.begin()][*YHead.begin()] = ST;
                }
                else if (arena[*XHead.begin()][*YHead.begin() + DP] == 'x') {
                    SL++;
                    XHead.insert(XHead.begin(), *XHead.begin());
                    YHead.insert(YHead.begin(), *YHead.begin() + DP);
                    for (int i = 0; i < SL; i++) arena[XHead[i]][YHead[i]] = ST;
                    randomiser();
                }
                else rr = -1;
            }
            printing();
        }
        else {
            key_entry();
            if (D == 'D' || D == 'U') {
                if (arena[*XHead.begin() + DP][*YHead.begin()] == ' ') {
                    XHead.insert(XHead.begin(), *XHead.begin() + DP);
                    YHead.insert(YHead.begin(), *YHead.begin());
                    arena[XHead.back()][YHead.back()] = ' ';
                    XHead.pop_back();
                    YHead.pop_back();
                }
                else if (arena[*XHead.begin() + DP][*YHead.begin()] == 'x') {
                    XHead.insert(XHead.begin(), *XHead.begin() + DP);
                    YHead.insert(YHead.begin(), *YHead.begin());
                    SL++;
                    randomiser();
                }
                else rr = -1;
                for (int i = 0; i < SL; i++) arena[XHead[i]][YHead[i]] = ST;
            }
            if (D == 'R' || D == 'L') {
                if (arena[*XHead.begin()][*YHead.begin() + DP] == ' ') {
                    XHead.insert(XHead.begin(), *XHead.begin());
                    YHead.insert(YHead.begin(), *YHead.begin() + DP);
                    arena[XHead.back()][YHead.back()] = ' ';
                    XHead.pop_back();
                    YHead.pop_back();
                }
                else if (arena[*XHead.begin()][*YHead.begin() + DP] == 'x') {
                    XHead.insert(XHead.begin(), *XHead.begin());
                    YHead.insert(YHead.begin(), *YHead.begin() + DP);
                    SL++;
                    randomiser();
                }
                else rr = -1;
                for (int i = 0; i < SL; i++) arena[XHead[i]][YHead[i]] = ST;
            }
            printing();
        }
    }
    void randomiser() {
        srand(time(NULL));
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 20; j++) {
                if (arena[i][j] == ' ') {
                    food_place.push_back(make_pair(i, j));
                }
            }
        }
        if (!food_place.empty()) {
            rr = rand() % food_place.size();
            arena[food_place[rr].first][food_place[rr].second] = 'x';
        }
        food_place.clear();
    }

    bool game_status_check() {
        try {
            if (rr == -1) throw 1;
            else return 0;
        }
        catch (int error) {
            cout << "GAME OVER!" << endl;
            for (auto i : NaP) if (i.first == name) cout << "Your result : " << i.second << endl;
            return 1;
        }
    }
};

class snake : public base {
private:
    set<char> SS; /// snake symbols
    string* rodykle;
    int z = 0;
    bool r = 1;
public:
    snake() {
        SS.insert('o');
        SS.insert('z');
        SS.insert('v');
        SS.insert('m');
        SS.insert('c');
        SS.insert('b');
        rodykle = new string[SS.size()];
        fill(rodykle, rodykle + SS.size(), "  ");
        rodykle[0] = "->";
    }
    ~snake() {
        SS.clear();
    }
    void snake_options() {
        z = 0;
        system("cls");
        cout << "Please choose the symbols that your snake will be made out of" << endl;
        cout << "(Use UP and DOWN arrows. Once you've selected, press SPACE)" << endl;
        for (auto i : SS) {
            cout << rodykle[z] << " " << i << i << i << i << i << endl;
            z++;
        }
        Sleep(500);
        snake_submission();
    }
    void snake_submission() {
        while (r == 1) {
            if (GetAsyncKeyState(VK_SPACE)) {
                for (int i = 0; i < SS.size(); i++) {
                    if (rodykle[i] == "->") {
                        auto it = SS.begin();
                        advance(it, i);
                        ST = *it;
                        setST(ST);
                        r = 0;
                        break;
                    }
                }
                break;
            }
            if (GetAsyncKeyState(VK_DOWN)) {
                for (int i = 0; i < SS.size(); i++) {
                    if (rodykle[i] == "->") {
                        if (i + 1 == SS.size()) swap(rodykle[i], rodykle[0]);
                        else swap(rodykle[i], rodykle[i + 1]);
                        snake_options();
                        break;
                    }
                }
            }
            if (GetAsyncKeyState(VK_UP)) {
                for (int i = 0; i < SS.size(); i++) {
                    if (rodykle[i] == "->") {
                        if (i - 1 == -1) swap(rodykle[0], rodykle[SS.size() - 1]);
                        else swap(rodykle[i], rodykle[i - 1]);
                        snake_options();
                        break;
                    }
                }
            }
        }
    }
};

void start_game(base& b) {
    game g;
    g.setST(b.getST());
    g.randomiser();
    while (g.game_status_check() == 0) g.game_running();
}

int main() {
    string vardas;
    base b;
    snake s;
    cout << "GAME : 'SNAKE'" << endl;
    cout << "Please enter your name :" << endl;
    cout << "-> ";
    cin >> vardas;
    b = vardas;
    s.snake_options();
    system("cls");
    b.setST(s.getST());
    b.GS();
    start_game(b);
    return 0;
}
