// интерфейс "Бинарное дерево"
#pragma once
#include <fstream>

namespace BT1
{
		typedef char base;
		struct Node
		{
			Node *leftPtr; //указатель на левое поддерево
			Node *rightPtr; //указатель на правое поддерево 
			base data;
			int theX1, theY1;
			Node () {leftPtr = NULL; rightPtr = NULL;} //конструктор
		};
		typedef Node* binTree;

		inline binTree Create(void);
		inline bool isNull(binTree);
		inline base RootBT (binTree); // для непустого бин.дерева
		inline binTree Left1 (binTree);// для непустого бин.дерева
		inline binTree Right1 (binTree);// для непустого бин.дерева
		inline binTree ConsBT(const base &x, binTree &lst,  binTree &rst);
		inline void destroy (binTree&);
		inline binTree enterBT (std::ifstream& in);
		inline bool search (const base x, binTree b,bool &f);
		
}