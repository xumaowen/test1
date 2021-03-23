
#include "QtSysBasic.h"
#include <setjmp.h>
#include <map>
#include <vector>


/* �Զ���һ�������ռ� */
namespace stdTest
{

    //ʵ��endl 
    template<class T>
    inline const T &endl(const T &op)
    {
        op.flush();  //����flush����
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

        /* ���õĵط� ��Ϊconst�ͣ��������޸������ݣ� �������Ա��������const���ͣ�����������Ϊ�ú������޸������ݵ����ɣ��ᱨ�� */
        void flush() const
        {
            printf("\n");
            return;
        }

        void test1() { bPA = 0; return; }

        /* ������Ա��������Ϊconst����ú����������޸�������ݳ�Ա, ���ǽ���Ա��������Ϊmutables */ 
        // const �� ��const Ҳ���Ի�������
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
            return (*pfun)(*this);  //���ݺ���ָ����ú���
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

        /* ��ӡ�к� */
        const MyOstream& PL (unsigned long ulLine) const
        {
            printf("L[%5d] ", (int)ulLine);
            clearaddr();
            
            return *this;
        }

    };

    MyOstream cout;
}


/* using namespace std ��ʾ�����еı�׼�⺯�����ڱ�׼�����ռ�std�н����˶��塣����std��ʾ��׼�����ռ�����֡�
   ���������þ����ڱ��ⷢ��������������() ������� stdTest �����ռ� , ���� cout �ͻᱨ�� */
using namespace std;
//using namespace stdTest;

/* �Զ������ռ� */
namespace InheritTest
{

void namespacetest()
{
    Cprintf("using InheritTest namespace\n");
}

/* �˴�������һ������,��������������������(�����޴�����) */
class MAIN_Friend;
class MAIN_Test;

/* ��������Ԫ�������� */
ULONG FriendFun3(IN MAIN_Test &clsMainClass, IN MAIN_Friend &clsFriendClass);


/* ���� */
class MAIN_GrandPa
{
public:
    MAIN_GrandPa(IN ULONG ulTmp = 0);
    ~MAIN_GrandPa(void);

    ULONG pubulGrandPaA;
    static ULONG pubulStaticTest;  /* ��̬����,�����ڶ����ͬ��Ķ���֮���ͨ�� */

    /* ���������(��α��뱾����������,�Ҳ�����Ĭ�ϲ���) */
    ULONG operator + (IN MAIN_GrandPa &clsTmp1);
    ULONG operator - (IN ULONG &ulTmp1);

protected:
    ULONG proulGrandPaB;

private:
    ULONG priulGrandPaC;
};

/* ����:˽�м̳��丸��,ֻ�ܷ��ʸ���Ĺ��г�Ա(����Ĺ��г�Ա���Ǹ����˽�г�Ա) */
class MAIN_Father : private MAIN_GrandPa
{
public:
    typedef MAIN_GrandPa Superclass;
    MAIN_Father(IN ULONG ulTmp = 1);
    ~MAIN_Father(void);

    ULONG pubulParentA;
    virtual void virtualTest(void); /* �麯�� */

protected:
    ULONG proulParentB;

private:
    ULONG priulParentC;
    UCHAR *pszTmp;
    class MAIN_Friend *pstClass;
};

/* ����:���м̳��丸��,ֻ�ܷ��ʸ���Ĺ��г�Ա��������Ա */
class MAIN_Test : public MAIN_Father
{
public: /* �������ǹ��г�Ա���κ�����¾��ɷ��� */

    MAIN_Test(IN int x = 0, IN int y = 0);  /* C++ �����������캯��,���ݵ������ѡ��ʹ���ĸ� */
    MAIN_Test(IN CHAR *pszTmp = NULL);      /* ���캯�� */
    ~MAIN_Test( );                  /* �������� */

    void virtualTest(void);         /* ���౻����Ϊ�麯��,�����Զ�ת��Ϊ�麯�� ����Ҫvirtual */
    /* �����������ھ�̬��̬��,����ʱ�������ĸ� */
    /* �麯�����ڶ�̬��̬��,����ʱ�������ĸ� */
    /* ��virtual ȥ��,�������û���ĵ�ַ���ִ�ӡ����ĺ��� */

    ULONG pubulChildrenA;
    ULONG TEST_Public_Fun1(IN ULONG ulA, IN ULONG ulB); /* ���г�Ա���� */

