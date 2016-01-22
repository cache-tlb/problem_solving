class Solution {
public:
    double pow(double x, int n) {
        return _pow(x, (long long)n);
    }
    double _pow(double x, long long n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 0) return _pow(1.0/x, -n);
        if (!n) return 1.0;
        double y = _pow(x, n/2);
        if (n%2)
            return x*y*y;
        else
            return y*y;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
