#pragma once
#include<iostream>
#include<vector>

using namespace std;

namespace OpenAddress
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	template<class K, class V>
	class HashTable
	{
	public:

		bool insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;

			if (_tables.size() == 0 || _n * 10 / _tables.size() > 7)
			{
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V> newht;
				newht._tables.resize(newsize);
				for (auto& s : _tables)
				{
					newht.insert(s._kv);
				}

				_tables.swap(newht._tables);
			}

			size_t hashi = kv.first % _tables.size();

			size_t i = 1;
			size_t index = hashi;
			while (_tables[index]._state == EXIST)
			{
				index = hashi + i;
				index %= _tables.size();
				++i;
			}

			_tables[index]._kv = kv;
			_tables[index]._state = EXIST;
			_n++;

			return true;
		}


		HashData<K,V>* Find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;

			size_t hashi = key % _tables.size();

			size_t i = 1;
			size_t pos = hashi;
			while (_tables[pos]._state != EMPTY)
			{
				if (_tables[pos]._kv.first == key && _tables[pos]._state == EXIST)
				{
					return &_tables[pos];
				}

				pos += hashi + i;
				pos %= _tables.size();
				++i;

				if (pos == hashi)
				{
					break;
				}
			}

			return nullptr;

		}
		
		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = EMPTY;
				--_n;
				return true;
			}
			else
			{
				return false;
			}
		}
		

	private:
		vector<HashData<K,V>> _tables;
		size_t _n = 0;// 存储数据的个数
	};


}



namespace HashBucket
{
	template<class K, class V>
	struct HashNode
	{
		HashNode<K, V>* _next;
		pair<K, V> _kv;

		HashNode(const pair<K,V> &kv)
			:_next(nullptr)
			,_kv(kv)
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


	template<class K,class V,class Hash = HashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:


		bool Erase(const K& key)
		{
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* cur= _tables[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if (cur->_kv.first == key)
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
			size_t hashi = hash(key) % _tables.size();
			
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
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

		bool insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;

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
						size_t newhashi = hash(cur->_kv.first) % newsize;
						
						cur->_next = newtables[newhashi];
						newtables[newhashi] = cur;

						cur = next;
					}
				}

				_tables.swap(newtables);
			}

			size_t hashi = hash(kv.first) % _tables.size();
			Node* tmp = new Node(kv);
			tmp->_next = _tables[hashi];
			_tables[hashi] = tmp;

			++n;
			return true;

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
		vector<HashNode<K, V>*> _tables;
		size_t n = 0; // vector 存储有效数据个数
	};

}