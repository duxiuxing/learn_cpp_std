#include "gtest/gtest.h"

#include <vector>
using namespace std;

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
