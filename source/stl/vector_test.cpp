#include "gtest/gtest.h"

#include <vector>
using namespace std;

#define EXPECT_VECTOR_EQ(expect_array, actual_vector) \
    { \
        ASSERT_EQ(_countof(expect_array), actual_vector.size()); \
        for (unsigned int index = 0; index < actual_vector.size(); ++index) { \
            EXPECT_EQ(expect_array[index], actual_vector[index]) << "index = " << index; \
        } \
    }

/*
    TestedMethod: vector::assign()
    Description: Erases a vector and copies the specified elements to the empty vector.
*/
TEST(vector_test, assign) {
    vector<int> v1;

    {
        v1.push_back(10);
        v1.push_back(20);
        v1.push_back(30);
        v1.push_back(40);
        v1.push_back(50);

        int array[] = { 10, 20, 30, 40, 50 };
        EXPECT_VECTOR_EQ(array, v1);
    }

    {
        // template <class InputIterator>
        // void assign(InputIterator First, InputIterator Last);
        vector<int> v2;
        v2.assign(v1.begin(), v1.end());

        int array[] = { 10, 20, 30, 40, 50 };
        EXPECT_VECTOR_EQ(array, v2);
    }

    vector<int> v3;
    {
        // void assign(size_type Count, const Type& Val);
        v3.assign(7, 4);

        int array[] = { 4, 4, 4, 4, 4, 4, 4 };
        EXPECT_VECTOR_EQ(array, v3);
    }

#if GTEST_LANG_CXX11
    {
        // void assign(initializer_list<Type> IList);
        v3.assign({ 10, 20, 30, 40, 50 });

        int array[] = { 10, 20, 30, 40, 50 };
        EXPECT_VECTOR_EQ(array, v3);
    }
#endif
}

/*
    TestedMethod: vector::at()
    Description: Returns a reference to the element at a specified location in the vector.
*/
TEST(vector_test, at) {
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
    vector<int> c1;

    c1.push_back(1);
    c1.push_back(2);

    {
        int array[] = { 1, 2 };
        int index = 0;

        vector<int>::iterator c1_Iter = c1.begin();
        for (; c1_Iter != c1.end(); c1_Iter++) {
            EXPECT_EQ(array[index], *c1_Iter);
            ++index;
        }
    }

    {
        int array[] = { 20, 2 };
        int index = 0;

        vector<int>::iterator c1_Iter = c1.begin();
        *c1_Iter = 20;
        for (; c1_Iter != c1.end(); c1_Iter++) {
            EXPECT_EQ(array[index], *c1_Iter);
            ++index;
        }
    }
}

/*
    TestedMethod: vector::capacity()
    Description: Returns the number of elements that the vector could contain without allocating more storage.
    Remark: 每次新增当前空间的1/2
*/
TEST(vector_test, capacity) {
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
    TestedMethod: vector::operator[]
    Description: Returns a reference to the vector element at a specified position.
*/
TEST(vector_test, operator_bracket) {
    vector<int> v;
    v.push_back(20);
    v.push_back(26);
    v.push_back(39);

    EXPECT_EQ(20, v[0]);
    EXPECT_EQ(26, v[1]);
    EXPECT_EQ(39, v[2]);
}

// 遍历vector
TEST(vector_test, traverse) {
    vector<int> v;
    v.push_back(20);
    v.push_back(26);
    v.push_back(39);

    int array[] = { 20, 26, 39 };
    int index = 0;

    // 用数组的方式遍历
    for (vector<int>::size_type i = 0; i < v.size(); ++i) {
        EXPECT_EQ(array[index], v[i]);
        ++index;
    }

    // 通过迭代器遍历
    index = 0;
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        EXPECT_EQ(*it, array[index]);
        ++index;
    }

#if GTEST_LANG_CXX11
    // C++11
    index = 0;
    for (auto& elem : v) {
        EXPECT_EQ(array[index], elem);
        ++index;
    }
#endif
}

/*
    TestedMethod: vector::insert()
    Description: Inserts an element or a number of elements or a range of elements into the vector at a specified position.
*/
TEST(vector_test, insert_an_element) {
    vector<int> v;

    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(10);

    {
        int array[] = { 6, 7, 8, 10 };
        EXPECT_VECTOR_EQ(array, v);
    }

    // insert的位置在中间
    {
        v.insert(v.begin() + 3, 9);
        EXPECT_EQ(9, v[3]);

        int array[] = { 6, 7, 8, 9, 10 };
        EXPECT_VECTOR_EQ(array, v);
    }

    // insert的位置在开头
    {
        v.insert(v.begin(), 5);
        EXPECT_EQ(5, v[0]);

        int array[] = { 5, 6, 7, 8, 9, 10 };
        EXPECT_VECTOR_EQ(array, v);
    }

    // insert的位置在末尾
    {
        v.insert(v.end(), 11);
        EXPECT_EQ(11, v[v.size() - 1]);

        int array[] = { 5, 6, 7, 8, 9, 10, 11 };
        EXPECT_VECTOR_EQ(array, v);
    }
}

/*
    TestedMethod: vector::insert()
    Description: Inserts an element or a number of elements or a range of elements into the vector at a specified position.
*/
TEST(vector_test, insert_elements) {
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    {
        int array[] = { 10, 20, 30 };
        EXPECT_VECTOR_EQ(array, v);
    }

    /*
        TestedMethod: void vector::insert(const_iterator _Where, size_type count, const Type& val);
        Description: insert多个数值相同的元素。
    */
    {
        v.insert(v.begin() + 2, 4, 40);
        EXPECT_EQ(40, v[2]);
        EXPECT_EQ(40, v[3]);
        EXPECT_EQ(40, v[4]);
        EXPECT_EQ(40, v[5]);

        int array[] = { 10, 20, 40, 40, 40, 40, 30 };
        EXPECT_VECTOR_EQ(array, v);
    }

    /*
        TestedMethod:
            template <class InputIterator>
            void vector::insert(const_iterator _Where, InputIterator first, InputIterator last);
        Description: insert多个元素。
    */
    {
        {
            vector<int> vv;
            vv.push_back(0);
            vv.push_back(30);

            vector<int>::size_type size_before_insert = vv.size();
            vv.insert(vv.begin() + 1, v.begin(), v.begin() + 2);
            EXPECT_EQ(size_before_insert + 2, vv.size());

            int array[] = { 0, 10, 20, 30 };
            EXPECT_VECTOR_EQ(array, vv);
        }

        {
            vector<int>::size_type size_before_insert = v.size();
            v.insert(v.begin() + 1, v.begin() + 2, v.begin() + 4);
            EXPECT_EQ(size_before_insert + 2, v.size());

            int array[] = { 10, 40, 40, 20, 40, 40, 40, 40, 30 };
            EXPECT_VECTOR_EQ(array, v);
        }
    }

    // initialize a vector of vectors by moving v
    {
        vector<vector<int> > vv;

        vv.insert(vv.begin(), move(v));
        EXPECT_EQ(1, vv.size());

        int array[] = { 10, 40, 40, 20, 40, 40, 40, 40, 30 };
        EXPECT_VECTOR_EQ(array, vv[0]);
    }
}

/*
    TestedMethod: vector::()
    Description:
*/
TEST(vector_test, xx) {
}
