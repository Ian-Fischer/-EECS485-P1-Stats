/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

void test_sum_small_data_set();
void test_count();
void test_sum();
void test_mean();
void test_median();
void test_mode();
void test_stdev();
void test_percentile();
void test_summarize();

// Add prototypes for you test functions here.

int main()
{
  test_sum_small_data_set();
    test_count();
    test_sum();
    test_mean();
    test_mode();
    test_stdev();
    test_percentile();
    test_summarize();
  // Call your test functions here

  return 0;
}

void test_sum_small_data_set()
{
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "PASS!" << endl;
}

void test_count() {
    cout << "Now testing count function" << endl;
    vector<double> test1;
    test1.push_back(1);
    test1.push_back(2);
    test1.push_back(3);
    test1.push_back(4);
    test1.push_back(5);
    test1.push_back(6);
    
    vector<double> test2;
    test2.push_back(5);
    test2.push_back(2);
    test2.push_back(11);
    test2.push_back(33);
    test2.push_back(1);

    vector<double> test3;
    test3.push_back(5);
    test3.push_back(2);
    test3.push_back(11);
    test3.push_back(33);
    test3.push_back(11);
    test3.push_back(1);
    test3.push_back(11);
    test3.push_back(33);
    test3.push_back(33);
    test3.push_back(33);
    test3.push_back(5);
    test3.push_back(1);
    
    cout << "Expecting 6. Actual: " << count(test1) << endl;
    cout << "Expecting 5. Actual: " << count(test2) << endl;
    cout << "Expecting 12. Actual: " << count(test3) << endl;
}
void test_summarize() {
    cout << "Now testing summarize function" << endl;
    vector<double> test1;
    test1.push_back(1);
    test1.push_back(2);
    test1.push_back(3);
    test1.push_back(4);
    test1.push_back(5);
    test1.push_back(6);
    
    vector<double> test2;
    test2.push_back(5);
    test2.push_back(2);
    test2.push_back(11);
    test2.push_back(33);
    test2.push_back(1);

    vector<double> test3;
    test3.push_back(5);
    test3.push_back(2);
    test3.push_back(11);
    test3.push_back(33);
    test3.push_back(11);
    test3.push_back(1);
    test3.push_back(11);
    test3.push_back(33);
    test3.push_back(33);
    test3.push_back(33);
    test3.push_back(5);
    test3.push_back(1);
    
    cout << "Expecting 6. Actual: " << endl;
    vector<vector<double>> info1 = summarize(test1);
    cout << "Expecting 5. Actual: " << endl;
     vector<vector<double>> info2 = summarize(test2);
    cout << "Expecting 12. Actual: " << endl;
     vector<vector<double>> info3 = summarize(test3);
}


void test_sum() {
    cout << "Now testing sum function" << endl;
    vector<double> test1;
    test1.push_back(1);
    test1.push_back(2);
    test1.push_back(3);
    test1.push_back(4);
    test1.push_back(5);
    test1.push_back(6);
    
    vector<double> test2;
    test2.push_back(5);
    test2.push_back(2);
    test2.push_back(11);
    test2.push_back(33);
    test2.push_back(1);

    vector<double> test3;
    test3.push_back(5);
    test3.push_back(2);
    test3.push_back(11);
    test3.push_back(33);
    test3.push_back(11);
    test3.push_back(1);
    test3.push_back(11);
    test3.push_back(33);
    test3.push_back(33);
    test3.push_back(33);
    test3.push_back(5);
    test3.push_back(1);
    
    cout << "Expecting 21. Actual: " << sum(test1) << endl;
    cout << "Expecting 52. Actual: " << sum(test2) << endl;
    cout << "Expecting 179. Actual: " << sum(test3) << endl;
}

