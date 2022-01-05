#include "lib.h"

string Rle::compress(const string &input_str) {
    unsigned int i = input_str.size();
    string letters;

    for (int j = 0; j < i; ++j) {
        int count = 1;
        while (input_str[j] == input_str[j + 1]) {
            count++;
            j++;
        }
        letters += std::to_string(count);
        letters.push_back(input_str[j]);
    }
    return letters;
}

bool alpha_or_space(const char c)
{
    return isalpha(c) || c == ' ';
}

string Rle::decompress(std::string& compressed)
{
    size_t i = 0;
    size_t repeat;
    string original;
    while (i < compressed.length())
    {
        while (alpha_or_space(compressed[i]))
            original.push_back(compressed[i++]);

        repeat = 0;
        while (isdigit(compressed[i]))
            repeat = 10 * repeat + (compressed[i++] - '0');

        auto char_to_unroll = compressed[i++];
        while (repeat--)
            original.push_back(char_to_unroll);
    }
    return original;
}

