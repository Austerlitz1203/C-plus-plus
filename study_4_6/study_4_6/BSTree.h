#pragma once

template<class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;

	BSTreeNode(const K& val)
		:_left(nullptr)
		,_right(nullptr)
		,_key(val)
	{}
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:

	bool Insert(const K& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_key < val)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > val)
			{
				parent = cur;
				cur = cur->_left;
			}
			else {
				return false;
			}
		}

		if (parent->_key < val)
			parent->_right = new Node(val);
		else
			parent->_left = new Node(val);

		return true;
	}

	bool find(const K& val)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > val)
			{
				cur = cur->_left;
			}
			else if (cur->_key < val)
			{
				cur = cur->_right;
			}
			else
				return true;
		}
		return false;
	}


	// É¾³ý
	bool Erase(const K& val)
	{
		Node* cur = _root;
		Node* parent = root;
		while (cur)
		{
			if (cur->_key < val)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > val)
			{
				parent = cur;
				cur = cur->_left;
			}
			else // ÏàµÈ£¬É¾³ý
			{

			}
		}
	}

	void Inorder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr) return;

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

private:
	Node* _root = nullptr;
};