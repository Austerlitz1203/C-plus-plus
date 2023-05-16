#pragma once
#include"rb_tree.h"

namespace SetSimulate
{
	template<class K>
	class set
	{
		struct KeyOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};

	public:

		typedef typename RBTreeNode<K> Node;
		typedef typename RBTree<K, K, KeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, KeyOfT>::const_iterator const_iterator;
		typedef typename RBTree<K, K, KeyOfT>::const_reverse_iterator reverse_iterator;
		typedef typename RBTree<K, K, KeyOfT>::const_reverse_iterator const_reverse_iterator;
		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		const_iterator begin()const
		{
			return _t.begin();
		}

		const_iterator end()const
		{
			return _t.end();
		}

		reverse_iterator rbegin()
		{
			return _t.rbegin();
		}

		reverse_iterator rend()
		{
			return _t.rend();
		}

		const_reverse_iterator rbegin()const
		{
			return _t.rbegin();
		}

		const_reverse_iterator rend()const
		{
			return _t.rend();
		}

		pair<iterator,bool> insert(const K& k)
		{
			return _t.Insert(k);
		}

		iterator Find(const K& key)
		{
			Node* cur = _t.find(key);
			return iterator(cur);
		}

	private:
		RBTree<K, K, KeyOfT> _t;
	};
}
