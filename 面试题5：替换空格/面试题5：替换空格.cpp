//题目：请实现一个函数，把字符串中的每个空格替换成%20。
//例如，输入“we are happy.” 则输出“we%20are%20happy.”
//
//需注意的点：是否要在原字符串上修改，内存是否够用

//算法一：在源字符串上修改，从头到尾，遇到空格添加%20
//时间O(n2),空间O(1) 太逊了

//算法二：在源字符串上修改，双指针，从尾到头，遇到空格添加%20
//时间O(n),空间O(1)
//书本源代码：
void ReplaceBlank(char *str, int length)
{
    if(str == nullptr || length <= 0)
        return;
    
    int originalLength = 0;
    int blankNum = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        ++ originalLength;
        if(str[i] == ' ')
            ++ blankNum; 
        
        ++i;
    }
    int newStrLength = originalLength + 2 * blankNum;//这里要有内存意识判断是否会越界
    if(newStrLength > length)
    return;

    while(i >= 0 && newStrLength > i)//newStrLength > i 可以避免无效的复制 
    {
        if(str[i] == ' ')
        {
            str[newStrLength--] = '0';
            str[newStrLength--] = '2';
            str[newStrLength--] = '%';
        }
        else
            str[newStrLenght--] = str[i];
        
        --i;
    }
}

//LeetCode 题解
class Solution{
public:
    string replaceSpace(string s){
        int originalLength = s.length();
        int spaceNum = 0;
        for(int i = 0; i < s.length();++i)
        {
            if(s[i] == ' ')
                spaceNum++;
        }
        s.resize(originalLength + spaceNum * 2);
        int newStrLength =  s.length();
        int originalIndex = originalLength;
        int newIndex = newStrLength;
        while(originalIndex >= 0 && newIndex > originalIndex)
        {
            if(s[originalIndex] == ' ')
            {
                s[newIndex -- ] = '0';
                s[newIndex -- ] = '2';
                s[newIndex -- ] = '%';
            }
            else
                s[newIndex --] = s[originalIndex];
            
            originalIndex --;
        }
        return s;
    }
};