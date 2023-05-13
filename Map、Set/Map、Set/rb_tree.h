#pragma once
#include<iostream>
#include<cassert>

using namespace std;


	enum Colour
	{
		RED,
		BLACK,
	};

	template<class T>
	struct RBTreeNode
	{
		RBTreeNode<T>* _left;
		RBTreeNode<T>* _right;
		RBTreeNode<T>* _parent;
		T _data;
		Colour _col;

		RBTreeNode(const T& val)
			: _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _data(val)
			, _col(RED)
		{}
	};

	

	template<class T,class Ref,class Ptr>
	struct _RBTreeIterator
	{
		typedef RBTreeNode<T> Node;
		typedef _RBTreeIterator<T, Ref, Ptr> self;


		_RBTreeIterator(Node* node)
			:_node(node)
		{}


		_RBTreeIterator(const _RBTreeIterator<T, T&, T*> &it)
			:_node(it._node)
		{}


		Ref operator*()
		{
			return _node->_data;
		}

		bool operator!=(const self& s)
		{
			return this->_node != s._node;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		self& operator++()
		{
			// 右子树存在，先去右子树的第一个
			if (_node->_right)
			{
				Node* subleft=_node->_right;
				while (subleft->_left)
				{
					subleft = subleft->_left;
				}

				_node = subleft;
			}
			else // 右子树不存在，向上找
			{
				Node* cur = _node;
				Node* parent = _node->_parent;
				while (parent && parent->_right == cur)
				{
					cur = cur->_parent;
					parent = parent->_parent;
				}
				_node = parent;
			}

			return *this;
		}

		self& operator--()
		{
			if (_node->_left)
			{
				Node* subright = _node->_left;
				while (subright->_right)
				{
					subright = subright->_right;
				}
				_node = subright;
			}
			else // 当前节点没有左子树，直接向上找，直到 parent 的左子节点是 cur
			{
				Node* cur = _node;
				Node* parent = cur->_parent;
				while (parent && parent->_left == cur)
				{
					cur = cur->_parent;
					parent = parent->_parent;
				}
				_node = parent;
			}

			return *this;
		}



		Node* _node;
	};


	template<class T, class Ref, class Ptr>
	struct _RBTreeReverseIterator
	{
		typedef RBTreeNode<T> Node;
		typedef _RBTreeReverseIterator<T, Ref, Ptr> self;

		_RBTreeReverseIterator(Node* node)
		{
			_it._node = node;
		}

		_RBTreeReverseIterator(const _RBTreeIterator<T, T&, T*>& it)
		{
			_it._node = it._node;
		}

		_RBTreeReverseIterator(const _RBTreeReverseIterator<T, T&, T*>& it)
		{
			_it._node = it._it._node;
		}
		
		self& operator++()
		{
			--_it;
			return *this;
		}

		self& operator--()
		{
			++_it;
			return *this;
		}

		bool operator!=(const self& s)
		{
			return _it._node != s._it._node;
		}

		Ptr operator->()
		{
			return &_it._node->_data;
		}

		Ref operator*()
		{
			return _it._node->_data;
		}

		struct _RBTreeIterator<T,Ref,Ptr> _it=nullptr;
	};



	template<class K, class T, class KeyOfT>
	class RBTree
	{
		typedef struct RBTreeNode<T> Node;

	public:
		typedef _RBTreeIterator<T, T&, T*> iterator;
		typedef _RBTreeIterator<T, const T&, const T*> const_iterator;
		typedef _RBTreeReverseIterator<T, T&, T*> reverse_iterator;
		typedef _RBTreeReverseIterator<T, const T&, const T*> const_reverse_iterator;
	public:

		iterator begin()
		{
			Node* cur = _root;
			while (cur && cur->_left)
			{
				cur = cur->_left;
			}

			return iterator(cur);
		}

		iterator end()
		{
			return iterator(nullptr);
		}

		const_iterator begin() const
		{
			Node* cur = _root;
			while (cur && cur->_left)
			{
				cur = cur->_left;
			}

			return const_iterator(cur);
		}

		const_iterator end() const
		{
			return const_iterator(nullptr);
		}


		reverse_iterator rbegin()
		{
			Node* cur = _root;
			while (cur && cur->_right)
			{
				cur = cur->_right;
			}

			return reverse_iterator(cur);
		}

		reverse_iterator rend()
		{
			return reverse_iterator(nullptr);
		}

		const_reverse_iterator rbegin() const
		{
			Node* cur = _root;
			while (cur && cur->_right)
			{
				cur = cur->_right;
			}

			return const_reverse_iterator(cur);
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(nullptr);
		}


		~RBTree()
		{
			Delete(_root);
			_root = nullptr;
		}

		Node* find(const K& val)
		{
			KeyOfT kt;
			Node* cur = _root;
			while (cur)
			{
				if (kt(val) > kt(cur->_data))
				{
					cur = cur->_right;
				}
				else if (kt(val) < kt(cur->_data))
				{
					cur = cur->_left;
				}
				else
					return cur;
			}

			return nullptr;
		}

		pair<iterator,bool> Insert(const T& val)
		{
			if (_root == nullptr)
			{
				_root = new Node(val);
				_root->_col = BLACK;
				return make_pair(iterator(_root),true);
			}
			KeyOfT kt;
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur) // 找到要插入的位置
			{
				if (kt(cur->_data) > kt(val))
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (kt(cur->_data) < kt(val))
				{
					parent = cur;
					cur = cur->_right;
				}
				else
					return make_pair(iterator(_root), false);
			}

			// 插入
			cur = new Node(val);
			if (kt(parent->_data) < kt(val))
			{
				parent->_right = cur;
			}
			else if (kt(parent->_data) > kt(val))
			{
				parent->_left = cur;
			}
			cur->_parent = parent;


			// 调整颜色
			while (parent && parent->_col == RED)
			{
				Node* grandfather = parent->_parent;
				if (parent == grandfather->_left)
				{
					Node* uncle = grandfather->_right;
					if (uncle && uncle->_col == RED) // uncle 为红色
					{
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandfather->_col = RED;

						// 继续调整
						cur = grandfather;
						parent = cur->_parent;
					}
					else // uncle不存在 or 存在且为黑
					{
						if (cur == parent->_left)
						{
							RotateR(grandfather);
							parent->_col = BLACK;
							grandfather->_col = RED;
							//cur->_col = RED;
						}
						else if (cur == parent->_right)
						{
							RotateL(parent);
							RotateR(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;
							parent->_col = RED;
						}

						break;
					}
				}
				else // if (parent == grandfather->_right)
				{
					Node* uncle = grandfather->_left;
					if (uncle && uncle->_col == RED) // uncle 为红色
					{
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandfather->_col = RED;

						// 继续调整
						cur = grandfather;
						parent = cur->_parent;
					}
					else // uncle不存在 or 存在且为黑
					{
						if (cur == parent->_right)
						{
							RotateL(grandfather);
							parent->_col = BLACK;
							grandfather->_col = RED;
							//cur->_col = RED;
						}
						else // cur == parent->_left
						{
							RotateR(parent);
							RotateL(grandfather);
							cur->_col = BLACK;
							parent->_col = RED;
							grandfather->_col = RED;
						}

						break;
					}
				}
			}

			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}

		int Height()
		{
			return _Height(_root);
		}

		bool isBalance()
		{
			if (_root->_col == RED)
			{
				cout << "根节点的颜色是红色" << endl;
				return false;
			}

			int benchmark = 0;
			Node* tmp = _root;
			while (tmp)
			{
				if (tmp->_col == BLACK)
					benchmark++;
				tmp = tmp->_left;
			}

			return _isBalance(_root, 0, benchmark);
		}

		void Inorder()
		{
			_Inorder(_root);
		}

	private:

		void _Inorder(Node* root)
		{
			if (root == nullptr)
				return;

			_Inorder(root->_left);
			cout << root->_kv.first << " ";
			_Inorder(root->_right);
		}

		bool _isBalance(Node* root, int blackNum, int benchmark)
		{
			if (root == nullptr)
			{
				if (blackNum == benchmark)
					return true;
				else
				{
					cout << "某条链路黑色节点数目错误！" << endl;
					return false;
				}
			}

			if (root->_col == BLACK)
				++blackNum;
			else
			{
				if (root->_parent && root->_parent->_col == RED)
				{
					cout << "存在两个连续的红色节点" << endl;
					return false;
				}
			}

			return _isBalance(root->_left, blackNum, benchmark)
				&& _isBalance(root->_right, blackNum, benchmark);
		}

		int _Height(Node* root)
		{
			if (root == nullptr) return 0;

			int leftH = _Height(root->_left);
			int rightH = _Height(root->_right);

			return leftH > rightH ? leftH + 1 : rightH + 1;
		}



		void Delete(Node* root)
		{
			if (root == nullptr)
				return;

			Delete(root->_left);
			Delete(root->_right);
			free(root);
		}

		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			parent->_right = subRL;
			if (subRL)
				subRL->_parent = parent;

			Node* pparent = parent->_parent;
			subR->_left = parent;
			parent->_parent = subR;

			if (pparent == nullptr)
			{
				_root = subR;
				_root->_parent = nullptr;
			}
			else
			{
				if (parent == pparent->_left)
				{
					pparent->_left = subR;
				}
				else
				{
					pparent->_right = subR;
				}
				subR->_parent = pparent;
			}


		}



		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			Node* pparent = parent->_parent;
			subL->_right = parent;
			parent->_parent = subL;

			parent->_left = subLR;
			if (subLR)
				subLR->_parent = parent;


			if (pparent == nullptr)
			{
				subL->_parent = nullptr;
				_root = subL;
			}
			else
			{
				if (parent == pparent->_left)
				{
					pparent->_left = subL;
				}
				else
				{
					pparent->_right = subL;
				}

				subL->_parent = pparent;
			}

		}

	private:
		Node* _root;
	};

