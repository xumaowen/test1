
#include "QtSysBasic.h"
#include <setjmp.h>
#include <map>
#include <vector>


/* 自定义一个命名空间 */
namespace stdTest
{

    //实现endl 
    template<class T>
    inline const T &endl(const T &op)
    {
        op.flush();  //调用flush方法
        return op;
    }

    template<class T>
    inline const T &pll(const T &op)
    {
        op.printaddr();
        return op;
    }

    class MyOstream
    {
    private:

        mutable int bPA;
        
    public:

        MyOstream():bPA(0) { }

        /* 调用的地方 类为const型，不允许修改类数据， 但如果成员函数不是const类型，编译器会认为该函数有修改类数据的嫌疑，会报错 */
        void flush() const
        {
            printf("\n");
            return;
        }

        void test1() { bPA = 0; return; }

        /* 若将成员函数声明为const，则该函数不允许修改类的数据成员, 除非将成员变量声明为mutables */ 
        // const 和 非const 也可以互相重载
        void printaddr() const
        {
            bPA = 1;
            return;
        }

        void clearaddr() const
        {
            bPA = 0;
        }

        const MyOstream& operator << (const MyOstream& (*pfun)(const MyOstream &)) const
        {
            clearaddr();
            return (*pfun)(*this);  //传递函数指针调用函数
        }

        const MyOstream& operator << (short int arg) const
        {
            printf("%hd", arg);
            clearaddr();
            return *this;
        }
                
        const MyOstream& operator << (const int arg) const
        {
            if (1 == bPA)
            {
                printf("%x", arg);

            }
            else
            {
                printf("%d", arg);
            }

            clearaddr();

            return *this;
        }

        const MyOstream& operator << (const int *arg) const
        {
            if (1 == bPA)
            {
                printf("%lx", (long unsigned int)arg);
            }
            else
            {
                if (0 != arg)
                {
                    printf("%d", *arg);
                }
                else
                {
                    printf("{null}");
                }
            }

            clearaddr();

            return *this;
        }

        const MyOstream& operator << (const unsigned int *arg) const
        {
            if (1 == bPA)
            {
                printf("%lx", (long unsigned int)arg);
            }
            else
            {
                if (0 != arg)
                {
                    printf("%u", *arg);
                }
                else
                {
                    printf("{null}");
                }
            }

            clearaddr();

            return *this;
        }

        const MyOstream& operator << (const long *arg) const
        {
            if (1 == bPA)
            {
                printf("%lx", (long unsigned int)arg);
            }
            else
            {
                if (0 != arg)
                {
                    printf("%ld", *arg);
                }
                else
                {
                    printf("{null}");
                }
            }

            clearaddr();

            return *this;
        }

        const MyOstream& operator << (const unsigned long *arg) const
        {
            if (1 == bPA)
            {
                printf("%lx", (long unsigned int)arg);
            }
            else
            {
                if (0 != arg)
                {
                    printf("%lu", *arg);
                }
                else
                {
                    printf("{null}");
                }
            }

            clearaddr();

            return *this;
        }

        const MyOstream& operator << (const unsigned int arg) const
        {
            if (1 == bPA)
            {
                printf("%lx", (long unsigned int)arg);

            }
            else
            {
                printf("%u", arg);
            }
            
            clearaddr();

            return *this;
        }

        const MyOstream& operator << (const long arg) const
        {
            printf("%ld", arg);
            clearaddr();

            return *this;
        }

        const MyOstream& operator << (const unsigned long arg) const
        {
            printf("%lu", arg);
            clearaddr();

            return *this;
        }

        const MyOstream& operator << (const long long arg) const
        {
            printf("%lld", arg);
            clearaddr();
            
            return *this;
        }

        const MyOstream& operator << (const unsigned long long arg) const
        {
            printf("%llu", arg);
            clearaddr();
            
            return *this;
        }
         
        const MyOstream& operator << (const char *s) const
        {
            if (1 == bPA)
            {
                printf("%lx", (long unsigned int)s);

            }
            else
            {
                printf("%s", s);
            }

            clearaddr();

            return *this;
        }

        const MyOstream& operator << (const unsigned char *s) const
        {
            if (1 == bPA)
            {
                printf("%lx", (long unsigned int)s);

            }
            else
            {
                printf("%s", s);
            }

            clearaddr();

            return *this;
        }


        const MyOstream& operator << (const std::string s) const
        {
            std::cout << s;

            clearaddr();
            
            return *this;
        }

        /* 打印行号 */
        const MyOstream& PL (unsigned long ulLine) const
        {
            printf("L[%5d] ", (int)ulLine);
            clearaddr();
            
            return *this;
        }

    };

    MyOstream cout;
}


/* using namespace std 表示了所有的标准库函数都在标准命名空间std中进行了定义。其中std表示标准命名空间的名字。
   该语句的作用就在于避免发生重命名的问题() 如果引用 stdTest 命名空间 , 引用 cout 就会报错 */
using namespace std;
//using namespace stdTest;

/* 自定义程序空间 */
namespace InheritTest
{

void namespacetest()
{
    Cprintf("using InheritTest namespace\n");
}

/* 此处先声明一个类名,后续必须有真正的声明(可以无此声明) */
class MAIN_Friend;
class MAIN_Test;

/* 第三类友元函数声明 */
ULONG FriendFun3(IN MAIN_Test &clsMainClass, IN MAIN_Friend &clsFriendClass);


/* 基类 */
class MAIN_GrandPa
{
public:
    MAIN_GrandPa(IN ULONG ulTmp = 0);
    ~MAIN_GrandPa(void);

