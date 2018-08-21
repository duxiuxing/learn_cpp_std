#include "gtest/gtest.h"

#include <vector>

/*
    TestedMethod: vector::assign()
    Description: Erases a vector and copies the specified elements to the empty vector.
*/
TEST(vector_test, assign) {
    using namespace std;
    vector<int> v1, v2, v3;

    {
        v1.push_back(10);
        v1.push_back(20);
        v1.push_back(30);
        v1.push_back(40);
        v1.push_back(50);

        int expect_array[] = { 10, 20, 30, 40, 50 };
        int index = 0;
        for (auto& v : v1) {
            EXPECT_EQ(expect_array[index], v);
            ++index;
        }
    }

    {
        // template <class InputIterator>
        // void assign(InputIterator First, InputIterator Last);
        v2.assign(v1.begin(), v1.end());

        int expect_array[] = { 10, 20, 30, 40, 50 };
        int index = 0;
        for (auto& v : v2) {
            EXPECT_EQ(expect_array[index], v);
            ++index;
        }
    }

    {
        // void assign(size_type Count, const Type& Val);
        v3.assign(7, 4);

        EXPECT_EQ(7, v3.size());
        for (auto& v : v3) {
            EXPECT_EQ(4, v);
        }
    }

    {
        // void assign(initializer_list<Type> IList);
        v3.assign({ 10, 20, 30, 40, 50 });

        int expect_array[] = { 10, 20, 30, 40, 50 };
        int index = 0;
        for (auto& v : v3) {
            EXPECT_EQ(expect_array[index], v);
            ++index;
        }
    }
}

/*
    TestedMethod: vector::at()
    Description: Returns a reference to the element at a specified location in the vector.
*/
TEST(vector_test, at) {
    using namespace std;
    vector <int> v1;

    v1.push_back(10);
    v1.push_back(20);

    const int& i = v1.at(0);
    int& j = v1.at(1);

    EXPECT_EQ(10, i);
    EXPECT_EQ(20, j);
}

/*
    TestedMethod: vector::back()
    Description: Returns a reference to the last element of the vector.
*/
TEST(vector_test, back) {
    using namespace std;
    vector <int> v1;

    v1.push_back(10);
    v1.push_back(11);

    int& i = v1.back();
    const int& ii = v1.front();

    EXPECT_EQ(11, i);
    EXPECT_EQ(10, ii);
}

/*
    TestedMethod: vector::begin()
    Description: Returns a random-access iterator to the first element in the vector.
*/
TEST(vector_test, begin) {
    using namespace std;
    vector<int> c1;

    c1.push_back(1);
    c1.push_back(2);

    {
        int expect_array[] = { 1, 2 };
        int index = 0;

        vector<int>::iterator c1_Iter = c1.begin();
        for (; c1_Iter != c1.end(); c1_Iter++) {
            EXPECT_EQ(expect_array[index], *c1_Iter);
            ++index;
        }
    }

    {
        int expect_array[] = { 20, 2 };
        int index = 0;

        vector<int>::iterator c1_Iter = c1.begin();
        *c1_Iter = 20;
        for (; c1_Iter != c1.end(); c1_Iter++) {
            EXPECT_EQ(expect_array[index], *c1_Iter);
            ++index;
        }
    }
}

/*
    TestedMethod: vector::capacity()
    Description: Returns the number of elements that the vector could contain without allocating more storage.
    Output: 每次新增当前空间的1/2
*/
TEST(vector_test, capacity) {
    using namespace std;
    vector <int> v1;

    v1.push_back(1);
    EXPECT_EQ(1, v1.capacity());

    v1.push_back(2);
    EXPECT_EQ(2, v1.capacity());

    v1.push_back(3);
    EXPECT_EQ(3, v1.capacity());

    v1.push_back(4);
    EXPECT_EQ(4, v1.capacity());

    v1.push_back(5);
    EXPECT_EQ(6, v1.capacity());

    v1.push_back(6);
    EXPECT_EQ(6, v1.capacity());

    v1.push_back(7);
    EXPECT_EQ(9, v1.capacity());

    v1.push_back(8);
    EXPECT_EQ(9, v1.capacity());

    v1.push_back(9);
    EXPECT_EQ(9, v1.capacity());

    v1.push_back(10);
    EXPECT_EQ(13, v1.capacity());
}

/*
    TestedMethod: vector::()
    Description:
*/
TEST(vector_test, xx) {
}
