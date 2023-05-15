#pragma once
#include<iostream>
#include<vector>

using namespace std;

namespace HashBucket
{
	template<class T>
	struct HashNode
	{
		HashNode<T>* _next;
		T _data;

		HashNode(const T& data)
			:_next(nullptr)
			, _data(data)
		{}
	};


	template<class K>
	struct HashFunc
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};

	// 模板的特化，如果有 string 类型的数据，优先使用特化的模板
	template<>
	struct HashFunc<string>
	{
		size_t operator()(const string& s)
		{
			size_t hash = 0;
			for (auto& a : s)
			{
				hash += a;
				hash *= 31;
			}
			return hash;
		}
	};

	// 前置声明，不需要默认参数
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;


	template<class K,class T,class Ref,class Ptr,class KeyOfT,class Hash=HashFunc<K>>
	struct Iterator
	{
	public:
		typedef HashNode<T> Node;
		typedef Iterator<K, T, Ref, Ptr, KeyOfT, Hash> self;
		typedef HashTable<K, T, KeyOfT, Hash> HT;
	public:
		Iterator(Node* node = nullptr, HT* tables= nullptr)
			:_node(node)
			,_ht(tables)
		{}

		Iterator(const Iterator<K,T,T&,T*,KeyOfT,Hash>& it)
			:_node(it._node)
			,_ht(it._ht)
		{}

		Ptr operator->()
		{
			return &_node->_data;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		bool operator!=(const self& it)
		{
			return _node != it._node;
		}

		self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
				return *this;
			}

			// 找到下一个有数据的桶
			KeyOfT kot;
			Hash hash;
			size_t hashi = hash(kot(_node->_data)) % _ht->_tables.size();
			++hashi;
			while (hashi < _ht->_tables.size())
			{
				if (_ht->_tables[hashi])
				{
					_node = _ht->_tables[hashi];
					break;
				}
				else
				{
					++hashi;
				}
			}

			if (hashi >= _ht->_tables.size())
				_node = nullptr;

			return *this;
		}

		self& operator--()
		{
			// 找到当前桶
			KeyOfT kot;
			Hash hash;
			int hashi = hash(kot(_node->_data)) % _ht->_tables.size();
			
			// 桶的第一个就是当前节点构成的迭代器,往前面的桶找
			if (_ht->_tables[hashi] == _node)
			{
				--hashi;
				while (hashi >= 0)
				{
					if (_ht->_tables[hashi] == nullptr)
					{
						--hashi;
					}
					else
					{
						// 找到上一个有数据的桶的最后一个数据
						Node* cur = _ht->_tables[hashi];
						while (cur->_next)
							cur = cur->_next;
						_node = cur;
						break;
					}
				}

				if (hashi < 0)
					_node = nullptr;
			}
			else // 桶的第一个不是当前节点构成的迭代器，在该桶里面找
			{
				Node* cur = _ht->_tables[hashi];
				while (cur->_next != _node)
				{
					cur = cur->_next;
				}
				_node = cur;
			}

			return *this;
		}

		Node* _node;
		HT* _ht;
	};


	template<class K,class T,class Ref,class Ptr,class KeyOfT,class Hash=HashFunc<K>>
	struct ReverseIterator
	{
		
		typedef HashNode<T> Node;
		typedef ReverseIterator<K, T, Ref, Ptr, KeyOfT, Hash> self;
		typedef HashTable<K, T, KeyOfT, Hash> HT;

		ReverseIterator(Node* node, HT* ht)
		{
			it._node = node;
			it._ht = ht;
		}

		ReverseIterator(const Iterator<K, T,Ref,Ptr,KeyOfT,Hash> rit)
		{
			it._node = rit._node;
			it._ht = rit._ht;
		}

		ReverseIterator(const ReverseIterator<K, T, T&, T*, KeyOfT, Hash>& rit)
		{
			it._node = rit.it._node;
			it._ht = rit.it._ht;
		}

		self operator++()
		{
			return --it;
		}

		self& operator--()
		{
			return ++it;
		}

		Ref operator*()
		{
			return it._node->_data;
		}

		Ptr operator->()
		{
			return it._node->_data;
		}

		bool operator!=(const self& rit)
		{
			return it._node != rit.it._node;
		}

		Iterator<K, T, Ref, Ptr, KeyOfT, Hash> it;
	};

	template<class K, class T, class KeyOfT,class Hash = HashFunc<K>>
	class HashTable
	{
	public:

		typedef HashNode<T> Node;

		typedef Iterator<K, T, T&, T*, KeyOfT, Hash> iterator;
		typedef Iterator<K, T, const T&, const T*, KeyOfT, Hash> const_iterator;
		typedef ReverseIterator<K, T, T&, T*, KeyOfT, Hash> reverse_iterator;
		typedef ReverseIterator<K, T, const T&, const T*, KeyOfT, Hash> const_reverse_iterator;

		// 模板类友元，声明不需要默认参数
		template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
		friend struct Iterator;

	public:

		iterator begin()
		{
			Node* cur = nullptr;
			for (int i = 0; i < _tables.size(); i++)
			{
				cur = _tables[i];
				if (cur)
					break;
			}

			return iterator(cur, this);
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		const_iterator begin()const
		{
			Node* cur = nullptr;
			for (int i = 0; i < _tables.size(); i++)
			{
				cur = _tables[i];
				if (cur)
					break;
			}

			return const_iterator(cur, this);
		}

		const_iterator end()const
		{
			return const_iterator(nullptr, this);
		}


		reverse_iterator rbegin()
		{
			int hashi = _tables.size() - 1;
			while (_tables[hashi] == nullptr && hashi>=0)
			{
				hashi--;
			}
			if (hashi < 0)
				return reverse_iterator(nullptr, this);

			// 最后一个
			Node* cur = _tables[hashi];
			while (cur->_next)
				cur = cur->_next;
			return reverse_iterator(cur, this);
		}

		reverse_iterator rend()
		{
			return reverse_iterator(nullptr, this);
		}


		const_reverse_iterator rbegin()const
		{
			int hashi = _tables.size() - 1;
			while (_tables[hashi] == nullptr && hashi >= 0)
			{
				hashi--;
			}
			if (hashi < 0)
				return const_reverse_iterator(nullptr, this);

			// 最后一个
			Node* cur = _tables[hashi];
			while (cur->_next)
				cur = cur->_next;
			return const_reverse_iterator(cur, this);
		}

		const_reverse_iterator rend()const
		{
			return const_reverse_iterator(nullptr, this);
		}

		bool Erase(const K& key)
		{
			KeyOfT kot;
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}

			return false;
		}

		Node* Find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;

			Hash hash;
			KeyOfT kot;
			size_t hashi = hash(key) % _tables.size();

			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
					return cur;
				cur = cur->_next;
			}
			return nullptr;
		}


		size_t GetNextPrime(size_t prime)
		{
			// SGI
			static const int __stl_num_primes = 28;
			static const unsigned long __stl_prime_list[__stl_num_primes] =
			{
				53, 97, 193, 389, 769,
				1543, 3079, 6151, 12289, 24593,
				49157, 98317, 196613, 393241, 786433,
				1572869, 3145739, 6291469, 12582917, 25165843,
				50331653, 100663319, 201326611, 402653189, 805306457,
				1610612741, 3221225473, 4294967291
			};

			size_t i = 0;
			for (; i < __stl_num_primes; ++i)
			{
				if (__stl_prime_list[i] > prime)
					return __stl_prime_list[i];
			}

			return __stl_prime_list[i];
		}

		pair<iterator,bool> insert(const T& data)
		{
			KeyOfT kot;
			Node* findnode = Find(kot(data));
			if (findnode)
				return make_pair(iterator(findnode, this), false);

			Hash hash;

			if (_tables.size() == n)
			{
				//size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;

				size_t newsize = GetNextPrime(_tables.size());

				vector<Node*> newtables(newsize, nullptr);
				for (auto& cur : _tables)
				{
					while (cur) // 链表节点全部插入newht
					{
						Node* next = cur->_next;
						size_t newhashi = hash(kot(cur->_data)) % newsize;

						cur->_next = newtables[newhashi];
						newtables[newhashi] = cur;

						cur = next;
					}
				}

				_tables.swap(newtables);
			}

			size_t hashi = hash(kot(data)) % _tables.size();
			Node* tmp = new Node(data);
			tmp->_next = _tables[hashi];
			_tables[hashi] = tmp;

			++n;
			return make_pair(iterator(tmp,this),true);

		}


		size_t MaxBucketSize()
		{
			int size = _tables.size();
			size_t max = 0;
			for (int i = 0; i < size; i++)
			{
				size_t tmp = 0;
				Node* cur = _tables[i];
				while (cur)
				{
					tmp++;
					cur = cur->_next;
				}

				if (tmp > max)
					max = tmp;
			}

			return max;
		}

	private:
		vector<HashNode<T>*> _tables;
		size_t n = 0; // vector 存储有效数据个数
	};

}