    ULONG pubulGrandPaA;
    static ULONG pubulStaticTest;  /* 静态变量,多用于多个相同类的对象之间的通信 */

    /* 运算符重载(入参必须本身所属的类,且不能有默认参数) */
    ULONG operator + (IN MAIN_GrandPa &clsTmp1);
    ULONG operator - (IN ULONG &ulTmp1);

protected:
    ULONG proulGrandPaB;

private:
    ULONG priulGrandPaC;
};

/* 父类:私有继承其父类,只能访问父类的公有成员(父类的公有成员就是该类的私有成员) */
class MAIN_Father : private MAIN_GrandPa
{
public:
    typedef MAIN_GrandPa Superclass;
    MAIN_Father(IN ULONG ulTmp = 1);
    ~MAIN_Father(void);

    ULONG pubulParentA;
    virtual void virtualTest(void); /* 虚函数 */

protected:
    ULONG proulParentB;

private:
    ULONG priulParentC;
    UCHAR *pszTmp;
    class MAIN_Friend *pstClass;
};

/* 子类:公有继承其父类,只能访问父类的公有成员及保护成员 */
class MAIN_Test : public MAIN_Father
{
public: /* 声明的是公有成员，任何情况下均可访问 */

    MAIN_Test(IN int x = 0, IN int y = 0);  /* C++ 里允许多个构造函数,根据调用入参选择使用哪个 */
    MAIN_Test(IN CHAR *pszTmp = NULL);      /* 构造函数 */
    ~MAIN_Test( );                  /* 析构函数 */

    void virtualTest(void);         /* 父类被声明为虚函数,这里自动转换为虚函数 不需要virtual */
    /* 函数重载属于静态多态性,编译时决定用哪个 */
    /* 虚函数属于动态多态性,调用时决定用哪个 */
    /* 将virtual 去掉,发现引用基类的地址发现打印父类的函数 */

    ULONG pubulChildrenA;
    ULONG TEST_Public_Fun1(IN ULONG ulA, IN ULONG ulB); /* 公有成员函数 */

    friend ULONG FriendFun1(IN MAIN_Test &clsTmp);    /* 第一类友元函数:在类的外部通过这个函数访问该类的私有成员 */
    ULONG FriendFun2(IN MAIN_Friend &clsFriendClass); /* 第二类友元函数:通过这个函数访问其它类的所有成员 */

    /* 第三类友元函数:将一个不属于任何类的普通函数声明为多个类的友元函数,该函数可以访问多个类的私有成员 */
    friend ULONG FriendFun3(IN MAIN_Test &clsMainClass, IN MAIN_Friend &clsFriendClass);

    ULONG TEST_FunPultectAdd(IN ULONG ulTmp1, IN ULONG ulTmp2);  /* 函数重载,通过入参来区别 */
    ULONG TEST_FunPultectAdd(IN DOUBLE dTmp1, IN DOUBLE dTmp2);  /* 函数重载,通过入参来区别 */

protected: /* 声明的是保护成员，只能在类的内部以及其子类的内部访问它，在类外不能访问 */
    ULONG proulChildrenB;
    string prostrTmp1;
    string prostrTmp2[36];
    UCHAR  prouszTmp3[36];

private:   /* 声明的是私有成员，只能在类的内部访问它，其子类也不能够访问 */
    ULONG priulChildrenC;
    string pristrTmp1;
    UCHAR priuszTmp1[36];
    char *pripszTmp;
    ULONG TEST_FunPrivate(void);

};


/* 声明一个其它类,主要用于友元函数学习 */
class MAIN_Friend
{
public:
    MAIN_Friend(void);
    ~MAIN_Friend(void);

    ULONG pubulFriendA;

    /* 第二类友元函数:通过这个函数访问其它类的所有成员 */
    friend ULONG MAIN_Test::FriendFun2(IN MAIN_Friend &clsFriendClass);

    /* 第三类友元函数:将一个不属于任何类的普通函数声明为多个类的友元函数,该函数可以访问多个类的私有成员 */
    friend ULONG FriendFun3(IN MAIN_Test &clsMainClass, IN MAIN_Friend &clsFriendClass);

protected:
    ULONG proulFriendB;

private:
    ULONG priulFriendC;

};
} // end namespace

class MAIN_Test2
{
public:
    MAIN_Test2();
    MAIN_Test2(int c);
    static void fun1();
    char getChar()       { return (char)i2test1; }
    void ToChar(int off) { i2test1 += off; return; }
    void numInit()       { i2test1 = rand() % 10; return; }
    int i2test1;
};

namespace oldTemplateTest
{

/* 模板类 */
template <class Type> // template <class Type1, class Type2>
class clsTmpLate1
{
public:
    clsTmpLate1();
    clsTmpLate1(char c);
    clsTmpLate1(Type c);
    ~clsTmpLate1();
    void push(Type c, int d);
    Type pop(int c);
    virtual Type operator[](int i);

private:

    Type *pItem;
    int iMaxNum;
};

/* 模板参数类 new */
template <template <typename T> class Thing>
class clsTmpLate2
{
public:
    clsTmpLate2();
    ~clsTmpLate2();
private:
    Thing<int> a;
    Thing<clsTmpLate1<int> > b;
    Thing<MAIN_Test2> c;
    //T *apItem; error ???
};
}// end namespace

/*  */
namespace corefunspace
{

/* 用于处理 核心流程/算法 的模板(不区分输入数据类型) */
template <typename TData, typename TFunction>
class cls_T_CORE
{
public:
    typedef TFunction FunctorType;

