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


def main():
    arr = ['A','B']
    result = binary_permutations(arr, 4)
    assert result==["AAAA", "AAAB", "AABA", "AABB", "ABAA", "ABAB", "ABBA", "ABBB", "BAAA", "BAAB", "BABA", "BABB", "BBAA", "BBAB", "BBBA", "BBBB"]


if __name__ == "__main__":
    main()

