class Node():

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def __str__(self):
        return str('{}'.format(self.data))


def flatten_tree(root):
    stack = list()
    curr = root
    done = False
    head = None
    prev = None
    while not done:
        if curr:
            stack.append(curr)
            curr = curr.left
        else:
            if stack:
                curr = stack.pop()

                #dostuff
                if not head:
                    head = curr
                if prev:
                    prev.right = curr
                curr.left = prev
                prev = curr

                curr = curr.right
            else:
                done = True
    prev.right = head
    head.left = prev
    return head


def main():
    n1 = Node(1)
    n2 = Node(2)
    n3 = Node(3)
    n4 = Node(4)
    n5 = Node(5)
    n6 = Node(6)
    n7 = Node(7)
    root = n4
    n4.left = n2
    n4.right = n6
    n2.left = n1
    n2.right = n3
    n6.left = n5
    n6.right = n7
    head = flatten_tree(root)
    print('---')
    print(head)
    print(head.right)
    print(head.right.right)
    print(head.right.right.right)
    print(head.right.right.right.right)
    print(head.right.right.right.right.right)
    print(head.right.right.right.right.right.right)
    print(head.right.right.right.right.right.right.right)

    print('---')
    print(head)
    print(head.left)
    print(head.left.left)
    print(head.left.left.left)
    print(head.left.left.left.left)
    print(head.left.left.left.left.left)
    print(head.left.left.left.left.left.left)
    print(head.left.left.left.left.left.left.left)

if __name__ == "__main__":
    main()