    cls_T_CORE() {return;}
    ~cls_T_CORE(){return;}

    void cls_T_2_transform(void)
    {
        for (int i = 0; i < st1.getMaxNum(); i++)
        {
            st1.Put(m_Functor(st1.Get()));
        }

        st1.PrintSelf();

        return;
    }

private:
    FunctorType m_Functor;
    TData st1;
};

/* 供cls_T_CORE模板引用的功能类 */
template <typename T>
class cls_corefun1
{
public:
    cls_corefun1() {return;}
    ~cls_corefun1(){return;}

    // 实现数字转字符串功能
    T operator()(T x)
    {
        x.ToChar(48);
        return x;
    }

private:
};

/* 供cls_T_CORE模板引用的数据类 */
template <typename T, int iMaxNum>
class cls_dataAccess
{
public:
    cls_dataAccess()
    {
        T a;
        slsData.push_back(a);
        ulCurLen = 1;
        return;
    }

    ~cls_dataAccess(){ slsData.clear(); return; }

    // 产生一个随机数
    T Get(void)
    {
        T a;
        a.numInit();
        slsData.push_back(a);
        ulCurLen++;
        return slsData[ulCurLen - 2];
    }

    // 存储一个数字字符
    void Put(const T &x)
    {
        slsData[ulCurLen - 2] = x;
        return;
    }

    int getMaxNum(void)
    {
        return iMaxNum;
    }

    void PrintSelf(void)
    {
        Cprintf("----template test : ");
        for (size_t i = 0; i < slsData.size();i++)
        {
            stdTest::cout << slsData[i].getChar();
        }

        stdTest::cout << stdTest::endl;

        return;
    }

private:
    std::vector<T> slsData;
    unsigned long ulCurLen;
};
}// end namespace

namespace newTemplateTest
{
void namespacetest()
{
    Cprintf("using newTemplateTest namespace\n");
}

/* new cls_T_CORE模板的引用实例 */
template <typename T, int KSize>
class clsTemplate : public corefunspace::cls_T_CORE<corefunspace::cls_dataAccess<T, KSize>, corefunspace::cls_corefun1<T> >
{
public:
    clsTemplate();
    clsTemplate(T c);
    ~clsTemplate();
    virtual T operator[](int i);

 // typedef std::map<char, int> maptest1;
 // typedef std::map<char, T> maptest2;

private:
    T *apItem;

};
}// end namespace

//---------------------------------------------------------------------------------

namespace oldTemplateTest
{

/* 模板类 */
template <class Type>
clsTmpLate1<Type>::clsTmpLate1()
{
    iMaxNum = 2;

    /* 这种方法分配的内存信息不公用，如无法使用sizeof() 测量数组占用的内存大小 */
    pItem = new Type[iMaxNum];
    Cprintf("new: %d %s %d x %d\n", (int)sizeof(*pItem), (iMaxNum == 1) ? "=" : "!=", (int)iMaxNum, (int)sizeof(Type));

    return;
}

template <class Type>
clsTmpLate1<Type>::clsTmpLate1(char c) : iMaxNum(c)
{
    pItem = new Type[iMaxNum];

    return;
}

template <class Type>
clsTmpLate1<Type>::clsTmpLate1(Type c)
{
    iMaxNum = 1;
    pItem = new Type;

    memcpy(pItem, &c, sizeof(*pItem));

    return;
}

template <class Type>
clsTmpLate1<Type>::~clsTmpLate1()
{
    delete [] pItem;

    return;
}

/* 符号重载 */
template <class Type>
Type clsTmpLate1<Type>::operator[](int i)
{
    if (i >= iMaxNum)
    {
        Cprintf("err over clsTmpLate1 operator[] max  %d\n", __LINE__);
        return 0;
    }

    return pItem[i];
}

template <class Type>
void clsTmpLate1<Type>::push(Type c, int curid)
{
    if (curid >= iMaxNum)
    {
        Cprintf("err over clsTmpLate1 push max  %d\n", __LINE__);
        return;
    }

    memcpy(&pItem[curid], &c, sizeof(c));

    return;
}

template <class Type>
Type clsTmpLate1<Type>::pop(int c)
{
    Type res;

    if (c >= iMaxNum)
    {
        Cprintf("err over clsTmpLate1 pop max %d\n", __LINE__);
        return 0;
    }

    memcpy(&res, &pItem[c], sizeof(res));

    return res;
}

/* 模板类作为参数 */
template <template <class T> class Thing>
clsTmpLate2<Thing>::clsTmpLate2()
{
    Thing<int> test1;

    return;
}

template <template <class T> class Thing>
clsTmpLate2<Thing>::~clsTmpLate2()
{
    return;
}

}// end namespace

MAIN_Test2::MAIN_Test2()
{
    i2test1 = 1;
    return;
}

MAIN_Test2::MAIN_Test2(int c) : i2test1(c)
{
    return;
}

void MAIN_Test2::fun1()
{
    Cprintf("MAIN_Test2 static fun test  %d\n", __LINE__);
    return;
}

