#include "PeopleList.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
        
        int main()
        {
            PeopleList m;//create an empty list 
            string first,last; int a;
            assert(m.add("Fred", "Mertz", 52)); //test add
            assert(m.add("Ethel", "Mertz", 49));
            PeopleList n(m);//test copy constructor
            n=n;//test assignment operator
            assert(!n.empty() );//test empty
            assert(n.size() == 2);//test size
            assert( !n.change("M", "Lucy", 10) );//test change(nothing to change)
            assert( m.get(1, first, last, a)  && (first == "Fred"  &&  a == 52));//test get and order in PeopleLisst
            assert( m.remove("Fred", "Mertz")); //test remove
            m.swap(n); 
            assert(  m.get(1, first, last, a)  && (first == "Fred"  &&  a == 52));//test swap
            PeopleList result;
            assert( combine(n,m,result) && result.size()==2 ); //test combine        	
			psearch("Fred","*",m,result);
            assert(   result.size()==1 ); //test psearch
            psearch("Fred","*",m,m);
            assert(   result.size()==1 ); //test psearch aliasing
            cout << "Passed all tests" << endl;
        }
