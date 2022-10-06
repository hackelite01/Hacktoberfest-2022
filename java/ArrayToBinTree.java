/*
 *Node Class for BinaryTree
 *
 */
class Node {
	int data;
	Node left = null;
	Node right = null;

	Node(int n) {
		this.data = n;
	}
}
/*
 *
 *Binary Tree Class
 */

class BinaryTree {

	Node root = null;

	// Constructor

	BinaryTree(int[] arr) {
		this.root = this.arrToBinTree(arr, 0, arr.length);
	}

	// Print Driver for BinaryTree

	void print() {
		this.printTree(this.root);
	}

	// Recursive inner implementation for conversion

	private Node arrToBinTree(int[] arr, int i, int len) {
		Node node = null;
		if (len == 0 || i >= len) return node;
		node = new Node(arr[i]);
		node.left = this.arrToBinTree(arr, 2 * i + 1, len);
		node.right = this.arrToBinTree(arr, 2 * i + 2, len);
		return node;
	}

	// Simple inorder traveraal based recursive print method
	private void printTree(Node root) {
		if (root == null) return;
		System.out.println(root.data);
		printTree(root.left);
		printTree(root.right);
		return;
	}
}

public class Main {


	// DRIVER CODE

	public static void main(String[] args) {
		// pre defined test array
		int[] arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

		// creating new Binary Tree Object

		BinaryTree t1 = new BinaryTree(arr);

		// print binary Tree

		t1.print();
	}
}

