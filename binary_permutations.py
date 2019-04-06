def helper(arr, n, curr, results):
    if n == 0:
        results.append(curr)
        return
    else:
        n-=1
        for c in arr:
            helper(arr, n, curr+c, results)
        return


def binary_permutations(arr, n):
    results = list()
    helper(arr, n, '', results)
    return results


def binary_perm_recurse(n):
    arr = ['A','B']
    return binary_permutations(arr, n)


def binary_perm_iter(n):
    res = ['A','B']
    n-=1
    while n:
        left = res[:]
        right = res[:]
        for i in range(len(res)):
            left[i] = 'A'+left[i]
            right[i] = 'B'+right[i]
        res = left + right
        n-=1
    return res


def main():
    n = 15
    for i in range(1,n+1):
        recursive = binary_perm_recurse(i)
        iterative = binary_perm_iter(i)
        assert recursive==iterative


if __name__ == "__main__":
    main()

