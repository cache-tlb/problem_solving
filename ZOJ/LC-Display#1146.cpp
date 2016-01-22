#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char buf[32];

void print_char(char c, int t) {
    for(int i = 0; i < t; i++) printf("%c", c);
}

int main(int argc, char const *argv[])
{
    int size;

    while(scanf("%d%s", &size, buf)) {
        if(!size) break;
        int len = strlen(buf);
        // head
        for(int k = 0; k < len; k++) {
            if(k) printf(" ");
            switch(buf[k]){
            case '0': case '2': case '3': case '5': case '6': case '7': case '8': case '9':
                print_char(' ', 1); print_char('-', size); print_char(' ', 1); break;
            case '1': case '4':
                print_char(' ', size + 2); break;
            default:
                break;
            }
        }
        printf("\n");
        // up
        for(int i = 0; i < size; i++) {
            for(int k = 0; k < len; k++) {
                if(k) printf(" ");
                switch(buf[k]) {
                //only left
                case '5': case '6':
                    print_char('|', 1); print_char(' ', size + 1); break;
                // only right
                case '1': case '2': case '3': case '7':
                    print_char(' ', size + 1); print_char('|', 1); break;
                // both
                case '4': case '8': case '9': case '0':
                    print_char('|', 1); print_char(' ', size); print_char('|', 1); break;
                default:
                    break;
                }
            }
            printf("\n");
        }
        // mid
        for(int k = 0; k < len; k++) {
            if(k) printf(" ");
            switch(buf[k]) {
            case '0': case '1': case '7':
                print_char(' ', size + 2); break;
            case '2': case '3': case '4': case '5': case '6': case '8': case '9':
                print_char(' ', 1); print_char('-', size); print_char(' ', 1); break;
            default:
                break;
            }
        }
        printf("\n");
        // down
        for(int i = 0; i < size; i++){
            for(int k = 0; k < len; k++) {
                if(k) printf(" ");
                switch(buf[k]) {
                // only left
                case '2':
                    print_char('|', 1); print_char(' ', size + 1); break;
                // only right
                case '1': case '3': case '4': case '5': case '7': case '9':
                    print_char(' ', size + 1); print_char('|', 1); break;
                // both
                case '6': case '8': case '0':
                    print_char('|', 1); print_char(' ', size); print_char('|', 1); break;
                default:
                    break;
                }
            }
            printf("\n");
        }
        // bottom
        for(int k = 0; k < len; k++) {
            if(k) printf(" ");
            switch(buf[k]){
            case '1': case '4': case '7':
                print_char(' ', size + 2); break;
            case '2': case '3': case '5': case '6': case '8': case '9': case '0':
                print_char(' ', 1); print_char('-', size); print_char(' ', 1); break;
            default:
                break;
            }
        }
        printf("\n\n");
    }
    return 0;
}
