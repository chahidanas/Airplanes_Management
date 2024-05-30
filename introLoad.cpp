#include "introLoad.h"

using namespace std;

void setColor(const int color) {
    switch (color) {
        case 33:
            cout << "\033[1;33m";
            break;
        case 36:
            cout << "\033[1;36m";
            break;
        case 40:
            cout << "\033[40m";
            break;
        case 102:
            cout << "\x1B[102m";
            break;
        case 0:
            cout << "\033[0m";
            break;
        default:
            break;
    }
}

void introLoad() {
    constexpr int bar1 = 219;
    constexpr int bar2 = 273;
    constexpr int
            barSZ = 25;

    system("cls");
    setColor(36);
    cout << "\t\t\tPROJECT BY:\t";
    constexpr char name[] = "***** Chahid Anas 3IIR5 *****";
    for (int i = 0; name[i] != '\0'; i++) {
        cout << name[i];
        Sleep(100);
    }
    setColor(33);
    cout << "\n\t\t\t\t\tLoading ... " << endl;
    cout << "\n\t\t\t\t";
    for (int i = 1; i <= barSZ; i++) {
        cout << static_cast<char>(bar2);
    }
    cout << "\r";
    cout << "\t\t\t\t";
    for (int i = 1; i <= barSZ; i++) {
        cout << static_cast<char>(bar1);
        Sleep(100);
    }
    system("cls");
    setColor(36);
    cout << "\t\t\tPROJECT BY:\t";
    for (int i = 0; name[i] != '\0'; i++) {
        cout << name[i];
    }
    setColor(33);
    cout << "\n\t\t\t\t\t Loaded" << endl;
    cout << "\n\t\t\t\t";
    for (int i = 1; i <= barSZ; i++) {
        cout << static_cast<char>(bar2);
    }
    cout << "\r";
    cout << "\t\t\t\t";
    for (int i = 1; i <= barSZ; i++) {
        cout << static_cast<char>(bar1);
    }
    cout << endl << endl;
    setColor(36);
    cout << "Press any key to continue to the menue" << endl;
    _getch();
    setColor(33);
}
