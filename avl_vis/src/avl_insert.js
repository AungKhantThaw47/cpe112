export default class AVLTree {
    constructor() {
      this.root = null;
    }
  
    insert(value) {
      this.root = this._insertNode(this.root, value);
    }
  
    _insertNode(node, value) {
      // Step 1: Perform standard BST insertion
      if (node === null) {
        return new Node(value);
      }
  
      if (value < node.value) {
        node.left = this._insertNode(node.left, value);
      } else if (value > node.value) {
        node.right = this._insertNode(node.right, value);
      } else {
        // Value already exists in tree, do nothing
        return node;
      }
  
      // Step 2: Update height of current node
      node.height = 1 + Math.max(this._getHeight(node.left), this._getHeight(node.right));
  
      // Step 3: Get balance factor of current node
      const balanceFactor = this._getBalanceFactor(node);
  
      // Step 4: Rebalance the tree if necessary
      if (balanceFactor > 1 && value < node.left.value) {
        // Left Left Case
        return this._rotateRight(node);
      }
      if (balanceFactor > 1 && value > node.left.value) {
        // Left Right Case
        node.left = this._rotateLeft(node.left);
        return this._rotateRight(node);
      }
      if (balanceFactor < -1 && value > node.right.value) {
        // Right Right Case
        return this._rotateLeft(node);
      }
      if (balanceFactor < -1 && value < node.right.value) {
        // Right Left Case
        node.right = this._rotateRight(node.right);
        return this._rotateLeft(node);
      }
  
      return node;
    }
  
    _getHeight(node) {
      return node ? node.height : 0;
    }
  
    _getBalanceFactor(node) {
      return node ? this._getHeight(node.left) - this._getHeight(node.right) : 0;
    }
  
    _rotateLeft(node) {
      const newRoot = node.right;
      const leftChildOfNewRoot = newRoot.left;
  
      newRoot.left = node;
      node.right = leftChildOfNewRoot;
  
      node.height = 1 + Math.max(this._getHeight(node.left), this._getHeight(node.right));
      newRoot.height = 1 + Math.max(this._getHeight(newRoot.left), this._getHeight(newRoot.right));
  
      return newRoot;
    }
  
    _rotateRight(node) {
      const newRoot = node.left;
      const rightChildOfNewRoot = newRoot.right;
  
      newRoot.right = node;
      node.left = rightChildOfNewRoot;
  
      node.height = 1 + Math.max(this._getHeight(node.left), this._getHeight(node.right));
      newRoot.height = 1 + Math.max(this._getHeight(newRoot.left), this._getHeight(newRoot.right));
  
      return newRoot;
    }
  }
  
  class Node {
    constructor(value) {
      this.value = value;
      this.height = 1;
      this.left = null;
      this.right = null;
    }
  }
  