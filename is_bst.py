def helper(min_, node, max_):
    if not node:
        return True
    curr = min_ < node.val <= max_
    return  curr and
            helper(min_, node.left, node.val) and
            helper(node.val, node.right, max_)


def is_bst_recurse(root):
    if not root:
        return False
    else:
        return helper(float('-inf'), root, float('inf'))


def is_bst_inorder(root):
    if not root:
        return False
    stack = list()
    curr = root
    done = False
    inorder = list()
    while not done:
        if curr:
            stack.append(curr)
            curr = curr.left
        else:
            if len(stack):
                curr = stack.pop()
                inorder.append(curr.val)
                curr = curr.right
            else:
                done = True
    for i in range(1,len(inorder)):
        if inorder[i] < inorder[i-1]:
            return False
    return True


def main():
    pass


if __name__ == "__main__":
    main()

