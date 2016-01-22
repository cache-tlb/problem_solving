#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!n) return 0;
        int sum = 0;
        while (1) {
            int front = 0, rear = n - 1;
            int f_height = 0, r_height = 0;
            while (front < n && A[front] >= f_height) f_height = A[front++];
            while (rear >= 0 && A[rear] >= r_height) r_height = A[rear--];
            front--; rear++;
            //printf("%d %d\n", front, rear);
            if(front >= rear) break;
            int min_height = A[front], min_pos = front;
            for (int i = front; i <= rear; i++) {
                if (A[i] < min_height) {
                    min_height = A[i];
                    min_pos = i;
                }
            }
            //printf("min pos %d\n", min_pos);
            int min_front = min_pos, min_rear = min_pos;
            f_height = r_height = min_height;
            while (min_front >= 0 && A[min_front] >= f_height) f_height = A[min_front--];
            while (min_rear < n && A[min_rear] >= r_height) r_height = A[min_rear++];
            min_front++; min_rear--;
            //printf("min front/rear%d %d, height front/rear%d %d\n", min_front, min_rear, f_height, r_height);
            int target = min(f_height, r_height);
            for (int i = min_front + 1; i <= min_rear - 1; i++) if(A[i] < target) {
                sum += target - A[i];
                A[i] = target;
            }
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int A[] = {5,4,1,2};
    int n = sizeof(A) / sizeof(int);
    printf("%d\n", s.trap(A, n));
    return 0;
}
