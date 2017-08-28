#include <iostream>
#include <vector>

std::vector<long long> batch_sizes;
void init() {
    long long tmp = 2;
    long long tmp2 = 10;
    for (int i = 0; i < 18; i++) {
        batch_sizes.push_back(tmp);
        tmp = tmp*8 + 2*tmp2;
        tmp2 *= 10;
    }
}

long long find(long long k) {
    if (k == 0) return 4;
    if (k == 1) return 7;
    int scale_index = batch_sizes.size() - 1;
    long long tmp = 1;
    for (int i = 0; i < batch_sizes.size(); i++) {
        if (k < batch_sizes[i]) {
            scale_index = i - 1;
            break;
        }
        tmp *= 10;
    }
    long long head = 0;
    long long rem = 0;
    long long batch_size = batch_sizes[scale_index];
    if (0 <= k && k < 4*batch_size) {
        head = k/batch_size;
        rem = k - head*batch_size;
    } else if (4*batch_size <= k && k < 4*batch_size + tmp) {
        head = 4;
        return tmp*head + (k - 4*batch_size);
    } else if (4*batch_size + tmp <= k && k < 6*batch_size + tmp) {
        int extra = (k - 4*batch_size - tmp)/batch_size;
        head = extra + 5;
        rem = k - (tmp + (4+extra)*batch_size);
    } else if (6*batch_size + tmp <= k && k < 6*batch_size + tmp*2) {
        head = 7;
        return tmp*head + (k - 6*batch_size - tmp);
    } else {
        int extra = (k - 6*batch_size - tmp*2)/batch_size;
        head = extra + 8;
        rem = k - (tmp*2 + (6+extra)*batch_size);
    }
    // std::cout << tmp << std::endl;
    // std::cout << batch_size[scale_index] << std::endl;
    return tmp*head + find(rem);
}
// 981985601490518016 -> max batch size
// 9223372036854775807 -> long long
// 1000000000000000000 -> 1e18
int main(int argc, char const *argv[]) {
    init();
    long long k;
    std::cin >> k;
    k--;
    long long res = find(k);
    std::cout << res << std::endl;
    return 0;
}