    friend ULONG FriendFun1(IN MAIN_Test &clsTmp);    /* ��һ����Ԫ����:������ⲿͨ������������ʸ����˽�г�Ա */
    ULONG FriendFun2(IN MAIN_Friend &clsFriendClass); /* �ڶ�����Ԫ����:ͨ�����������������������г�Ա */

    /* ��������Ԫ����:��һ���������κ������ͨ��������Ϊ��������Ԫ����,�ú������Է��ʶ�����˽�г�Ա */
    friend ULONG FriendFun3(IN MAIN_Test &clsMainClass, IN MAIN_Friend &clsFriendClass);

    ULONG TEST_FunPultectAdd(IN ULONG ulTmp1, IN ULONG ulTmp2);  /* ��������,ͨ����������� */
    ULONG TEST_FunPultectAdd(IN DOUBLE dTmp1, IN DOUBLE dTmp2);  /* ��������,ͨ����������� */

protected: /* �������Ǳ�����Ա��ֻ��������ڲ��Լ���������ڲ��������������ⲻ�ܷ��� */
    ULONG proulChildrenB;
    string prostrTmp1;
    string prostrTmp2[36];
    UCHAR  prouszTmp3[36];

private:   /* ��������˽�г�Ա��ֻ��������ڲ���������������Ҳ���ܹ����� */
    ULONG priulChildrenC;
    string pristrTmp1;
    UCHAR priuszTmp1[36];
    char *pripszTmp;
    ULONG TEST_FunPrivate(void);

};


/* ����һ��������,��Ҫ������Ԫ����ѧϰ */
class MAIN_Friend
{
public:
    MAIN_Friend(void);
    ~MAIN_Friend(void);

    ULONG pubulFriendA;

    /* �ڶ�����Ԫ����:ͨ�����������������������г�Ա */
    friend ULONG MAIN_Test::FriendFun2(IN MAIN_Friend &clsFriendClass);

    /* ��������Ԫ����:��һ���������κ������ͨ��������Ϊ��������Ԫ����,�ú������Է��ʶ�����˽�г�Ա */
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

/* ģ���� */
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

/* ģ������� new */
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

/* ���ڴ��� ��������/�㷨 ��ģ��(������������������) */
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

/* ��cls_T_COREģ�����õĹ����� */
template <typename T>
class cls_corefun1
{
public:
    cls_corefun1() {return;}
    ~cls_corefun1(){return;}

    // ʵ������ת�ַ�������
    T operator()(T x)
    {
        x.ToChar(48);
        return x;
    }

private:
};

/* ��cls_T_COREģ�����õ������� */
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

    // ����һ�������
    T Get(void)
    {
        T a;
        a.numInit();
        slsData.push_back(a);
        ulCurLen++;
        return slsData[ulCurLen - 2];
    }