namespace InheritTest
{

/* 对象里的静态变量必须在CPP文件里声明一遍来分配内存,定义多个相同类共用这一个内存 */
ULONG MAIN_GrandPa::pubulStaticTest;

/* 基类构造函数 */
MAIN_GrandPa::MAIN_GrandPa(IN ULONG ulTmp)
{
    /* 初始化基类成员 */
    pubulGrandPaA = 101;
    proulGrandPaB = ulTmp;
    priulGrandPaC = 103;
    UCHAR szEndSize[4] = {2, 1, 0, 0};
    ULONG *pulEndSize = (ULONG *)szEndSize;


    /* 字节对齐测试 */
    typedef struct tagDuiqiA
    {
        USHORT a;
        ULONG b;
        USHORT C;
    }DUIQI_A_S;

    typedef struct tagDuiqiB
    {
        USHORT a;
        USHORT C;
        ULONG b;
    }DUIQI_B_S;

    stdTest::cout.PL(__LINE__) << "End Size : " << ((*pulEndSize == 258) ? "small end" : "big end") << stdTest::endl;    // 何为计算机大小端序?
    stdTest::cout.PL(__LINE__) << "Byte alignment : " << sizeof(DUIQI_A_S) << " ?= " << sizeof(DUIQI_B_S) << stdTest::endl; // 结果是否相同? WHY?
    Cprintf("GrandPa Class Create");

    return;
}

/* 运算符(+号)重载 */
ULONG MAIN_GrandPa::operator + (IN MAIN_GrandPa &clsTmp1)
{
    ULONG ulTmp = 0;

    ulTmp = proulGrandPaB + clsTmp1.proulGrandPaB;
    Cprintf("A(%lu) + B(%lu) = C(%lu)\n", proulGrandPaB, clsTmp1.proulGrandPaB, ulTmp);

    return ulTmp;
}

/* 运算符(-号)重载 */
ULONG MAIN_GrandPa::operator - (IN ULONG &ulTmp1)
{
    ULONG ulTmp = 0;

    ulTmp = proulGrandPaB - ulTmp1;
    Cprintf("A(%lu) - Input(%lu) = C(%lu)\n", proulGrandPaB, ulTmp1, ulTmp);

    return ulTmp;
}


/* 基类析构函数 */
MAIN_GrandPa::~MAIN_GrandPa(void)
{
    Cprintf("GrandPa Class Delete\n");

    return;
}

/* 父类构造函数 */
MAIN_Father::MAIN_Father(IN ULONG ulTmp): Superclass(ulTmp), pubulParentA(ulTmp)
{
    MAIN_GrandPa *clsOperatorA = new MAIN_GrandPa(125); /* 创建类并调用构造函数 */

    /* 标准库中包含一个名为allocator的类，允许我们将分配和初始化分离。使用allocator通常会提供更好的性能和更灵活的内存管理能力 */
    allocator<MAIN_GrandPa> clsOperatorB;
    //auto const p = clsOperatorB.allocate(2); /* 创建2个类结构/数组，只申请内存，不调用构造函数 */
    MAIN_GrandPa *p = clsOperatorB.allocate(2); /* 同上 */

    /* 调用构造函数 */
    auto q = p;
    clsOperatorB.construct(q++, 126);
    clsOperatorB.construct(q, 127);


    /* 申请内存/释放内存 */
    vector<int> v1{1, 2, 3, 4, 5};
    int* p1 = (int *)allocator<int>().allocate(v1.size() * 2); 
    auto p2 = std::uninitialized_copy(v1.begin(), v1.end(), p1);  //  通过拷贝的方式初始化数据，返回拷贝内存的下一个地址
    std::uninitialized_fill_n(p2, v1.size(), 42); // 将剩余的数值填充为42
    p1[2] = 6; // 直接修改元素


    /* 私有继承基类的public属性成员在子类中呈现private属性(保护继承类似) */
    pubulParentA = pubulGrandPaA * ulTmp;

    /* 私有继承基类的protected属性成员在子类中呈现private属性 */
    proulParentB = proulGrandPaB;

    /* 私有继承不允许访问基类私有成员,否则编译报错  */
  //  priulParentC = priulGrandPaC;

    /* 运算符重载实例 */
    priulParentC = (*clsOperatorA) + p[0];
    priulParentC = p[0] - proulParentB;

    /* 动态分配对象/缓存 */
    pstClass = new MAIN_Friend;
    pszTmp = new UCHAR[10];

    /* 多个相同类对象的静态变量共用一块内存空间 */
    class MAIN_GrandPa clsA;
    clsA.pubulStaticTest++;
    Cprintf("Static Value Test [%lu]\n", MAIN_GrandPa::pubulStaticTest);
    class MAIN_GrandPa clsB;
    clsB.pubulStaticTest++;
    Cprintf("Static Value Test [%lu]   priulParentC = [%lu]   %d-%d\n", clsB.pubulStaticTest, priulParentC, p1[1], p1[7]);

    stdTest::cout.PL(__LINE__) << "Father Class Create" << (stdTest::endl);

    /* 调用析构函数 */
    while (q != p)
    {
        clsOperatorB.destroy(--q);
    }

    /* 清除分配的内存 */
    clsOperatorB.deallocate(p, 2);
    allocator<int>().deallocate((int *)p1, v1.size() * 2);

    return;
}

/* 虚函数 */
void MAIN_Father::virtualTest(void)
{
    stdTest::cout.PL(__LINE__) << "virtual test Father" << stdTest::endl;
    return;
}


/* 父类析构函数 */
MAIN_Father::~MAIN_Father(void)
{
    /* 删除动态分配的变量 */
    delete pstClass;

    /* pszTmp为数组, 不加[] 仅仅释放第一个字节,后面的内存仍处于占用状态 */
    delete [] pszTmp;

    stdTest::cout.PL(__LINE__) << "Father Class Delete" << stdTest::endl;

    return;
}


/* 子类构造函数 */
MAIN_Test::MAIN_Test(IN int x, IN int y) : MAIN_Father(x), pubulChildrenA(x)
{
    pripszTmp = NULL;

    /* 公有继承父类的public属性成员在子类中呈现public属性 */
    pubulChildrenA = pubulParentA;

    /* 公有继承父类的protected属性成员在子类中呈现protected属性 */
    proulChildrenB = proulParentB;

    /* 子类不能访问父类私有成员*/
  // priulChildrenC = priulParentC;

    /* 子类不能访问父类私有继承的公有成员 */
//    priulChildrenC = pubulGrandPaA;
    priulChildrenC = (x * y);

    stdTest::cout.PL(__LINE__) << "Children Class Create\n\n" << stdTest::endl;

    return;
}

/* 子类构造函数 */
MAIN_Test::MAIN_Test(IN CHAR *pszTmp)
{
    int i = 0;
    string strTmp;
    SIZE_T ulDateLen = 9;

    pubulChildrenA = 10;
    proulChildrenB = 11;
    priulChildrenC = 12;

    if (NULL == pszTmp)
    {
        return;
    }

    stdTest::cout.PL(__LINE__) << "Please Input uszTmp: \n" << stdTest::endl;
    for (i = 0 ; i < 6; i++)
    {
     //   cin >> priuszTmp1[i];
    }

    prostrTmp1 = pszTmp;

    stdTest::cout.PL(__LINE__) << "Please Input prostrTmp1: \n" << stdTest::endl;

    /*  */
//    getline(cin, prostrTmp1);
    pripszTmp = new char [36];

//    ulDateLen = getline(&pripszTmp, (SIZE_T *)&priulChildrenC, stdin);
    Cprintf("getline  [%s]  [%d]\n", pripszTmp, (int)ulDateLen);

    pristrTmp1 = "Test";

    /* 字符串拼接 */
    strTmp = pszTmp + pristrTmp1;

    /* 字符串追加 */
    pristrTmp1 += pszTmp;

    stdTest::cout.PL(__LINE__) << "uszProtectTmp1:" << prouszTmp3 << "strTmp:" << pristrTmp1 << stdTest::endl;
    stdTest::cout.PL(__LINE__) << "Children Class Create\n\n" << stdTest::endl;

    return;
}

/* 虚函数 */
void MAIN_Test::virtualTest(void)
{
    stdTest::cout.PL(__LINE__) << "virtual test Child" << stdTest::endl;

    return;
}

/* 子类公有成员函数 */
ULONG MAIN_Test::TEST_Public_Fun1(IN ULONG ulA, IN ULONG ulB)
{
    stdTest::cout.PL(__LINE__) << "MAIN Public Fun1\n" << stdTest::endl;

    return (ulA * ulB);
}

/* 子类公有成员函数 */
ULONG MAIN_Test::TEST_FunPultectAdd(IN ULONG ulTmp1, IN ULONG ulTmp2)
{
    ULONG ulAdd = 0;

    ulAdd = ulTmp1 + ulTmp2;
    stdTest::cout.PL(__LINE__) << " Protect Funs Add[ULONG] = " << ulAdd << stdTest::endl;

    return ulAdd;
}

/* 子类公有成员函数(重载) */
ULONG MAIN_Test::TEST_FunPultectAdd(IN DOUBLE dTmp1, IN DOUBLE dTmp2)
{
    DOUBLE dAdd = 0;

    dAdd = dTmp1 + dTmp2 + 0.5;
    stdTest::cout.PL(__LINE__) << " Protect Funs Add[DOUBLE] = " << (ULONG)dAdd << stdTest::endl;

    return (ULONG)dAdd;
}


/* 子类私有成员函数 */
ULONG MAIN_Test::TEST_FunPrivate(void)
{
    stdTest::cout.PL(__LINE__) << " Protect Funs " << stdTest::endl;

    return 0;
}

/* 子类析构函数 */
MAIN_Test::~MAIN_Test(void)
{
    delete [] pripszTmp;

    stdTest::cout.PL(__LINE__) << "\n\nChildren Class Delete" << stdTest::endl;

    return;
}

/* 友类构造函数 */
MAIN_Friend::MAIN_Friend(void)
{
    pubulFriendA = 22;
    proulFriendB = 23;
    priulFriendC = 24;

    stdTest::cout.PL(__LINE__) << "Friend Class Create" << stdTest::endl;

    return;
}

/* 友类析构函数*/
MAIN_Friend::~MAIN_Friend(void)
{
    stdTest::cout.PL(__LINE__) << "Friend Class Delete" << stdTest::endl;

    return;
}

void reference_test(int &a)
{
    // 指针没有级数限制，引用只有一级
    long double test1 = 1.1; 
    long double &test2 = test1;
    
    Cprintf("%d  %x  %d  %d\n", a, &a, (int)sizeof(test1), (int)sizeof(test2));

    return;
}

/* 引用& 与指针* 的区别 1.指针传递了入参的原始地址供函数内操作  2.引用没有传递地址，对入参的操作就是对原始数据的操作，相当于原始数据的别名,指针相当于实体 */
/* 第一类友元函数 */
ULONG FriendFun1(IN MAIN_Test &clsTmp)
{
    int a = 10;
    int &b = a;

    b = 11;
    b++;
    Cprintf("reference test  %d  %d  %x\n", a, b, &a);
    reference_test(a);

    /* 友元函数访问对象的私有成员 */
    Cprintf("FriendFun[1] Access pubA[%lu] proB[%lu] priC[%lu]\n",
           clsTmp.pubulChildrenA, clsTmp.proulChildrenB, clsTmp.priulChildrenC);
    clsTmp.pubulChildrenA = 12354;

    return 0;
}

/* 第二类友元函数 */
ULONG MAIN_Test::FriendFun2(IN MAIN_Friend &clsFriendClass)
{
    /* MAIN_Test类 访问 MAIN_Friend类 的私有成员 */
    priulChildrenC = clsFriendClass.priulFriendC;

    Cprintf("FriendFun[2] Access priC[%lu]\n", priulChildrenC);

    return 0;
}

/* 第三类友元函数 */
ULONG FriendFun3(IN MAIN_Test &clsMainClass, IN MAIN_Friend &clsFriendClass)
{
    /* 访问多个类的私有成员 */
    Cprintf("FriendFun[3] Access Class1 priC[%lu]  Class2 priC[%lu]\n",
           clsMainClass.priulChildrenC, clsFriendClass.priulFriendC);

    return 0;
}
}// end namespace

