#pragma once

namespace BList
{
	struct Node
	{
		struct Node* prev;
		struct Node* next;
		int val;
	};

	int m;

	namespace B
	{
		int x;
	}
}