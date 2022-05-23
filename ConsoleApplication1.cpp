#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const char POLYBIUS[5][5] = {
    { 'A', 'B', 'C' , 'D', 'E'},
    { 'F', 'G', 'H' , 'I', 'K'},
    { 'L', 'M', 'N' , 'O', 'P'},
    { 'Q', 'R', 'S' , 'T', 'U'},
    { 'V', 'W', 'X' , 'Y', 'Z'}
};

char encrypt(const char c) {

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
        {
            if (POLYBIUS[i][j] == c)
                return POLYBIUS[(i + 1) % 5][j];
            else if (c == 'J')
                return 'Q';
        }
}

char decrypt(const char c) {

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
        {
            if (POLYBIUS[i][j] == c)
                return POLYBIUS[(i + 4) % 5][j];
        }
}

int main() {
    string h;
    int y;
    int t = 0;
    char c[100];
    M:cout << "Select one of the options (enter 1 or 2):" << endl;
    cout << "1.Encrypt from file" << endl << "2.Decrypt from file" << endl << "3.Encrypt" << endl << "4.Decrypt" << endl << "5.Finish the job" << endl;
    cin >> t;
    ifstream en("encrypt.txt", ios::in | ios::binary);
    ifstream de("decrypt.txt", ios::in | ios::binary);
    switch (t) {
    case(1):

        if (en.is_open())
        {
            while (getline(en, h, '\n'))
            {
                cout << "Word:" << h << endl;

                y = h.length();
                for (int i = 0; i < y - 1; ++i)
                    c[i] = h[i];
                cout << "Encription:";
                for (int i = 0; i < y - 1; ++i)
                    cout << encrypt(c[i]);
                cout << endl;

            }
        }
        en.close();
        cout << endl;
        goto M;
        break;
    case(2):

        if (de.is_open())
        {
            while (getline(de, h, '\n'))
            {
                cout << "Word:" << h << endl;

                y = h.length();
                for (int i = 0; i < y - 1; ++i)
                    c[i] = h[i];
                cout << "Decription:";
                for (int i = 0; i < y - 1; ++i)
                    cout << decrypt(c[i]);
                cout << endl;
            }
        }
        de.close();
        cout << endl;
        goto M;
        break;
    case(3):
        cout << "Enter the Word:";
        cin >> h;
        cout << "Word:" << h << endl;
        y = h.length();
        for (int i = 0; i < y ; ++i)
            c[i] = h[i];
        cout << "Encription:";
        for (int i = 0; i < y ; ++i)
            cout << encrypt(c[i]);
        cout << endl;
        cout << endl;
        goto M;
        break;
    case(4):
        cout << "Enter the Encription:";
        cin >> h;
        cout << "Encription:" << h << endl;
        y = h.length();
        for (int i = 0; i < y ; ++i)
            c[i] = h[i];
        cout << "Decription:";
        for (int i = 0; i < y; ++i)
            cout << decrypt(c[i]);
        cout << endl;
        cout << endl;
        goto M;
        break;
    case(5):
        break;
    }
    return 0;
}