namespace newTemplateTest
{

/* 模板类 */
template <typename T, int KSize>
clsTemplate<T, KSize>::clsTemplate()
{
    apItem = new T[KSize];

    return;
}

struct Map_classcomp
{
    bool operator() (const char &lhs, const char &rhs) const
    {
        Cprintf("Map-compare-A  %c  %c\n", lhs, rhs);

        return lhs < rhs;
    }
};

bool Map_fncomp(char lhs, char rhs)
{
    Cprintf("Map-compare-B  %c  %c\n", lhs, rhs);

    return lhs < rhs;
}

template <typename T, int KSize>
clsTemplate<T, KSize>::clsTemplate(T c)
{
    int k = 0;
    apItem = new T[KSize];
    memcpy(&apItem[0], &c, sizeof(c));
    char c1 = 'F';

    /* Map是一种关联容器，它按照特定顺序存储由键值Key和映射值Value组合而成的元素 */
    typedef std::map<char, int> SRMAP_T;
    SRMAP_T maptest1;

    maptest1['A'] = 10;
    maptest1['B'] = 11;
    maptest1['C'] = 12;
    maptest1['D'] = 13;
    maptest1['E'] = 12;

    maptest1.at('A') = 201;  // 修改参数

    /* 插入元素 */
    std::pair<std::map<char, int>::iterator, bool> P_ret;
    P_ret = maptest1.insert(std::pair<char, int>('Q', 202)); // try 'D'
    std::map<char, int>::iterator tmp = maptest1.begin();
    //maptest1.insert(tmp, std::pair<char, int>('Q', 300));
    if (P_ret.second == false)
    {
        stdTest::cout.PL(__LINE__) << "element 'z' already existed";
        stdTest::cout << " with a value of " << P_ret.first->second << stdTest::endl;
    }

    c1 = 'Q';
    tmp = maptest1.find(c1);
    maptest1.erase(tmp);         // maptest1.erase(c1);
    maptest1.emplace(c1, 100);   //插入元素

    std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> pairtest1;

    // 如果找不到键值与k相等的元素，则两个迭代器均指向排在k之后的第一个元素。
    pairtest1 = maptest1.equal_range('A');

    stdTest::cout.PL(__LINE__) << "lower points to: " << pairtest1.first->first << " => " << pairtest1.first->second << stdTest::endl;
    stdTest::cout.PL(__LINE__) << "upper points to: " << pairtest1.second->first << " => " << pairtest1.second->second << stdTest::endl;

    SRMAP_T::iterator itlow, itup;

    itlow = maptest1.lower_bound('B');  // 指向容器中第一个键值等于 k 或排在 k 之后的元素 itlow points to B
    itup = maptest1.upper_bound('D');   // 向容器中第一个键值排在 k 之后的元素 itup points to E (not D!)

    maptest1.erase(itlow, itup);        // erases [itlow, itup]

    for (std::map<char, int>::iterator it = maptest1.begin(); it != maptest1.end(); ++it)
    {
        stdTest::cout.PL(__LINE__) << it->first << " => " << it->second << stdTest::endl;
    }

    /* begin 返回一个迭代器，指向第一个元素, end返回一个迭代器，指向尾后元素 */
    std::map<char, int> maptest2(maptest1.begin(), maptest1.end());
    std::map<int, T> maptest3;
    maptest3[11] = c;

    std::map<char, int, Map_classcomp> maptest4;
    maptest4['C'] = 15;
    maptest4['D'] = 16;

    bool(*fn_pt)(char, char) = Map_fncomp;
    std::map<char, int, bool(*)(char, char)> maptest5(fn_pt); // function pointer as Compare
    maptest5['E'] = 17;
    maptest5['F'] = 18;

    Cprintf("-------------map test %d- %d - %d - %d - %d - %d - %d \n",
           maptest1['E'], (int)maptest1.size(),
           maptest2['A'],
           maptest3[11].i2test1,        // 已在 TemplateTest 赋值
           maptest3.find(11)->second.i2test1,
           maptest4['C'], maptest5['E']);

    c1 = 'F';  // try 'W'
    Cprintf("'%c' %s\n", c1, maptest5.count(c1) > 0 ? "is an element of Map" : "is not an element of Map");

    /* 健值比较 */
    std::map<char, int>::key_compare map_key_comp = maptest1.key_comp();
    tmp = maptest1.begin();
    do
    {
        stdTest::cout.PL(__LINE__) << tmp->first << " +=> " << tmp->second << stdTest::endl;
    }
    while (map_key_comp((*tmp++).first, 'E'));

    /* 健值比较 */
    std::pair<char, int> target1('E', 12);
    tmp = maptest1.begin();
    do
    {
        stdTest::cout.PL(__LINE__) << tmp->first << " -=> " << tmp->second << stdTest::endl;
    }
    while (maptest1.value_comp()(*tmp++, target1));


    /* pair是将2个数据组合成一个数据，当需要这样的需求时就可以使用pair */
    std::pair<int, char> p1(1, 's');
    stdTest::cout.PL(__LINE__) << p1.first << ' ' << p1.second << stdTest::endl;

//-------------------------------< vector >----------------------------------

    std::vector<int> vec_test1(4, 101);
    std::array<int, 12> arGroup = {7,6,5,4,3,2,3,24,25,26,27};
    int aiInts[] = {16, 21, 77, 29};
    std::vector<int> vec_test2(aiInts, aiInts + sizeof(aiInts) / sizeof(int));
    std::vector<int> vec_test3(vec_test2);    // a copy of third
    vec_test3.push_back(102);     // 插入数据
    vec_test3.push_back(103);
    vec_test3[1] = 23;            // 修改数据
    int *p2 = vec_test3.data();
    *(p2++) = 123;                // 修改数据
    arGroup[1] = arGroup.size();
    std::vector<T> vec_test7(2, c);

    /* 删除指定元素 */
    for (std::vector<int>::iterator it = vec_test3.begin(); it != vec_test3.end(); )
    {
        if (103 == *it)
        {
            // remove() 没有删除元素只是元素的替换
            int iOldSize = vec_test3.size();
            it = vec_test3.erase(it);
            stdTest::cout.PL(__LINE__) << "delete a element " << iOldSize << " -> " << vec_test3.size() << stdTest::endl;
        }
        else
        {
            ++it;
        }
    }

    std::vector<SRMAP_T::iterator> vec_test6(10);
    SRMAP_T::iterator tmp2 = maptest1.begin();
    //tmp2['u'] = 73; // !!error
    vec_test6.at(8) = tmp2;
    //vec_test6.assign(7, tmp2);

    /* 赋值 */
    k = 0;
    for (SRMAP_T::iterator it = maptest1.begin(); it != maptest1.end(); ++it, k++)
    {
        vec_test6[k] = it;
        vec_test6.at(k) = it;
    }

    std::vector<SRMAP_T::iterator>::iterator it_1;
    it_1 = vec_test6.begin();
    it_1 = vec_test6.insert(it_1, tmp2);   // 插入数据 ， tmp2必须有指向，否则insert段错误
    vec_test6.insert(it_1, 2, tmp2);

    /* 插入 */
    SRMAP_T::value_type p('R', 227);
    vec_test6.push_back(maptest1.insert(p).first);

    Cprintf("-------------vec test %d %d  %d  %d-%d-%d  %d -- m %c:%d\n",
           arGroup[3],
           vec_test1[0], vec_test2[1],
           (int)vec_test2.size(), (int)vec_test2.capacity(), (int)vec_test2.max_size(),
           vec_test7[1].i2test1,
           vec_test6[1]->first, vec_test6[0]->second );

    for (std::vector<int>::iterator it = vec_test3.begin(); it != vec_test3.end(); ++it)
    {
        stdTest::cout << ' ' << (*it);
    }

    for (std::vector<SRMAP_T::iterator>::iterator it = vec_test6.begin(); it != vec_test6.end(); ++it)
    {
        //if (0 != static_cast<int>(it[0]))
        {
            Cprintf("-------- %x %x \n", it, it[0]); //it[0]->second
        }
    }

    stdTest::cout << stdTest::endl;

    return;
}

template <typename T, int KSize>
clsTemplate<T, KSize>::~clsTemplate()
{
    delete [] apItem;

    return;
}

/* 符号重载 */
template <typename T, int KSize>
T clsTemplate<T, KSize>::operator[](int i)
{
    if (i >= KSize)
    {
        Cprintf("error %d  %d  L-%d\n", i, KSize, __LINE__);
        return 0;
    }

    return apItem[i];
}

void TemplateTest(void)
{
    int a = 15;
    MAIN_Test2 stB;
    oldTemplateTest::clsTmpLate1<int> test1((char)3);
    oldTemplateTest::clsTmpLate1<MAIN_Test2> test2;

    stB.i2test1 = 12;

    test1.push(a, 1);
    Cprintf("clsTmpLate1 1 -> %d %d\n", test1.pop(1), test1[1]);

    clsTemplate<MAIN_Test2, 4> clstest1(stB);
    clstest1.cls_T_2_transform( );

    Cprintf("clsTemplate 2  -> %d\n", clstest1[0].i2test1);

    oldTemplateTest::clsTmpLate2<oldTemplateTest::clsTmpLate1> test3;
    //clsTmpLate2<MAIN_Test2> test4;  clsTmpLate2的 <>入参必须是模板类

    return;
}
}// end namespace

