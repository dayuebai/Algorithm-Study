# 			6
# 	4				8
# 3		5		7		9

tree_array = [6,4,8,3,5,7,9]

class treeNode:
	def __init__(self, val = None, left = None, right = None):
		self.val = val
		self.left = left
		self.right = right


def construct_bt(tree_array: list, root_i, n):
	if root_i < n:
		return treeNode(tree_array[root_i], construct_bt(tree_array, 2*root_i+1, n), construct_bt(tree_array, 2*root_i+2, n))
	return None


def generate(tree_array):
	l = len(tree_array)

	if l != 0:
		root = treeNode(tree_array[0])
		root.left = construct_bt(tree_array, 1, l)
		root.right = construct_bt(tree_array, 2, l)
		return root
		
	return None


def in_order(treeNode):
	if treeNode != None:
		in_order(treeNode.left)
		print(treeNode.val)
		in_order(treeNode.right)


def pre_order(treeNode):
	if treeNode != None:
		print(treeNode.val)
		pre_order(treeNode.left)
		pre_order(treeNode.right)


def post_order(treeNode):
	if treeNode != None:
		post_order(treeNode.left)
		post_order(treeNode.right)
		print(treeNode.val)


if __name__ == "__main__":
	root = generate(tree_array)

	in_order(root)
