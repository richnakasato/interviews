'''

ID | message
1  | ......
2  | ......
3  | ......
4  | ......
5  | ......

ID | Ack/Nack (boolean) | Mutliple (boolean)
1  | T | F
2  | T | F
4 | F | T -> replay 3 and 4
4 | F | T -> replay 3 and 4
4 | F | T -> replay 3 and 4
4 | F | T -> replay 3 and 4

4 | T | T -> continue
4 | F | T -> replay 3 and 4
4 | T | F -> lost 3 somehow, need to replay
4 | F | F -> also lost 3

5 | F | T
'''

#void put(int, string)
#bool remove(int, bool multiple)
#list replay(int start, int end)

from collections import deque

class Replayer():

    def __init__(self):
        self.memo = deque()
        pass

    def put(id_, string):
        #TODO: error handling
        data = (id_, string)
        self.memo.append(data)

    def remove(id_, multiple):
        #TODO: error handling
        target = id_
        front_id, dont_care = self.memo[0]
        if multiple:
            while front_id != target:
                self.memo.popleft()
                front_id, dont_care = self.memo[0]
            self.memo.popleft()
        else:
            front_id, dont_care = self.memo[0]
            if target != front_id:
                return False
            else:
                self.memo.popleft()
        return True

    def replay(start_id, end_id):
        #TODO: error handling
        output = list()
        for id_, string in self.memo:
            if start_id <= id_ <= end_id:
                output.append(string)
            if id_ > end_id:
                break
        return output


def main():
    pass

if __name__ == "__main__":
    main()
