#include <cstring>
using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = strlen(needle);
        if (!len) return haystack;
        while (*haystack) {
            if (strncmp(haystack, needle, len) == 0) return haystack;
            haystack++;
        }
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
