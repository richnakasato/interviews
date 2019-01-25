import itertools
from collections import deque

def bin_add(lhs, rhs):
    pairs_to_sum = itertools.izip_longest(reversed(lhs), reversed(rhs), fillvalue='0')
    sum_ = deque()
    carry = 0
    for l_val, r_val in pairs_to_sum:
        temp = carry + int(l_val) + int(r_val)
        sum_.appendleft(str(temp%2))
        carry = temp//2
    if carry:
        sum_.appendleft(str(carry))
    return ''.join(sum_)


def main():
    lhs = '1111'
    rhs = '1'
    ans = '10000'
    assert bin_add(lhs, rhs)==ans
    lhs = '100'
    rhs = '101'
    ans = '1001'
    assert bin_add(lhs, rhs)==ans


if __name__ == "__main__":
    main()