    // �洢һ�������ַ�
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

/* new cls_T_COREģ�������ʵ�� */
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

/* ģ���� */
template <class Type>
clsTmpLate1<Type>::clsTmpLate1()
{
    iMaxNum = 2;

    /* ���ַ���������ڴ���Ϣ�����ã����޷�ʹ��sizeof() ��������ռ�õ��ڴ��С */
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

/* �������� */
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

/* ģ������Ϊ���� */
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

/* ������ľ�̬����������CPP�ļ�������һ���������ڴ�,��������ͬ�๲����һ���ڴ� */
ULONG MAIN_GrandPa::pubulStaticTest;

/* ���๹�캯�� */
MAIN_GrandPa::MAIN_GrandPa(IN ULONG ulTmp)
{
    /* ��ʼ�������Ա */
    pubulGrandPaA = 101;
    proulGrandPaB = ulTmp;
    priulGrandPaC = 103;
    UCHAR szEndSize[4] = {2, 1, 0, 0};
    ULONG *pulEndSize = (ULONG *)szEndSize;


    /* �ֽڶ������ */
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

    stdTest::cout.PL(__LINE__) << "End Size : " << ((*pulEndSize == 258) ? "small end" : "big end") << stdTest::endl;    // ��Ϊ�������С����?
    stdTest::cout.PL(__LINE__) << "Byte alignment : " << sizeof(DUIQI_A_S) << " ?= " << sizeof(DUIQI_B_S) << stdTest::endl; // ����Ƿ���ͬ? WHY?
    Cprintf("GrandPa Class Create");

    return;
}

/* �����(+��)���� */
ULONG MAIN_GrandPa::operator + (IN MAIN_GrandPa &clsTmp1)
{
    ULONG ulTmp = 0;

    ulTmp = proulGrandPaB + clsTmp1.proulGrandPaB;
    Cprintf("A(%lu) + B(%lu) = C(%lu)\n", proulGrandPaB, clsTmp1.proulGrandPaB, ulTmp);

    return ulTmp;
}

/* �����(-��)���� */
ULONG MAIN_GrandPa::operator - (IN ULONG &ulTmp1)
{
    ULONG ulTmp = 0;

    ulTmp = proulGrandPaB - ulTmp1;
    Cprintf("A(%lu) - Input(%lu) = C(%lu)\n", proulGrandPaB, ulTmp1, ulTmp);

    return ulTmp;
}


/* ������������ */
MAIN_GrandPa::~MAIN_GrandPa(void)
{
    Cprintf("GrandPa Class Delete\n");

    return;
}

/* ���๹�캯�� */
MAIN_Father::MAIN_Father(IN ULONG ulTmp): Superclass(ulTmp), pubulParentA(ulTmp)
{
    MAIN_GrandPa *clsOperatorA = new MAIN_GrandPa(125); /* �����ಢ���ù��캯�� */

    /* ��׼���а���һ����Ϊallocator���࣬�������ǽ�����ͳ�ʼ�����롣ʹ��allocatorͨ�����ṩ���õ����ܺ͸������ڴ�������� */
    allocator<MAIN_GrandPa> clsOperatorB;
    //auto const p = clsOperatorB.allocate(2); /* ����2����ṹ/���飬ֻ�����ڴ棬�����ù��캯�� */
    MAIN_GrandPa *p = clsOperatorB.allocate(2); /* ͬ�� */

    /* ���ù��캯�� */
    auto q = p;
    clsOperatorB.construct(q++, 126);
    clsOperatorB.construct(q, 127);


    /* �����ڴ�/�ͷ��ڴ� */
    vector<int> v1{1, 2, 3, 4, 5};
    int* p1 = (int *)allocator<int>().allocate(v1.size() * 2); 
    auto p2 = std::uninitialized_copy(v1.begin(), v1.end(), p1);  //  ͨ�������ķ�ʽ��ʼ�����ݣ����ؿ����ڴ����һ����ַ
    std::uninitialized_fill_n(p2, v1.size(), 42); // ��ʣ�����ֵ���Ϊ42
    p1[2] = 6; // ֱ���޸�Ԫ��


    /* ˽�м̳л����public���Գ�Ա�������г���private����(�����̳�����) */
    pubulParentA = pubulGrandPaA * ulTmp;

    /* ˽�м̳л����protected���Գ�Ա�������г���private���� */
    proulParentB = proulGrandPaB;

    /* ˽�м̳в�������ʻ���˽�г�Ա,������뱨��  */
  //  priulParentC = priulGrandPaC;

    /* ���������ʵ�� */
    priulParentC = (*clsOperatorA) + p[0];
    priulParentC = p[0] - proulParentB;

    /* ��̬�������/���� */
    pstClass = new MAIN_Friend;
    pszTmp = new UCHAR[10];

    /* �����ͬ�����ľ�̬��������һ���ڴ�ռ� */
    class MAIN_GrandPa clsA;
    clsA.pubulStaticTest++;
    Cprintf("Static Value Test [%lu]\n", MAIN_GrandPa::pubulStaticTest);
    class MAIN_GrandPa clsB;
    clsB.pubulStaticTest++;
    Cprintf("Static Value Test [%lu]   priulParentC = [%lu]   %d-%d\n", clsB.pubulStaticTest, priulParentC, p1[1], p1[7]);

    stdTest::cout.PL(__LINE__) << "Father Class Create" << (stdTest::endl);

    /* ������������ */
    while (q != p)
    {
        clsOperatorB.destroy(--q);
    }

    /* ���������ڴ� */
    clsOperatorB.deallocate(p, 2);
    allocator<int>().deallocate((int *)p1, v1.size() * 2);

    return;
}

/* �麯�� */
void MAIN_Father::virtualTest(void)
{
    stdTest::cout.PL(__LINE__) << "virtual test Father" << stdTest::endl;
    return;
}


/* ������������ */
MAIN_Father::~MAIN_Father(void)
{
    /* ɾ����̬����ı��� */
    delete pstClass;

    /* pszTmpΪ����, ����[] �����ͷŵ�һ���ֽ�,������ڴ��Դ���ռ��״̬ */
    delete [] pszTmp;

    stdTest::cout.PL(__LINE__) << "Father Class Delete" << stdTest::endl;

    return;
}


/* ���๹�캯�� */
MAIN_Test::MAIN_Test(IN int x, IN int y) : MAIN_Father(x), pubulChildrenA(x)
{
    pripszTmp = NULL;

    /* ���м̳и����public���Գ�Ա�������г���public���� */
    pubulChildrenA = pubulParentA;

    /* ���м̳и����protected���Գ�Ա�������г���protected���� */
    proulChildrenB = proulParentB;

    /* ���಻�ܷ��ʸ���˽�г�Ա*/
  // priulChildrenC = priulParentC;

    /* ���಻�ܷ��ʸ���˽�м̳еĹ��г�Ա */
//    priulChildrenC = pubulGrandPaA;
    priulChildrenC = (x * y);

    stdTest::cout.PL(__LINE__) << "Children Class Create\n\n" << stdTest::endl;

    return;
}

/* ���๹�캯�� */
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

    /* �ַ���ƴ�� */
    strTmp = pszTmp + pristrTmp1;

    /* �ַ���׷�� */
    pristrTmp1 += pszTmp;

    stdTest::cout.PL(__LINE__) << "uszProtectTmp1:" << prouszTmp3 << "strTmp:" << pristrTmp1 << stdTest::endl;
    stdTest::cout.PL(__LINE__) << "Children Class Create\n\n" << stdTest::endl;

    return;
}

/* �麯�� */
void MAIN_Test::virtualTest(void)
{
    stdTest::cout.PL(__LINE__) << "virtual test Child" << stdTest::endl;

    return;
}

/* ���๫�г�Ա���� */
ULONG MAIN_Test::TEST_Public_Fun1(IN ULONG ulA, IN ULONG ulB)
{
    stdTest::cout.PL(__LINE__) << "MAIN Public Fun1\n" << stdTest::endl;

    return (ulA * ulB);
}

/* ���๫�г�Ա���� */
ULONG MAIN_Test::TEST_FunPultectAdd(IN ULONG ulTmp1, IN ULONG ulTmp2)
{
    ULONG ulAdd = 0;

    ulAdd = ulTmp1 + ulTmp2;
    stdTest::cout.PL(__LINE__) << " Protect Funs Add[ULONG] = " << ulAdd << stdTest::endl;

    return ulAdd;
}

/* ���๫�г�Ա����(����) */
ULONG MAIN_Test::TEST_FunPultectAdd(IN DOUBLE dTmp1, IN DOUBLE dTmp2)
{
    DOUBLE dAdd = 0;

    dAdd = dTmp1 + dTmp2 + 0.5;
    stdTest::cout.PL(__LINE__) << " Protect Funs Add[DOUBLE] = " << (ULONG)dAdd << stdTest::endl;

    return (ULONG)dAdd;
}


/* ����˽�г�Ա���� */
ULONG MAIN_Test::TEST_FunPrivate(void)
{
    stdTest::cout.PL(__LINE__) << " Protect Funs " << stdTest::endl;

    return 0;
}

/* ������������ */
MAIN_Test::~MAIN_Test(void)
{
    delete [] pripszTmp;

    stdTest::cout.PL(__LINE__) << "\n\nChildren Class Delete" << stdTest::endl;

    return;
}

/* ���๹�캯�� */
MAIN_Friend::MAIN_Friend(void)
{
    pubulFriendA = 22;
    proulFriendB = 23;
    priulFriendC = 24;

    stdTest::cout.PL(__LINE__) << "Friend Class Create" << stdTest::endl;

    return;
}

/* ������������*/
MAIN_Friend::~MAIN_Friend(void)
{
    stdTest::cout.PL(__LINE__) << "Friend Class Delete" << stdTest::endl;

    return;
}

void reference_test(int &a)
{
    // ָ��û�м������ƣ�����ֻ��һ��
    long double test1 = 1.1; 
    long double &test2 = test1;
    
    Cprintf("%d  %x  %d  %d\n", a, &a, (int)sizeof(test1), (int)sizeof(test2));

    return;
}

/* ����& ��ָ��* ������ 1.ָ�봫������ε�ԭʼ��ַ�������ڲ���  2.����û�д��ݵ�ַ������εĲ������Ƕ�ԭʼ���ݵĲ������൱��ԭʼ���ݵı���,ָ���൱��ʵ�� */
/* ��һ����Ԫ���� */
ULONG FriendFun1(IN MAIN_Test &clsTmp)
{
    int a = 10;
    int &b = a;

    b = 11;
    b++;
    Cprintf("reference test  %d  %d  %x\n", a, b, &a);
    reference_test(a);

    /* ��Ԫ�������ʶ����˽�г�Ա */
    Cprintf("FriendFun[1] Access pubA[%lu] proB[%lu] priC[%lu]\n",
           clsTmp.pubulChildrenA, clsTmp.proulChildrenB, clsTmp.priulChildrenC);
    clsTmp.pubulChildrenA = 12354;

    return 0;
}

/* �ڶ�����Ԫ���� */
ULONG MAIN_Test::FriendFun2(IN MAIN_Friend &clsFriendClass)
{
    /* MAIN_Test�� ���� MAIN_Friend�� ��˽�г�Ա */
    priulChildrenC = clsFriendClass.priulFriendC;

    Cprintf("FriendFun[2] Access priC[%lu]\n", priulChildrenC);

    return 0;
}

/* ��������Ԫ���� */
ULONG FriendFun3(IN MAIN_Test &clsMainClass, IN MAIN_Friend &clsFriendClass)
{
    /* ���ʶ�����˽�г�Ա */
    Cprintf("FriendFun[3] Access Class1 priC[%lu]  Class2 priC[%lu]\n",
           clsMainClass.priulChildrenC, clsFriendClass.priulFriendC);

    return 0;
}
}// end namespace

namespace newTemplateTest
{

/* ģ���� */
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

