int8_t是signed char
    int8_t min_value = INT8_MIN;
    int8_t max_value = INT8_MAX;

要用强制转换符
std::stringstream ss;
ss << (int32_t)min_value << " ~ " << (int32_t)max_value;


char str[10];
int a=175;
sprintf(str,"%x",a);//10进制转换成16进制，如果输出大写的字母是sprintf(str,"%X",a)
--------------------
char *itoa(int value, char* string, int radix); 
同样也可以将数字转字符串，不过itoa()这个函数是平台相关的（不是标准里的），故在这里不推荐使用这个函数。

.............
char str[]="AF";
int a;
sscanf(str,"%x",&a); //16进制转换成10进制


1、关于int 和 long int

（1）在VC下没有区别。两种类型均用4个字节存放数据。

（2）VC是后出的编译器，之前有很多早期的C编译器，在早期编译器下long int占4个字节，int占2个字节。
（3）之所以有“整型”和“长整形”两种不同类型，是C语言在诞生时发明者规定好的，

前者存储的整数的值域小于后者。 

这个问题不用牵肠挂肚，在VC下用谁都可以。

（4）在标准中，并没有规定long一定要比int长，也没有规定short要比int短。

标准时这么说的:长整型至少和整型一样长，整型至少和短整型一样长。
这个的规则同样适用于浮点型long double至少和double一样长，double至少和float一样长。
至于如何实现要看编译器厂商
（5）short<=int<=long

VC里面还有个
long long 是占8个字节的