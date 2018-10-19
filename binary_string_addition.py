'''
output binary string of sum of 2 binary strings

'100' + '101' = '1001'
'1111' + '1' = '10000'

Takeaways:
    1) Need to normalize string inputs -> '1000' + '1' becomes '1000' + '0001'
    2) When thinking of 2 ptr, ask if we can do with 1 ptr

'''
from collections import deque

def bin_str_sum(bin1, bin2):
    sum_list = deque()
    max_len = max(len(bin1), len(bin2))
    bin1 = bin1.zfill(max_len)
    bin2 = bin2.zfill(max_len)
    carry = 0
    for i in range(max_len-1, -1, -1):
        curr_sum = carry
        curr_sum += 1 if bin1[i] == '1' else 0
        curr_sum += 1 if bin2[i] == '1' else 0
        sum_ = 0 if curr_sum%2 == 0 else 1
        carry = 0 if curr_sum < 2 else 1
        sum_list.appendleft(str(sum_))
    if carry:
        sum_list.appendleft(str(carry))
    return ''.join(sum_list)

def main():
    bin1 = '100'
    bin2 = '101'
    sum_ = '1001'
    assert bin_str_sum(bin1, bin2) == sum_, 'not adding correctly'

    bin1 = '1111'
    bin2 = '1'
    sum_ = '10000'
    assert bin_str_sum(bin1, bin2) == sum_, 'not adding correctly'

if __name__ == "__main__":
    main()
