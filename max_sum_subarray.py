def max_sum_subarray(arr):
    g_max = l_max = 0;
    for num in arr:
        l_max = max(l_max + num, num)
        g_max = max(g_max, l_max)
    return g_max


def main():
    arr = [1,3,6,-7,-1,0,1,5,2]
    print(max_sum_subarray(arr))


if __name__ == "__main__":
    main()