void CTest(void)
{
    InheritTest::namespacetest(); //newTemplateTest

    InheritTest::MAIN_Test stTest1[2] = {InheritTest::MAIN_Test(112, 24),
                                         InheritTest::MAIN_Test(0)};
    InheritTest::MAIN_Friend stFriend;
    InheritTest::MAIN_Father stFather(1);
    InheritTest::MAIN_Father *pstVirtualTest = NULL;

    /* 分别调用三种友元函数 */
    InheritTest::FriendFun1(stTest1[0]);
    stTest1[0].FriendFun2(stFriend);
    InheritTest::FriendFun3(stTest1[0], stFriend);

    /* 类外使用非公有成员编译失败 */
  //stTest1.TEST_Protect( );
  //stTest1.TEST_Private( );

    /* 根据入参选择对应构造函数 */
    InheritTest::MAIN_Test stTest2((CHAR *)"asdffhjgfhf123443");

    /* 调用重载函数(根据入参来选择) */
    stdTest::cout.PL(__LINE__) << "Double Add Double Is : " << stTest2.TEST_FunPultectAdd(2.1, 3.4) << stdTest::endl;

    /* 虚函数测试 将函数前的virtual 去掉试一下 */
    pstVirtualTest = &stFather;
    pstVirtualTest->virtualTest( );
    pstVirtualTest = &stTest1[0];
    pstVirtualTest->virtualTest( );

    newTemplateTest::TemplateTest();

    return;
}

