#include"HashTable.h"

namespace simulate_unorderedset
{

	template<class K, class Hash = HashBucket::HashFunc<K>>
	class unordered_set
	{
	public:
		typedef typename HashBucket::HashNode<K> Node;
		struct KeyOfSet
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:

		typedef typename HashBucket::HashTable<K, K, KeyOfSet, Hash>::const_iterator iterator;
		typedef typename HashBucket::HashTable<K, K, KeyOfSet, Hash>::const_iterator const_iterator;
		typedef typename HashBucket::HashTable<K, K, KeyOfSet, Hash>::const_reverse_iterator reverse_iterator;
		typedef typename HashBucket::HashTable<K, K, KeyOfSet, Hash>::const_reverse_iterator const_reverse_iterator;

		pair<iterator,bool> insert(const K& key)
		{
			return _set.insert(key);
		}

		bool Erase(const K& key)
		{
			return _set.Erase(key);
		}

		iterator Find(const K& key)
		{
			Node* cur=_set.Find(key);
			return iterator(cur, &_set);
		}

		iterator begin()
		{
			return _set.begin();
		}

		iterator end()
		{
			return _set.end();
		}

		const_iterator begin()const
		{
			return _set.begin();
		}

		const_iterator end()const
		{
			return _set.end();
		}

		reverse_iterator rbegin()
		{
			return _set.rbegin();
		}

		reverse_iterator rend()
		{
			return _set.rend();
		}


	private:
		HashBucket::HashTable<K, K, KeyOfSet,Hash> _set;
	};

}
