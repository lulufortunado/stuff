/*
 * heap-test.cpp
 *
 * COMP15
 * Spring 2018
 *
 * Basic operations to test out 
 * the maxHeap and minHeap classes
 */

#include <iostream>
#include "Patient.h"
#include "MinHeap.h"
#include "MaxHeap.h"
using namespace std;

void test_insert(Heap<int> *);
void test_insert_people(Heap<Patient> *, bool);
void test_extract(Heap<int> *);
void test_extract_people(Heap<Patient> *);
void test_empty_heap(Heap<int> *);

int main()
{
    Heap<int> *max = new MaxHeap<int>;
    Heap<Patient> *max2 = new MaxHeap<Patient>;
    Heap<Patient> *min = new MinHeap<Patient>;
    test_insert(max);
    test_extract(max);
    test_empty_heap(max);

    cout << endl << "Test of patient insert of MAXHEAP:\n";
    
    test_insert_people(max2, true);
    
    cout << "Check is by brute force. The above printout should be \n";
    cout << "in the order of a max heap where the highest priority is 5\n";
    cout << "at the top with smallest time_in, and then the greater the\n";
    cout << "time_in the lower down the tree is should be, only by\n";
    cout << "comparison to parent\n" << endl;

    cout << endl << "Test of patient insert of MINHEAP:\n";

    test_insert_people(min, false);

    cout << "Check is by brute force. The above printout should be \n";
    cout << "in the order of a min heap where the highest priority is 1\n";
    cout << "at the top with smallest time_in, and then the greater the\n";
    cout << "time_in the lower down the tree is should be, only by\n";
    cout << "comparison to parent\n" << endl;

    cout << endl << "Test of patient extract of MAXHEAP:\n";
    
    test_extract_people(max2);

    cout << "Check is by brute force. The above printout should be \n";
    cout << "in order of priority first (highest 5, lowest 1), \n";
    cout << "then time in, with smallest time_in first (highest priority)\n" ;

    cout << endl << "Test of patient extract of MINHEAP:\n";
    
    test_extract_people(min);

    cout << "Check is by brute force. The above printout should be \n";
    cout << "in order of priority first (highest 1, lowest 5), \n";
    cout << "then time in, with smallest time_in first (highest priority)\n" ;

    delete max;
    delete max2;
    delete min;
    return 0;
}

void test_insert_people(Heap<Patient> *mheap, bool ismax)
{
    Patient p1("A1", "A1");
    Patient p2("A2", "A2");
    Patient p3("A3", "A3");
    Patient p4("A4", "A4");
    Patient p5("A5", "A5");
    Patient p6("A6", "A6");
    Patient p7("A7", "A7");
    Patient p8("A8", "A8");
    Patient p9("A9", "A9");
    Patient p10("A10", "A10");
    Patient p11("A11", "A11");
    Patient p12("A12", "A12");
    Patient p13("A13", "A13");
    Patient p14("A14", "A14");
    //params: bool chestpainIn, bool headwoundIn, 
    //            double tempIn, unsigned pulseIn, int timeinIn, bool ismaxIn
    p1.calculate_priority(true, true, 100, 80, 14, ismax);
    p2.calculate_priority(false, false, 100, 80, 20, ismax);
    p3.calculate_priority(true, false, 100, 80, 13, ismax);
    p4.calculate_priority(false, false, 85.8, 100, 100, ismax);
    p5.calculate_priority(false, false, 100, 80, 4, ismax);
    p6.calculate_priority(false, true, 88, 50, 4, ismax);
    p7.calculate_priority(false, true, 88, 100, 1, ismax);
    p8.calculate_priority(false, true, 88, 100, 22, ismax);
    p9.calculate_priority(false, true, 300, 100, 13, ismax);
    p10.calculate_priority(true, true, 85.8, 100, 109, ismax);
    p11.calculate_priority(false, false, 85.8, 100, 90, ismax);
    p12.calculate_priority(true, true, 100, 80, 2, ismax);
    p13.calculate_priority(false, false, 100, 100, 12, ismax);
    p14.calculate_priority(true, true, 100, 80, 14, ismax);

    mheap->insert_item(p1);
    mheap->insert_item(p2);
    mheap->insert_item(p3);
    mheap->insert_item(p4);
    mheap->insert_item(p5);
    mheap->insert_item(p6);
    mheap->insert_item(p7);
    mheap->insert_item(p8);
    mheap->insert_item(p9);
    mheap->insert_item(p10);
    mheap->insert_item(p11);
    mheap->insert_item(p12);
    mheap->insert_item(p13);
    mheap->insert_item(p14);

    cout << "print the heap: \n\n";
    mheap->print_with_time_in();
}

