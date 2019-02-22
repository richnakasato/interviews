'''
array = [1,2,1,2,3,4,5,6,7,7,7,1,2]

s = [1,2,3,4,5,3,1,2,5,3]
# receive array ints, must return LIST of longest continguous sequence containing unique numbers

map = {1: deq[2idx]
       2: deq[3idx]
       3: deq[4idx]}
       start_seq = 2
       curr_seq = 3
length_of_unique_seq_at_idx = [2, 2, ]

arr = [1,2,1,2]
dict = {1:2,
        2:3,

array = [1,2,1,2,3,4,5,6,7,7,7,1,2]
seen_idx = {1:2,
            2:3,
            3:4
            4:5
            5:6
            6:7}

def solution(arr):
    seen_idxs = dict()
    for idx,num in enumerate(arr):
        seen_idxs[num] = idx
    start = len(arr) + 1
    end = 0
    for k,v in seen_idxs:
        start = min(start, v)
        end = max(end, v)
    return arr[start:end]
'''

def solution(arr):
    seen = dict()
    ending_here = [1] * len(arr)
    seen[arr[0]] = True
    for idx in range(1,len(arr)):
        num = arr[idx]
        if not num in seen:
            ending_here[idx] = ending_here[idx-1] + 1
        else:
            seen.clear()
        seen[num] = True
    max_idx = 0
    max_end = 0
    for idx,end in enumerate(ending_here):
        if max_end < end:
            max_idx = idx
            max_end = end
    start = max_idx+1 - max_end
    return arr[start:start+max_end]



def main():
    arr = [1,2,1,2,3,4,5,6,7,7,7,1,2]
    print(solution(arr))


if __name__ == "__main__":
    main()

