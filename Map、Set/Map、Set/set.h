#pragma once
#include"rb_tree.h"

template<class K, class V>
class set
{
	struct KeyOfT
	{
		const K& operator()(const pair<K, V>& kv)
		{
			return kv.first;
		}
	};

public:
	bool insert(const pair<K, V>& kv)
	{
		_t.Insert(kv);
	}

private:
	RBTree<K, pair<const K, V>,KeyOfT> _t;
};
