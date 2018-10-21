'''
Find pair in arr that sum to target
'''
def findpair(arr, target):
    if arr == [] or target <= 1:
        return
    hi = 0
    ti = len(arr) - 1
    arr.sort()
    while hi <= ti:
        temp = target - arr[hi]
        if temp == arr[ti]:
            print('pair: ' + str(arr[hi]) + ', ' + str(arr[ti]))
            hi += 1
            ti -= 1
        elif temp > arr[ti]:
            hi += 1
        else: # temp < arr[ti]
            ti -= 1

def main():
    arr = [2, 14, 1, 6, 9, 11]
    target = 25
    findpair(arr, target)

if __name__ == "__main__":
    main()
