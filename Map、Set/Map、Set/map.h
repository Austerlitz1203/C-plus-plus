#pragma once
#include"rb_tree.h"


namespace MapSimulate
{
	template<class K, class V>
	class map
	{
		struct MapOfKey
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename RBTreeNode<pair<const K, V>> Node;
		typedef typename RBTree<K, pair<const K,V>, MapOfKey>::iterator iterator;
		typedef typename RBTree<K, pair<const K,V>, MapOfKey>::const_iterator const_iterator;
		typedef typename RBTree<K, pair<const K, V>, MapOfKey>::reverse_iterator reverse_iterator;
		typedef typename RBTree<K, pair<const K, V>, MapOfKey>::const_reverse_iterator const_reverse_iterator;

		pair<iterator,bool> insert(const pair<const K, V>& kv)
		{
			return _t.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _t.Insert(make_pair(key, V()));
			return ret.first->second;
		}

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

		iterator Find(const K& key)
		{
			Node* cur = _t.find(key);
			return iterator(cur);
		}

	private:
		RBTree<K, pair<const K, V>, MapOfKey> _t;
	};
}