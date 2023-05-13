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

		typedef typename RBTree<K, K, KeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, KeyOfT>::const_iterator const_iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		pair<iterator,bool> insert(const K& k)
		{
			return _t.Insert(k);
		}

	private:
		RBTree<K, K, KeyOfT> _t;
	};
}
