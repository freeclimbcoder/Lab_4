#pragma once
#include <iostream>
#include <fstream>
#include "BT.h"

using namespace std;

namespace BT1
{

	inline binTree Create()
	{	
		return NULL;
	}
//-------------------------------------
	inline bool isNull(binTree b)
	{	
		return (b == NULL);
	}
//-------------------------------------
	inline base RootBT (binTree b)			// для непустого бин.дерева
	{	
		if (b == NULL) { cerr << "Error: RootBT(null) \n"; exit(1); }
		else return b->data;
	}
//-------------------------------------	
	inline binTree Left1 (binTree b)		// для непустого бин.дерева
	{	
		if (b == NULL) { cerr << "Error: Left(null) \n"; exit(1); }
		else return b ->leftPtr;
	}
//-------------------------------------	
	inline binTree Right1 (binTree b)		// для непустого бин.дерева
	{	
		if (b == NULL) { cerr << "Error: Right(null) \n"; exit(1); }
		else return b->rightPtr;
	}
//-------------------------------------		
	inline binTree ConsBT(const base &x, binTree &lst,  binTree &rst)
	{	
		binTree p;
		p = new Node();
		if ( p != NULL)	{ 	
			p ->data = x;
			p ->leftPtr = lst;
			p ->rightPtr = rst;
			return p;
		}
		else {cerr << "Memory not enough\n"; exit(1);}
	}
//-------------------------------------			
	inline void destroy (binTree &b)
	{	
		if (b != NULL)	{
			destroy (b->leftPtr);
			destroy (b->rightPtr);
			delete b;
			b = NULL;
		}
	}
	
	inline binTree enterBT (ifstream& in)
	{	
		char ch;
		binTree p, q;
		in>>ch;
		if (ch=='/') return NULL;
		else {p = enterBT(in); q = enterBT(in); return ConsBT(ch, p, q);}
	}

	inline bool search (const base x, binTree b, bool &f)
	{	
	if(b != NULL)
		  {
			if(x == b->data)
			
			 f=true;
			
			else 
			   search(x, b->leftPtr,f);
			   search(x, b->rightPtr,f);
		  }
	return f;
	}
 

}