    /* Map��һ�ֹ����������������ض�˳��洢�ɼ�ֵKey��ӳ��ֵValue��϶��ɵ�Ԫ�� */
    typedef std::map<char, int> SRMAP_T;
    SRMAP_T maptest1;

    maptest1['A'] = 10;
    maptest1['B'] = 11;
    maptest1['C'] = 12;
    maptest1['D'] = 13;
    maptest1['E'] = 12;

    maptest1.at('A') = 201;  // �޸Ĳ���

    /* ����Ԫ�� */
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
    maptest1.emplace(c1, 100);   //����Ԫ��

    std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> pairtest1;

    // ����Ҳ�����ֵ��k��ȵ�Ԫ�أ���������������ָ������k֮��ĵ�һ��Ԫ�ء�
    pairtest1 = maptest1.equal_range('A');

    stdTest::cout.PL(__LINE__) << "lower points to: " << pairtest1.first->first << " => " << pairtest1.first->second << stdTest::endl;
    stdTest::cout.PL(__LINE__) << "upper points to: " << pairtest1.second->first << " => " << pairtest1.second->second << stdTest::endl;

    SRMAP_T::iterator itlow, itup;

    itlow = maptest1.lower_bound('B');  // ָ�������е�һ����ֵ���� k ������ k ֮���Ԫ�� itlow points to B
    itup = maptest1.upper_bound('D');   // �������е�һ����ֵ���� k ֮���Ԫ�� itup points to E (not D!)