void test_insert(Heap<int> *max)
{
    int result;

    try
    {
        max->insert_item(5);
    }
    catch (FullHeap exception)
    {
        cout << "Insert FAIL\n";
        cout << exception.what() << endl;
        return;
    }

    try
    {
        result = max->get_value_at(0);
    }
    catch (EmptyHeap exception)
    {
        cout << "Insert FAIL\n";
        cout << exception.what() << endl;
        return;
    }

    if (result == 5)
        cout << "Test insert (one node) SUCCESS\n";
    else
        cout << "Test insert (one node) FAIL\n";

    max->insert_item(5);

    if (max->get_value_at(0) == 5 && max->get_value_at(1) == 5)
        cout << "Test insert (duplicate) SUCCESS\n";
    else
        cout << "Test insert (duplicate) FAIL\n";

    max->insert_item(6);
    max->insert_item(3);
    max->insert_item(7);
    max->insert_item(12);
    max->insert_item(0);
    max->insert_item(7);
    max->insert_item(10);
    max->insert_item(2);
    max->insert_item(1);
    max->insert_item(0);
    max->insert_item(6);
    max->insert_item(8);
    max->insert_item(9);

    if (max->get_value_at(0) == 12)
        cout << "Test insert (15 nodes, index 0) SUCCESS\n";
    else
        cout << "Test insert (15 nodes, index 0) FAIL\n";

    if (max->get_value_at(1) == 10)
        cout << "Test insert (15 nodes, index 1) SUCCESS\n";
    else
        cout << "Test insert (15 nodes, index 1) FAIL\n";

    if (max->get_value_at(2) == 9)
        cout << "Test insert (15 nodes, index 2) SUCCESS\n";
    else
        cout << "Test insert (15 nodes, index 2) FAIL\n";

    if (max->get_value_at(3) == 7)
        cout << "Test insert (15 nodes, index 3) SUCCESS\n";
    else
        cout << "Test insert (15 nodes, index 3) FAIL\n";

    if (max->get_value_at(4) == 5)
        cout << "Test insert (15 nodes, index 4) SUCCESS\n";
    else
        cout << "Test insert (15 nodes, index 4) FAIL\n";

    if (max->get_value_at(5) == 6)
        cout << "Test insert (15 nodes, index 5) SUCCESS\n";
    else
        cout << "Test insert (15 nodes, index 5) FAIL\n";

    if (max->get_value_at(6) == 8)
        cout << "Test insert (15 nodes, index 6) SUCCESS\n";
    else
        cout << "Test insert (15 nodes, index 6) FAIL\n";

    if (max->get_value_at(7) == 3)
        cout << "Test insert (15 nodes, index 7) SUCCESS\n";
    else
        cout << "Test insert (15 nodes, index 7) FAIL\n";

    if (max->get_value_at(8) == 6)
        cout << "Test insert (15 nodes, index 8) SUCCESS\n";
    else
        cout << "Test insert (15 nodes, index 8) FAIL\n";

    if (max->get_value_at(9) == 2)
        cout << "Test insert (15 nodes, index 9) SUCCESS\n";
    else
        cout << "Test insert (15 nodes, index 9) FAIL\n";

    if (max->get_value_at(10) == 1)
        cout << "Test insert (15 nodes, index 10) SUCCESS\n";
    else
        cout << "Test insert (15 nodes, index 10) FAIL\n";

    if (max->get_value_at(11) == 0)
        cout << "Test insert (15 nodes, index 11) SUCCESS\n";
    else
        cout << "Test insert (15 nodes, index 11) FAIL\n";

    if (max->get_value_at(12) == 5)
        cout << "Test insert (15 nodes, index 12) SUCCESS\n";
    else
        cout << "Test insert (15 nodes, index 12) FAIL\n";

    if (max->get_value_at(13) == 0)
        cout << "Test insert (15 nodes, index 13) SUCCESS\n";
    else
        cout << "Test insert (15 nodes, index 13) FAIL\n";

    if (max->get_value_at(14) == 7)
        cout << "Test insert (15 nodes, index 14) SUCCESS\n";
    else
        cout << "Test insert (15 nodes, index 14) FAIL\n";

    cout << "print the heap: \n";
    max->print();
}

