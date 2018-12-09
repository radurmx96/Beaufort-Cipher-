#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H
void showAlpha(const char*alpha) {
    std::cout << "Alphabet:\n";
    for (int i = 0; i < 26; i++) {
        std::cout << alpha[i] << "-" << i << " ";
        if (i == 11 || i == 21) std::cout << std::endl;
    }
    std::cout << std::endl;
}

void showOriginal(int len, std::string cipher) {
    int first = 0, second = 0;
    std::cout << "Original Message  : ";
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            std::cout << cipher[j] << " ";
            second += 1;
            if (second == len) {
                first = 1;
                break;
            }
        }
        if (first == 1) break;
    }
    std::cout << std::endl;
}

void showKey(int len, std::string key) {
    std::cout << "Key for Encryption: ";
    for (int i = 0; i < len; i++) std::cout << key[i] << " ";
    std::cout << std::endl;
}

void makeCipher(int len,
                int f_pos,
                int s_pos,
                int t_pos,
                char f_font,
                char s_font,
                char t_font,
                const int *pos,
                std::string cipher,
                std::string alpha) {
    int first = 0, second = 0,
            dr = 0, f = 0, s = 0, t = 0;
    std::cout << "Encrypted message : ";
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            dr = pos[j];
            if (i != 0) dr = pos[j + len];
            if (cipher[j] == f_font) {
                f = std::abs(dr - f_pos);
                std::cout << alpha[f] << " ";
            }
            if (cipher[j] == s_font) {
                s = std::abs(dr - s_pos);
                std::cout << alpha[s] << " ";
            }
            if (cipher[j] == t_font) {
                t = std::abs(dr - t_pos);
                std::cout << alpha[t] << " ";
            }
            second += 1;
            if (second == len) {
                first = 1;
                break;
            }
        }
        if (first == 1) break;
    }
}
#endif //TEST_FUNCTIONS_H
