/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
    template <int N>
    struct Fib {
        static constexpr int value
            = Fib<N - 1>::value + Fib<N - 2>::value;
    };
    template <>
    struct Fib<1> {
        static constexpr int value = 1;
    };
    template <>
    struct Fib<0> {
        static constexpr int value = 0;
    };
    template <int N>
    static constexpr int Fib_v = Fib<N>::value;

    constexpr int FIB(int input) {
        return (input > 1)
            ? FIB(input - 1) + FIB(input - 2)
            : input;
    }

public:
    int fib(int n) {
        return FIB(n);
    }
};
// @lc code=end
