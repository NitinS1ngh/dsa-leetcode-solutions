class Solution {
public:
    long long sumAndMultiply(int n) {
        int p = 1;
        int num = 0;
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;

            if (digit != 0) {
                num += digit * p;
                sum += digit;
                p *= 10;
            }

            n /= 10;
        }

        return 1LL * num * sum;
    }
};