void test_mean() {
    cout << "Now testing mean function" << endl;
    vector<double> test1;
    test1.push_back(1);
    test1.push_back(2);
    test1.push_back(3);
    test1.push_back(4);
    test1.push_back(5);
    test1.push_back(6);
    
    vector<double> test2;
    test2.push_back(5);
    test2.push_back(2);
    test2.push_back(11);
    test2.push_back(33);
    test2.push_back(1);

    vector<double> test3;
    test3.push_back(5);
    test3.push_back(2);
    test3.push_back(11);
    test3.push_back(33);
    test3.push_back(11);
    test3.push_back(1);
    test3.push_back(11);
    test3.push_back(33);
    test3.push_back(33);
    test3.push_back(33);
    test3.push_back(5);
    test3.push_back(1);
    
    cout << "Expecting 3.5. Actual: " << mean(test1) << endl;
    cout << "Expecting 10.4. Actual: " << mean(test2) << endl;
    cout << "Expecting 14.9167. Actual: " << mean(test3) << endl;
}

void test_mode() {
    cout << "Now testing mode function" << endl;
    vector<double> test1;
    test1.push_back(1);
    test1.push_back(1);
    test1.push_back(2);
    test1.push_back(2);
    test1.push_back(5);
    test1.push_back(6);
    
    vector<double> test2;
    test2.push_back(5);
    test2.push_back(2);
    test2.push_back(11);
    test2.push_back(33);
    test2.push_back(1);

    vector<double> test3;
    test3.push_back(5);
    test3.push_back(2);
    test3.push_back(11);
    test3.push_back(33);
    test3.push_back(11);
    test3.push_back(1);
    test3.push_back(11);
    test3.push_back(33);
    test3.push_back(33);
    test3.push_back(33);
    test3.push_back(5);
    test3.push_back(1);
    
    cout << "Expecting 1. Actual: " << mode(test1) << endl;
    cout << "Expecting 1. Actual: " << mode(test2) << endl;
    cout << "Expecting 33. Actual: " << mode(test3) << endl;
}

void test_stdev() {
    cout << "Now testing stdev function" << endl;
    vector<double> test1;
    test1.push_back(1);
    test1.push_back(2);
    test1.push_back(3);
    test1.push_back(4);
    test1.push_back(5);
    test1.push_back(6);
    
    vector<double> test2;
    test2.push_back(5);
    test2.push_back(2);
    test2.push_back(11);
    test2.push_back(33);
    test2.push_back(1);

    vector<double> test3;
    test3.push_back(5);
    test3.push_back(2);
    test3.push_back(11);
    test3.push_back(33);
    test3.push_back(11);
    test3.push_back(1);
    test3.push_back(11);
    test3.push_back(33);
    test3.push_back(33);
    test3.push_back(33);
    test3.push_back(5);
    test3.push_back(1);
    
    cout << "Expecting 1. Actual: " << stdev(test1) << endl;
    cout << "Expecting 1. Actual: " << stdev(test2) << endl;
    cout << "Expecting 33. Actual: " << stdev(test3) << endl;
}

void test_percentile() {
cout << "Now testing stdev function" << endl;
vector<double> test1;
test1.push_back(1);
test1.push_back(2);
test1.push_back(3);
test1.push_back(4);
test1.push_back(5);
test1.push_back(6);

vector<double> test2;
test2.push_back(5);
test2.push_back(2);
test2.push_back(11);
test2.push_back(33);
test2.push_back(1);

vector<double> test3;
test3.push_back(5);
test3.push_back(2);
test3.push_back(11);
test3.push_back(33);
test3.push_back(11);
test3.push_back(1);
test3.push_back(11);
test3.push_back(33);
test3.push_back(33);
test3.push_back(33);
test3.push_back(5);
test3.push_back(1);

    cout << "Expecting 3.5. Actual: " << percentile(test1, .5) << endl;
    cout << "Expecting 5. Actual: " << percentile(test2, .5) << endl;
    cout << "Expecting 33. Actual: " << percentile(test3, 1) << endl;
}
// Add the test function implementations here.
