##        1
##    2       3
##4       5 6      7
from queue import *

class treeNode:
    def __init__(self, value: int, left = None, right = None):
        self.value = value
        self.left = left
        self.right = right

root = treeNode(1, treeNode(2, treeNode(4), None), treeNode(3, None, treeNode(5)))

def solution(root):
    print_queue = Queue()

    # Add root node to the queue
    print_queue.put(root)

    # Count level node number
    current_level_node = 1
    next_level_node = 0

    while (not print_queue.empty()):
        first = print_queue.get()
        current_level_node -= 1
        print(first.value, end = "")
        
        if first.left != None:
            print_queue.put(first.left)
            next_level_node += 1
        if first.right != None:
            print_queue.put(first.right)
            next_level_node += 1

        if current_level_node == 0:
            print("")
            current_level_node = next_level_node
            next_level_node = 0


if __name__ == "__main__":
    solution(root)


# Complexity Analysis
# Time complexity: O(N)
# Space complexity: O(w) w is maximum width of the binary tree.

