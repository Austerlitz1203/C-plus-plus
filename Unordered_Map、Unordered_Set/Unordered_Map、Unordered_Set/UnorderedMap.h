#include"HashTable.h"



namespace simulate_unorderedmap
{
	template<class K, class V,class Hash=HashBucket::HashFunc<K>>
	class unordered_map
	{
	public:

		struct KeyOfMap
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename HashBucket::HashNode<pair<const K, V>> Node;

		typedef typename HashBucket::HashTable<K, pair<const K, V>, KeyOfMap, Hash>::iterator iterator;
		typedef typename HashBucket::HashTable<K, pair<const K, V>, KeyOfMap, Hash>::const_iterator const_iterator;
		typedef typename HashBucket::HashTable<K, pair<const K, V>, KeyOfMap, Hash>::reverse_iterator reverse_iterator;
		typedef typename HashBucket::HashTable<K, pair<const K, V>, KeyOfMap, Hash>::const_reverse_iterator const_reverse_iterator;

		iterator begin()
		{
			return _map.begin();
		}

		iterator end()
		{
			return _map.end();
		}
	

		pair<iterator,bool> insert(const pair<const K, V>& kv)
		{
			return _map.insert(kv);
		}

		iterator Find(const K& key)
		{
			Node* cur = _map.Find(key);
			return iterator(cur, &_map);
		}

		bool Erase(const K& key)
		{
			return _map.Erase(key);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _map.insert(make_pair(key, V()));
			return ret.first->second;
		}


	private:
		HashBucket::HashTable<K, pair<const K, V>, KeyOfMap,Hash> _map;
	};

}