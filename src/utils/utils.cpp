#include "utils.h"
#include <sstream>

void split_string(const string& str, vector<string>& tokens, const string& delimiters) {
    size_t lastPos = str.find_first_not_of(delimiters, 0);
    size_t pos = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos) {
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }
}

void clear_screen() {
    system("clear");  // Em Windows, use "cls"
}