void test_extract_people(Heap<Patient> *max)
{
     cout << "in test_extract_people: \n\n";
     for (int i = 0; i < 14; i++)
     {   
        max->extract().print_with_time_in(cout);
        cout << endl;
    }

}

void test_extract(Heap<int> *max)
{
    int extracted;
    try
    { 
        extracted = max->extract();
    }
    catch (EmptyHeap exception)
    {
        cout << "Test extract FAIL\n";
        cout << exception.what() << endl;
        return;
    }

    if (extracted == 12)
    {
        cout << "First extract SUCCESSS\n";
    }
   
    else
    {
        cout << "First extract FAIL\n";
        cout << "Expected 12, extracted " << extracted << endl;
    }

    if (max->extract() == 10)
        {
            cout << "Second extract SUCCESS\n";
        }
    else
        {
            cout << "Second extract FAIL\n";
        }

    if (max->extract() == 9)
        {
            cout << "Third extract SUCCESS\n";
        }
    else
        {
            cout << "Third extract FAIL\n";
        }

    if (max->extract() == 8)
        {
            cout << "Fourth extract SUCCESS\n";
        }
    else
        {
            cout << "Fourth extract FAIL\n";
        }

    if (max->extract() == 7)
        {
            cout << "Fifth extract SUCCESS\n";
        }
    else
        {
            cout << "Fifth extract FAIL\n";
        }
    if (max->extract() == 7)
        {
            cout << "Sixth extract SUCCESS\n";
        }
    else
        {
            cout << "Sixth extract FAIL\n";
        }
    if (max->extract() == 7)
        {
            cout << "Seventh extract SUCCESS\n";
        }
    else
        {
            cout << "Seventh extract FAIL\n";
        }
    if (max->extract() == 6)
        {
            cout << "Eighth extract SUCCESS\n";
        }
    else
        {
            cout << "Eighth extract FAIL\n";
        }
    if (max->extract() == 6)
        {
            cout << "Ninth extract SUCCESS\n";
        }
    else
        {
            cout << "Ninth extract FAIL\n";
        }
    if (max->extract() == 5)
        {
            cout << "Tenth extract SUCCESS\n";
        }
    else
        {
            cout << "Tenth extract FAIL\n";
        }
    if (max->extract() == 5)
        {
            cout << "Eleventh extract SUCCESS\n";
        }
    else
        {
            cout << "Eleventh extract FAIL\n";
        }
    if (max->extract() == 5)
        {
            cout << "Twelfth extract SUCCESS\n";
        }
    else
        {
            cout << "Twelfth extract FAIL\n";
        }
    if (max->extract() == 3)
        {
            cout << "Thirteenth extract SUCCESS\n";
        }
    else
        {
            cout << "Thirteenth extract FAIL\n";
        }
    if (max->extract() == 2)
        {
            cout << "Fourteenth extract SUCCESS\n";
        }
    else
        {
            cout << "Fourteenth extract FAIL\n";
        }
     if (max->extract() == 1)
        {
            cout << "Fifteenth extract SUCCESS\n";
        }
    else
        {
            cout << "Fifteenth extract FAIL\n";
        }
}

void test_empty_heap(Heap<int> *max)
{
    try
    {
        max->extract();
        cout << "Test empty FAIL\n";
    }
    catch (EmptyHeap exception)
    {
        cout << "Test empty SUCCESS\n";
    }
}



