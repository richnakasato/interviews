def is_valid(d, s):
    keypad = [set(),
              set(),
              set(["A","B","C"]),
              set(["D","E","F"]),
              set(["G","H","I"]),
              set(["J","K","L"]),
              set(["M","N","O"]),
              set(["P","Q","R","S"]),
              set(["T","U","V"]),
              set(["W","X","Y","Z"])]
    lhs = 0
    rhs = 0
    while lhs < len(d) and not len(keypad[int(d[lhs])]):
        lhs += 1
    while lhs < len(d):
        digit = int(d[lhs])
        if len(keypad[digit]):
            if s[rhs] in keypad[digit]:
                rhs += 1
            else:
                return False
        lhs += 1
    return lhs == len(d) and rhs == len(s)


def helper(keypad, digits, index, curr, results):
    if index == len(digits):
        results.append(''.join(curr))
        return
    digit = int(digits[index])
    if not len(keypad[digit]):
        helper(keypad, digits, index+1, curr, results)
    else:
        for letter in keypad[digit]:
            curr.append(letter)
            helper(keypad, digits, index+1, curr, results)
            curr.pop()
    return


def all_perm(d):
    results = list()
    curr = list()
    keypad = [set(),
              set(),
              set(["A","B","C"]),
              set(["D","E","F"]),
              set(["G","H","I"]),
              set(["J","K","L"]),
              set(["M","N","O"]),
              set(["P","Q","R","S"]),
              set(["T","U","V"]),
              set(["W","X","Y","Z"])]
    helper(keypad, d, 0, curr, results)
    return results


def main():
    assert is_valid("000000001","") == True
    assert is_valid("0000000012","A") == True
    assert is_valid("2000000001","A") == True
    assert is_valid("234","ADG") == True
    assert is_valid("","AASDKWE") == False
    assert is_valid("012345678900","ADGJMPTW") == True
    assert is_valid("012345678900","DAGJMPTW") == False
    print(all_perm("23"))


if __name__ == "__main__":
    main()

