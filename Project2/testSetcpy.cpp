//
//  testSetcpy.cpp
//  Project2
//
//  Created by christopher kha on 1/28/19.
//  Copyright © 2019 christopher kha. All rights reserved.
//


#include "Set.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    //strings

    Set ss;
    ss.insert("lavash");
    ss.insert("roti");
    ss.insert("chapati");
    ss.insert("injera");
    ss.insert("roti");
    ss.insert("matzo");
    ss.insert("injera");
    assert(ss.size() == 5);  // duplicate "roti" and "injera" were not added
    string x;
    ss.get(0, x);
    assert(x == "chapati");  // "chapati" is greater than exactly 0 items in ss
    ss.get(4, x);
    assert(x == "roti");  // "roti" is greater than exactly 4 items in ss
    ss.get(2, x);
    assert(x == "lavash");  // "lavash" is greater than exactly 2 items in ss

    Set ss1;
    ss1.insert("laobing");
    Set ss2;
    ss2.insert("matzo");
    ss2.insert("pita");
    ss1.swap(ss2);
    assert(ss1.size() == 2  &&  ss1.contains("matzo")  &&  ss1.contains("pita")  &&
           ss2.size() == 1  &&  ss2.contains("laobing"));

    Set ss3;
    ss3.insert("dosa");
    assert(!ss3.contains(""));
    ss3.insert("tortilla");
    ss3.insert("");
    ss3.insert("focaccia");
    assert(ss3.contains(""));
    ss3.erase("dosa");
    assert(ss3.size() == 3  &&  ss3.contains("focaccia")  &&  ss3.contains("tortilla")  &&
           ss3.contains(""));
    string v;
    assert(ss3.get(1, v)  &&  v == "focaccia");
    assert(ss3.get(0, v)  &&  v == "");


    //empty()
    Set s;
    assert(s.empty());
    assert(s.size() == 0);

    //insert()
    s.insert("a");
    s.insert("b");
    assert(!s.insert("a") && s.size() == 2);        // inserting duplicates

    //    assert(!s.insert("b") && s.size() == 2);    // max num of items in set (changed DEFAULT_MAX_ITEMS =2)

    assert(s.erase("a") && s.size() == 1);
    //    s.dump();
    assert(!s.erase("a") && s.size() == 1);     // erase() value not found


    s.insert("c");
    s.insert("e");
    s.insert("d");
    s.insert("f");
    s.insert("g");
    s.insert("h");

    //contains()
    assert(!s.contains("C"));
    assert(s.contains("h"));
    assert(s.contains("f"));
    assert(!s.contains("H"));

    // get()
    ItemType y = "why";
    assert(!s.get(7, y) && y == "why");   // range must be ( 0 <= n < m_nItems )
    assert(!s.get(-1, y) && y == "why");
    assert(!s.get(8, y) && y == "why");

    assert(s.get(0, y) && y == "b");     // first item
    assert(s.get(6, y) && y == "h");     // last item

    // get()
    Set s1;
    assert(s1.empty());
    ItemType z = "arepa";
    assert( !s1.get(42, z)  &&  z == "arepa"); // x unchanged by get failure
    s1.insert("chapati");
    s1.dump();
    assert(s1.size() == 1);
    assert(s1.get(0, z)  &&  z == "chapati");


    //unsigned longs
    /*
     //empty()
     Set s0;
     assert(s0.empty());
     assert(s0.size() == 0);

     //insert()
     s0.insert(0);
     s0.insert(1);
     assert(!s0.insert(0) && s0.size() == 2);        // inserting duplicates

     //    assert(!s0.insert(2) && s0.size() == 2);    // max num of items in set (changed DEFAULT_MAX_ITEMS =2)

     assert(s0.erase(0) && s0.size() == 1);
     s0.dump();
     assert(!s0.erase(0) && s0.size() == 1);     // erase() value not found


     s0.insert(2);
     s0.insert(3);
     s0.insert(4);
     s0.insert(5);
     s0.insert(6);
     s0.insert(7);

     //contains()
     assert(!s0.contains(0));
     assert(s0.contains(7));
     assert(s0.contains(5));
     assert(!s0.contains(8));

     // get()
     ItemType y = 10;
     assert(!s0.get(7, y) && y == 10);   // range must be ( 0 <= n < m_nItems )
     assert(!s0.get(-1, y) && y == 10);
     assert(!s0.get(8, y) && y == 10);

     assert(s0.get(0, y) && y == 1);     // first item
     assert(s0.get(6, y) && y == 7);     // last item

     // get()
     Set s;
     assert(s.empty());
     ItemType x = 9876543;
     assert( !s.get(42, x)  &&  x == 9876543); // x unchanged by get failure
     s.insert(123456789);
     assert(s.size() == 1);
     assert(s.get(0, x)  &&  x == 123456789);

    */

    cerr << "Passed all tests" << endl;
}

