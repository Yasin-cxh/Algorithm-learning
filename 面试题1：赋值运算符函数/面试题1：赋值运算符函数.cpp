#include<cstring>
#include<cstdio>

class CMyString
{
public:
    CMyString(char *pData= nullptr);
    CMyString(const CMyString &str);
    ~CMyString(void);

    CMyString& operator = (const CMyString &str);
    void Print();
private:
    char* m_pData = nullptr;
};

CMyString::CMyString(char *pData)
{
    if(pData == nullptr){
        m_pData = new char[1];
        //new 的时候要考虑异常吧？
        m_pData[0] = '\0';
    } else {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData,pData);
    }
}
//这也是构造函数
CMyString::CMyString(const CMyString &str)
{
    if(m_pData != nullptr)
        delete[] m_pData;
    m_pData = nullptr;
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData,str.m_pData);
    
}

CMyString::~CMyString()
{
    delete[] m_pData; 
}

CMyString& CMyString::operator =(const CMyString &str)
{
    //1.先判断是不是同个对象，是返回当前对象，不是继续
    //2.先删除当前内存
    //3.分配内存，拷贝
    //4.返回当前对象
    if(this == &str){
        return *this;
    }
    delete[] m_pData;
    m_pData = nullptr;
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData,str.m_pData);
    return *this;
}

void CMyString::Print()
{
    printf("%s",m_pData);
}

//赋值给其他对象
void Test1()
{
    printf("Test1 begins:\n");
    char *text = "Hello World";
    CMyString str1(text);
    CMyString str2;//这会执行哪个构造函数？默认构造函数
    printf("The expected result is:%s.\n",text);
    printf("The actual result is :");
    str2.Print();
    printf(".\n");
}

//赋值给自己
void Test2()
{
    printf("Test2 begins:\n");
    char *text = "Hello World";
    CMyString str1(text);
    str1 =str1;
    printf("The expected result is:%s.\n",text);
    printf("The actual result is :");
    str1.Print();
    printf(".\n");
}

//连续赋值
void Test3()
{
    printf("Test3 begins:\n");
    char *text = "Hello world";
    CMyString str1(text);
    CMyString str2(str1);
    CMyString str3;
    CMyString str4;
    str4 = str3 = str1;
    printf("The expected result is: %s.\n",text);
    printf("The actual result is: \n");
    str2.Print();
    printf(".\n");
    str3.Print();
    printf(".\n");
    str4.Print();
    printf(".\n");
}

int main(int argc, char* argv[]){
    Test1();
    Test2();
    Test3();
    return 0;
}