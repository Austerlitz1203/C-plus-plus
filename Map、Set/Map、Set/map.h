#pragma once
#include"rb_tree.h"


namespace simulate
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
		bool insert(const pair<const K, V>& kv)
		{
			return _t.Insert(kv);
		}

	private:
		RBTree<K, pair<const K, V>, MapOfKey> _t;
	};
}