#include <string>

using namespace std;

class Rle {
public:
    static string compress(const string &input_str);
    static string decompress(std::string& compressed);
};