    maptest1.erase(itlow, itup);        // erases [itlow, itup]

    for (std::map<char, int>::iterator it = maptest1.begin(); it != maptest1.end(); ++it)
    {
        stdTest::cout.PL(__LINE__) << it->first << " => " << it->second << stdTest::endl;
    }

    /* begin ����һ����������ָ���һ��Ԫ��, end����һ����������ָ��β��Ԫ�� */
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
           maptest3[11].i2test1,        // ���� TemplateTest ��ֵ
           maptest3.find(11)->second.i2test1,
           maptest4['C'], maptest5['E']);

    c1 = 'F';  // try 'W'
    Cprintf("'%c' %s\n", c1, maptest5.count(c1) > 0 ? "is an element of Map" : "is not an element of Map");

    /* ��ֵ�Ƚ� */
    std::map<char, int>::key_compare map_key_comp = maptest1.key_comp();
    tmp = maptest1.begin();
    do
    {
        stdTest::cout.PL(__LINE__) << tmp->first << " +=> " << tmp->second << stdTest::endl;
    }
    while (map_key_comp((*tmp++).first, 'E'));

    /* ��ֵ�Ƚ� */
    std::pair<char, int> target1('E', 12);
    tmp = maptest1.begin();
    do
    {
        stdTest::cout.PL(__LINE__) << tmp->first << " -=> " << tmp->second << stdTest::endl;
    }
    while (maptest1.value_comp()(*tmp++, target1));


