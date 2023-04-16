#pragma once
#include<algorithm>

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


	// 删除
	bool Erase(const K& val)
	{
		Node* cur = _root;
		Node* parent = _root;
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
			else // 相等，删除
			{
				// 左为空
				if (cur->_left == nullptr)
				{
					if (parent->_left == cur)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
					delete cur;
				}// 右为空
				else if (cur->_right == nullptr)
				{
					if (parent->_left == cur)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
					delete cur;
				}
				else // 左右都不为空
				{
					Node* pminRight = nullptr;
					Node* minRight=cur->_right;
					while (minRight->_left)
					{
						pminRight = minRight;
						minRight = minRight->_left;
					}

					cur->_key = minRight->_key;
					// 删除节点的右边就是最小值
					if (minRight == cur->_right)
					{
						cur->_right = minRight->_right;
					}
					else 
					{
						pminRight->_left = minRight->_right;
					}
					
					delete minRight;
				}
				return true;
			}

		}
		return false;
	}

	bool _FindR(Node* root, const K& val)
	{
		if (root == nullptr) return false;

		if (root->_key > val) return _FindR(root->_left, val);
		else if (root->_key < val) return _FindR(root->_right, val);
		else return true;
	}

	bool FIndR(const K& val)
	{
		return _FindR(_root, val);
	}

	bool _InsertR(Node* &root, const K& val)
	{
		if (root == nullptr)
		{
			root = new Node(val);
			return true;
		}
		if (root->_key < val)
			_InsertR(root->_right, val);
		else if (root->_key > val) 
			_InsertR(root->_left, val);
		else return false;
	}

	bool InsertR(const K& val)
	{
		return _InsertR(_root, val);
	}

	bool _EraseR(Node* &root, const K& val)
	{
		if (root == nullptr) return false;
		if (root->_key > val)
		{
			_EraseR(root->_left, val);
		}
		else if (root->_key < val)
		{
			_EraseR(root->_right, val);
		}
		else
		{
			if (root->_left == nullptr)
			{
				root = root->_right;
			}
			else if (root->_right == nullptr)
			{
				root = root->_left;
			}
			else // 左右都不为空
			{
				Node* maxleft = root->_left;
				while (maxleft->_right)
				{
					maxleft = maxleft->_right;
				}
				swap(root->_key, maxleft->_key);
				_EraseR(root->_left, val);
			}
			return true;
		}

		return false;
	}

	bool EraseR(const K& val)
	{
		return _EraseR(_root, val);
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