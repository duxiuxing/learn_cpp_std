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
    TestedMethod: vector::erase()
    Description: Removes an element or a range of elements in a vector from specified positions.
*/
TEST(vector_test, erase) {
    vector<int> v;

    {
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(40);
        v.push_back(50);

        int array[] = { 10, 20, 30, 40, 50 };
        EXPECT_VECTOR_EQ(array, v);
    }

    /*
        TestedMethod: iterator vector::erase(const_iterator _Where);
        Description: 删除单个元素。
    */
    {
        v.erase(v.begin());

        int array[] = { 20, 30, 40, 50 };
        EXPECT_VECTOR_EQ(array, v);
    }

    /*
        TestedMethod: iterator vector::erase(const_iterator first, const_iterator last);
        Description: 批量删除元素。
    */
    {
        vector<int>::size_type size_before_erase = v.size();
        v.erase(v.begin() + 1, v.begin() + 3);
        EXPECT_EQ(size_before_erase - 2, v.size());

        int array[] = { 20, 50 };
        EXPECT_VECTOR_EQ(array, v);
    }
}

class MyAnimal {
public:
    static int count;
    char* name;
    int age;
public:
    MyAnimal(char* name, int age) {
        ++MyAnimal::count;
        this->name = name;
        this->age = age;
    }
    ~MyAnimal() {
        --MyAnimal::count;
    }
};

int MyAnimal::count = 0;

/*
    TestedMethod: vector::erase()
    Description: 当元素为指针类型时，需要显式调用delete来销毁对象。
*/
TEST(vector_test, erase_object_element) {
    EXPECT_EQ(0, MyAnimal::count);

    MyAnimal* pDog = new MyAnimal("dog", 1);
    MyAnimal* pMonkey = new MyAnimal("monkey", 2);
    MyAnimal* pChicken = new MyAnimal("chicken", 3);
    MyAnimal* pSnake = new MyAnimal("snake", 4);

    EXPECT_EQ(4, MyAnimal::count);

    vector<MyAnimal*> v; // v将存放各对象的地址
    v.push_back(pDog);
    v.push_back(pMonkey);
    v.push_back(pChicken);
    v.push_back(pSnake);
    EXPECT_EQ(4, MyAnimal::count);

    delete pMonkey; // 物理删除pMonkey所指的对象
    v.erase(v.begin() + 1); // 删除第2个元素,即抹去了vector的pMonkey地址
    EXPECT_EQ(3, MyAnimal::count);

    for (vector<MyAnimal*>::iterator it = v.begin(); it != v.end(); ++it) {
        EXPECT_STRNE((*it)->name, "");
        EXPECT_NE((*it)->age, 0);
        delete (*it);
    }

    EXPECT_EQ(0, MyAnimal::count);
    v.clear(); // 清除所有vector元素
}