static char *gpcMemAddrTest = NULL;
//static jmp_buf gstJmpBuffer;

void MAIN_Memory_b(char **p)
{
    Cprintf("\nbbbbb-1   [%p]  [%p]  [%s]\n", p, *p, *p);

    // 释放内存 就是将分给你的那块内存还给操作系统
    // 释放内存不代表这块内存被清 0 ，因编译平台而异，X86平台一般会清0，而ARM架构（如华为HISI3616提供的编译器回收内存后就不会清零）
    free(*p);
    *p = NULL;

   // longjmp(gstJmpBuffer, 1);

    Cprintf("bbbbb-2   [%p]  [%p]      [%s]\n\n", p, *p, *p);

    return;
}

void MAIN_Memory_a(char *p)
{
    Cprintf("\naaaaa-1   [%p]  [%p]  [%s]\n", &p, p, p);
    MAIN_Memory_b(&p);
    Cprintf("aaaaa-2   [%p]  [%p]      [%s]\n\n", &p, p, p);

    return;
}

void MAIN_Memory_c(char **p)
{
    if (NULL == gpcMemAddrTest)
    {
        return;
    }

    Cprintf("\nccccc-1   [%p]  [%p]      [%s]\n", p, *p, *p);
    *p = gpcMemAddrTest;
    Cprintf("ccccc-2   [%p]  [%p]  [%s]\n\n", p, *p, *p);

    return;
}

