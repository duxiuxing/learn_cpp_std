#include "gtest/gtest.h"

#include <vector>
using namespace std;

#define EXPECT_VECTOR_EQ(expect_array, actual_vector) \
    { \
        ASSERT_EQ(sizeof(expect_array) / sizeof(expect_array[0]), actual_vector.size()); \
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

// 3. 在任意位置插入vector元素
// 4. 利用erase函数删除vector元素
// 5. 反向遍历vector的元素
// 6. 两个vector容器元素的交换

/*
    TestedMethod: vector::()
    Description:
*/
TEST(vector_test, xx) {
}
