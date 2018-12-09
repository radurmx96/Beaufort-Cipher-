#include <iostream>
#include <cstdlib>
#include <string>
#include "Functions.h"

int main() {
    int i, j, len;
    const char*alpha = "abcdefghijklmnopqrstuvwxyz";
    std::cout << "\nEnter length of key:" << std::endl;
    std::cin >> len;
    std::string cipher, key;
    char f_font,
            s_font,
            t_font;
    char c;
    std::cout << "\nEnter the word to cipher below \n[Note]: use lowercase and place spaces \n>>";
    for (i = 0; i < len; i++) { std::cin >> c;
        cipher += c;}
    std::cout << "The length of key is: " << len << "\nEnter the key word:" << std::endl;
    for (i = 0; i < len; i++) { std::cin >> c; key += c; }
    std::cout << std::endl;
    showAlpha(alpha);
    showOriginal(len, cipher);
    showKey(len, key);
    /*Position of cipher */
    f_font = cipher[0];
    int f_pos = 0,
            s_pos = 0,
            t_pos = 0;
    s_font = cipher[1];
    t_font = cipher[2];
    for (i = 0; i < 26; i++) {
        if (alpha[i] == f_font) f_pos = i;
        if (alpha[i] == s_font) s_pos = i;
        if (alpha[i] == t_font) t_pos = i;
    }
    /*Position of key_word*/
    int pos[10], *ad;
    for (i = 0; i < len; i++)
        for (j = 0; j < 26; j++)
            if ((char)key[i] == alpha[j]) {
                ad = &j;
                pos[i] = *ad;
            }

    /*Make a cipher*/
    makeCipher(len, f_pos, s_pos, t_pos, f_font, s_font, t_font, pos, cipher, alpha);
    system("pause");
    return 0;
}
