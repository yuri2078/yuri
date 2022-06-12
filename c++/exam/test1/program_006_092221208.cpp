#include <iostream>
using namespace std;
int main()
{
    int i, j;
    char t;
    char ch[32][10] = {"a", "☺", "☻", "♥", "♦", "♣", "♠", "\\a", "\\b", "\\t", "\\n", "\\V", "\\f", "\\r", "♫",
                       "☼", "►", "◄", "↕", "‼", "¶", "§", "■", "↨", "↑", "→", "→", "←", "∟", "↔", "▲", "▼"};
    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < 8; j++)
        {
            t = j * 16 + i;
            if (t >= 0 && t <= 31)
            {
                cout << (int)t << ":" << ch[(int)t] << " | ";
            }
            else if (t >= 32 && t <= 126)
            {
                cout << (int)t << ":" << t << " | ";
            }
            else
            {
                cout << 127 << ":"
                     << "∆"
                     << " | ";
            }
        }
        cout << endl;
    }
    return 0;
}