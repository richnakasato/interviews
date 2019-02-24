# arr = [1,2,1,2,3,4,5,6,7,7,7,1,2]

def solution(arr):
    seen = dict()
    seen[arr[0]] = True
    g_max, g_left, g_right = 1,0,1
    l_max, l_left, l_right = 1,0,1
    for i in range(1,len(arr)):
        cur = arr[l_right]
        if not cur in seen:
            seen[cur] = True
            l_max += 1
        else:
            if g_max < l_max:
                g_max = l_max
                g_left = l_left
                g_right = l_right
            seen.clear()
            seen[cur] = True
            l_left = l_right = i
            l_max = 1
        l_right += 1
    if g_max < l_max:
        g_max = l_max
        g_left = l_left
        g_right = l_right
    return arr[g_left:g_right]


def main():
    arr = [1,2,1,2,3,4,5,6,7,7,7,1,2]
    #arr = [1,2,1,2,3,4,5,6,7]
    result = solution(arr)
    print(result)

if __name__ == "__main__":
    main()