void MAIN_Memory_d(char *p)
{
    if (NULL == gpcMemAddrTest)
    {
        return;
    }

    Cprintf("\nddddd-1   [%p]  [%p]  [%s]\n", &p, p, p);
    p = gpcMemAddrTest;
    Cprintf("ddddd-2   [%p]  [%p]  [%s]\n\n", &p, p, p);

    return;
}

void TwoLevelPointTest(void)
{
    /* 内存地址变换问题 */
#if 0
    char *p = NULL;
    int a[5] = {1,2,3,4,5};
    int *ptr = (int *)(&a + 1);

    Cprintf("%d,%d\n", *(a + 1), *(ptr - 1));  // why?

    Cprintf("=====-1   [%p]    [%p]  [%s]\n", &gpcMemAddrTest, gpcMemAddrTest, gpcMemAddrTest);

    /* 在堆上分配16字节内存  */
    gpcMemAddrTest = (char *)QT_Malloc(16);

    gpcMemAddrTest[0] = '1'; gpcMemAddrTest[1] = 'a'; gpcMemAddrTest[2] = '2'; gpcMemAddrTest[3] = 'b'; gpcMemAddrTest[4] = '\0';

    Cprintf("=====-2   [%p]    [%p]  [%s]\n\n", &gpcMemAddrTest, gpcMemAddrTest, gpcMemAddrTest);

    Cprintf("mmmmm-1   [%p]    [%p]      [%s]\n", &p, p, p);

    MAIN_Memory_c(&p);
    // 此处如果不调用 c 函数，调用 d 函数会是什么样的结果？Why?
    //MAIN_Memory_d(p);

    Cprintf("mmmmm-2   [%p]    [%p]  [%s]\n", &p, p, p);

   // if (1 != setjmp(gstJmpBuffer))
   // {
   //     Cprintf("set jmp fail\n");
   // }

    MAIN_Memory_a(p);
    Cprintf("mmmmm-3   [%p]    [%p]  [%s]\n", &p, p, p);

    Cprintf("\n\n=====-3   [%p]    [%p]  [%s]\n\n", &gpcMemAddrTest, gpcMemAddrTest, gpcMemAddrTest);
#endif

    return;
}


void CPtest_Write(IN ULONG ulLine, IN const char *pszStr, ...)
{
    int ulTmpNum = 0;
    ULONG ulTmpLen = 0;
    char szTmp[512] = {0};
    va_list stParalist;

    QT_ASSERT(NULL != pszStr);

    memset(&stParalist, 0, sizeof(stParalist));

    (void)snprintf(&szTmp[00], 10, "L[%5d] ", (int)ulLine);

    va_start(stParalist, pszStr);
    (void)vsnprintf((char *)&szTmp[9], (sizeof(szTmp) - strlen(szTmp) - 1), (const char *)pszStr, stParalist);
    va_end(stParalist);

    ulTmpLen = strlen(szTmp);
    if ((ulTmpLen + 2) > sizeof(szTmp))
    {
        ulTmpLen = sizeof(szTmp) - 2;
    }

    /* 不同级别显示的颜色不同，打印完成恢复为黑色 */
    printf("%s", szTmp);

    return;
}


