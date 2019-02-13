//
//  main.cpp
//  Project2
//
//  Created by christopher kha on 1/24/19.
//  Copyright © 2019 christopher kha. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "Set.h"

using namespace std;


//void test()
//{
//    Set uls;
//    assert(uls.insert(10));
//    assert(uls.insert(20));
//    assert(uls.size() == 2);
//    assert(uls.contains(20));
//    ItemType x = 30;
//    assert(uls.get(0, x)  &&  x == 10);
//    assert(uls.get(1, x)  &&  x == 20);
//}

int main() {
//    test();
    
    Set s;
    assert(s.size() == 0);
    assert(!s.erase("s"));
    
    // insert()
    assert(s.insert("how"));                // insert to empty Set
    assert(s.insert("wow"));                // insert to end
    assert(s.insert("a2"));                 // insert to front
    assert(s.insert("bow"));                // insert to middle
    
    assert(s.size() == 4);          // size()
    assert(!s.insert("a2") && s.size() == 4);   // attempt to insert duplicate
    
    // erase()
    assert(s.erase("a2") && s.size() == 3);     // remove from front
    assert(!s.erase("a2") && s.size() == 3);    // nothing to remove
    assert(s.erase("how") && s.size() == 2);    // remove from middle
    assert(s.erase("wow") && s.size() == 1);    // remove from end
    assert(!s.contains("wow"));
    
    s.dump();
    
    // get()
    Set s2;
    ItemType val = "";
    
    s2.insert("y");                         // insert to front multiple times
    s2.insert("m");
    s2.insert("c");
    s2.insert("a");

    assert(!s2.get(-1, val) && val == "");      // pos less than 0
    assert(!s2.get(4, val) && val == "");       // pos equal to m_size
    assert(!s2.get(5, val) && val == "");       // pos greater than m_size
    
    assert(s2.get(0, val) && val == "a");       // getting the value at each position
    assert(s2.get(1, val) && val == "c");
    assert(s2.get(2, val) && val == "m");
    assert(s2.get(3, val) && val == "y");
    
    s2.dump();
    
    // swap()
    s.swap(s2);                     // swap two Sets
    assert(s.contains("y") && s.contains("m") && s.contains("c") && s.contains("a") && s.size() == 4);
    assert(s2.contains("bow") && s2.size() == 1);
    
    Set s3;                         // swap an empty Set
    s3.swap(s2);
    assert(s2.empty());
    assert(s3.contains("bow") && s3.size() == 1);
    
    // copy constructor
    if(true){
        Set s4 = s3;
        s4.dump();
        assert(s4.contains("bow") && s4.size() == 1);
        
        Set s5 = s2;            // copying an empty set
        assert(s5.empty());
    }
    // destructor
    assert(s3.contains("bow") && s3.size() == 1);     // s3's linked list isn't deleted when s4 is destructed
    
    // assignment operator
    Set s6;
    Set s7;
    s6.insert("yes");
    s6.insert("or");
    s6.insert("no");
    
    s7.insert("why");
    s7.insert("not");
    
    s7 = s6;        // make a copy of s6
    s7.dump();
    
    assert(s7.contains("yes") && s7.size() == 3);
    
    // unite()
    Set s8;
    Set s9;
    Set s10;
    
    s8.insert("a");
    s8.insert("b");
    s8.insert("c");
    s9.insert("c");
    s9.insert("d");
    s9.insert("e");
    
    unite(s8, s9, s10);         // s10 should contain "a", "b", "c", "d", "e"
    assert(s10.contains("a") && s10.contains("b") && s10.contains("c")
           && s10.contains("d") && s10.contains("e") && s10.size() == 5);
    
    unite(s8, s9, s8);          // s1 and result are aliases
    assert(s8.contains("a") && s8.contains("b") && s8.contains("c")
           && s8.contains("d") && s8.contains("e") && s8.size() == 5);
    
    s8.insert("f");
    unite(s8, s9, s9);          // s2 and result are aliases
    assert(s9.contains("a") && s9.contains("b") && s9.contains("c")
           && s9.contains("d") && s9.contains("e") && s9.contains("f") && s9.size() == 6);
    s9.dump();
    
    Set s11;
    Set s12;
    unite(s11, s9, s12);    // s1 is empty
    assert(s12.contains("a") && s12.contains("b") && s12.contains("c")
           && s12.contains("d") && s12.contains("e") && s12.contains("f") && s12.size() == 6);
    
    
    // subtract()
    Set s13;
    Set s14;
    Set s15;
    Set s16;
    
    s13.insert("a");
    s13.insert("b");
    s13.insert("c");
    s14.insert("b");
    s14.insert("c");
    s14.insert("d");
    s14.insert("e");
    
    subtract(s13, s14, s15);                // subtract
    assert(s15.contains("a") && s15.size() == 1);
    
    subtract(s16, s14, s15);                // s1 is empty
    assert(s15.empty());
    
    subtract(s13, s16, s15);                // s2 is empty
    assert(s15.contains("a") && s15.contains("b") && s15.contains("c") && s15.size() == 3);
    
    subtract(s13, s14, s13);                // s1 and result are aliases
    assert(s13.contains("a") && s13.size() == 1);
    
    s13.insert("b");
    s13.insert("c");
    
    subtract(s13, s14, s14);                // s2 and result are aliases
    assert(s14.contains("a") && s14.size() == 1);
    
    cerr << "All tests passed!" << endl;
}