    /* pair�ǽ�2��������ϳ�һ�����ݣ�����Ҫ����������ʱ�Ϳ���ʹ��pair */
    std::pair<int, char> p1(1, 's');
    stdTest::cout.PL(__LINE__) << p1.first << ' ' << p1.second << stdTest::endl;

//-------------------------------< vector >----------------------------------

    std::vector<int> vec_test1(4, 101);
    std::array<int, 12> arGroup = {7,6,5,4,3,2,3,24,25,26,27};
    int aiInts[] = {16, 21, 77, 29};
    std::vector<int> vec_test2(aiInts, aiInts + sizeof(aiInts) / sizeof(int));
    std::vector<int> vec_test3(vec_test2);    // a copy of third
    vec_test3.push_back(102);     // ��������
    vec_test3.push_back(103);
    vec_test3[1] = 23;            // �޸�����
    int *p2 = vec_test3.data();
    *(p2++) = 123;                // �޸�����
    arGroup[1] = arGroup.size();
    std::vector<T> vec_test7(2, c);

    /* ɾ��ָ��Ԫ�� */
    for (std::vector<int>::iterator it = vec_test3.begin(); it != vec_test3.end(); )
    {
        if (103 == *it)
        {
            // remove() û��ɾ��Ԫ��ֻ��Ԫ�ص��滻
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

    /* ��ֵ */
    k = 0;
    for (SRMAP_T::iterator it = maptest1.begin(); it != maptest1.end(); ++it, k++)
    {
        vec_test6[k] = it;
        vec_test6.at(k) = it;
    }

    std::vector<SRMAP_T::iterator>::iterator it_1;
    it_1 = vec_test6.begin();
    it_1 = vec_test6.insert(it_1, tmp2);   // �������� �� tmp2������ָ�򣬷���insert�δ���
    vec_test6.insert(it_1, 2, tmp2);

    /* ���� */
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

/* �������� */
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
    //clsTmpLate2<MAIN_Test2> test4;  clsTmpLate2�� <>��α�����ģ����

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

    /* �ֱ����������Ԫ���� */
    InheritTest::FriendFun1(stTest1[0]);
    stTest1[0].FriendFun2(stFriend);
    InheritTest::FriendFun3(stTest1[0], stFriend);

    /* ����ʹ�÷ǹ��г�Ա����ʧ�� */
  //stTest1.TEST_Protect( );
  //stTest1.TEST_Private( );

    /* �������ѡ���Ӧ���캯�� */
    InheritTest::MAIN_Test stTest2((CHAR *)"asdffhjgfhf123443");

    /* �������غ���(���������ѡ��) */
    stdTest::cout.PL(__LINE__) << "Double Add Double Is : " << stTest2.TEST_FunPultectAdd(2.1, 3.4) << stdTest::endl;

    /* �麯������ ������ǰ��virtual ȥ����һ�� */
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

    // �ͷ��ڴ� ���ǽ��ָ�����ǿ��ڴ滹������ϵͳ
    // �ͷ��ڴ治��������ڴ汻�� 0 �������ƽ̨���죬X86ƽ̨һ�����0����ARM�ܹ����绪ΪHISI3616�ṩ�ı����������ڴ��Ͳ������㣩
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
    /* �ڴ��ַ�任���� */
#if 0
    char *p = NULL;
    int a[5] = {1,2,3,4,5};
    int *ptr = (int *)(&a + 1);

    Cprintf("%d,%d\n", *(a + 1), *(ptr - 1));  // why?

    Cprintf("=====-1   [%p]    [%p]  [%s]\n", &gpcMemAddrTest, gpcMemAddrTest, gpcMemAddrTest);

    /* �ڶ��Ϸ���16�ֽ��ڴ�  */
    gpcMemAddrTest = (char *)QT_Malloc(16);

    gpcMemAddrTest[0] = '1'; gpcMemAddrTest[1] = 'a'; gpcMemAddrTest[2] = '2'; gpcMemAddrTest[3] = 'b'; gpcMemAddrTest[4] = '\0';

    Cprintf("=====-2   [%p]    [%p]  [%s]\n\n", &gpcMemAddrTest, gpcMemAddrTest, gpcMemAddrTest);

    Cprintf("mmmmm-1   [%p]    [%p]      [%s]\n", &p, p, p);

    MAIN_Memory_c(&p);
    // �˴���������� c ���������� d ��������ʲô���Ľ����Why?
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

    /* ��ͬ������ʾ����ɫ��ͬ����ӡ��ɻָ�Ϊ��ɫ */
    printf("%s", szTmp);

    return;
}


