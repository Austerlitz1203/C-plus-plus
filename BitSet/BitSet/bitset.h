#pragma once
#include<vector>
#include<string>

using namespace std;

template<size_t N>
class bitset
{
public:

	bitset()
	{
		_b.resize(N / 8 + 1, 0);
	}

	void set(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;

		_b[i] |= (1 << j);
	}

	void reset(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;
		_b[i] &= ~(1 << j);
	}

	bool test(size_t x)
	{
		size_t i = x / 8;
		size_t j = x % 8;
		return (1 << j) & _b[i];
	}


private:
	vector<char> _b;
};





struct BKDRHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			hash += ch;
			hash *= 31;
		}

		return hash;
	}
};

struct APHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (long i = 0; i < s.size(); i++)
		{
			size_t ch = s[i];
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};


struct DJBHash
{
	size_t operator()(const string& s)
	{
		size_t hash = 5381;
		for (auto ch : s)
		{
			hash += (hash << 5) + ch;
		}
		return hash;
	}
};


template<size_t N,
class K=string,
class Hash1=BKDRHash,
class Hash2=APHash,
class Hash3=DJBHash>
class BloomFilter
{
public:

	void set(const K& key)
	{
		size_t len = N * _x;
		size_t hash1 = Hash1()(key) % len;
		_bs.set(hash1);

		size_t hash2 = Hash2()(key) % len;
		_bs.set(hash2);

		size_t hash3 = Hash3()(key) % len;
		_bs.set(hash3);
	}

	bool test(const K& key)
	{
		size_t len = N * _x;

		// 只要有一个位置没有映射到，就是没有
		size_t hash1 = Hash1()(key) % len;
		if (!_bs.test(hash1))
		{
			return false;
		}

		size_t hash2 = Hash2()(key) % len;
		if (!_bs.test(hash2))
		{
			return false;
		}

		size_t hash3 = Hash3()(key) % len;
		if (!_bs.test(hash3))
		{
			return false;
		}

		return true;
	}


private:
	static const size_t _x = 5;
	bitset<N * _x> _bs;
};