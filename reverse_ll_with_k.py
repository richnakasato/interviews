class Node(object):

    def __init__(self, data, next_=None):
        self.data = data
        self.next = next_


def reverse_ll(head):
    curr = head
    prev = None
    while curr:
        temp = curr.next
        curr.next = prev
        prev = curr
        curr = temp
    return prev

def reverse_ll_with_k(head, k):
    curr = head
    prev = None
    new_head = None
    count = 0
    stack = list()
    while curr:
        if count < k:
            stack.append(curr)
            curr = curr.next
            count += 1
        else:
            while len(stack):
                if not prev:
                    prev = stack.pop()
                    if not new_head:
                        new_head = prev
                else:
                    prev.next = stack.pop()
                    prev = prev.next
    return new_head

def main():
    head = curr = None
    n = 9
    for num in range(1, n):
        if not head:
            head = Node(num)
            curr = head
        else:
            curr.next = Node(num)
            curr = curr.next

    curr = head
    while curr:
        print(curr.data)
        curr = curr.next

    '''
    print("reversed")
    rev_head = reverse_ll(head)
    curr = rev_head
    while curr:
        print(curr.data)
        curr = curr.next
    '''

    print("reversed k")
    rev_head = reverse_ll_with_k(head, 2)
    curr = rev_head
    while curr:
        print(curr.data)
        curr = curr.next

if __name__ == "__main__":
    main()

