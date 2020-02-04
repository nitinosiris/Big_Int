#timepass2
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a=0,c=0,add=-1;
int sign=-1;
// a and c are for sign
string FindSum(string a1,string a2)
{
    string ans;
    int l1,l2,carry,i;
    reverse(a1.begin(),a1.end());
    reverse(a2.begin(),a2.end());
    l1 = a1.length();
    l2 = a2.length();
    int sum;
    if(l1 == l2)
    {
        carry = 0;
        for(i=0;i<l1;i++)
        {
            sum = (carry + (a1[i]-'0') + (a2[i]-'0'));
            carry = sum / 10;
            ans.push_back(((sum % 10) + '0'));
        }
        if(carry!=0)
        {
            ans.push_back((carry + '0'));
        }
        reverse(ans.begin(),ans.end());
    }
    else if (l1 < l2)
    {
        carry = 0;
        for(i=0;i<l1;i++)
        {
            sum = (carry + (a1[i]-'0') + (a2[i]-'0'));
            carry = sum / 10;
            ans.push_back(((sum % 10) + '0'));
        }
        for(i=l1;i<l2;i++)
        {
            sum = (carry + (a2[i]-'0'));
            carry = sum / 10;
            ans.push_back(((sum % 10) + '0'));
        }
        if(carry!=0)
        {
            ans.push_back((carry + '0'));
        }
        reverse(ans.begin(),ans.end());
    }
    else
    {
        carry = 0;
        for(i=0;i<l2;i++)
        {
            sum = (carry + (a1[i]-'0') + (a2[i]-'0'));
            carry = sum / 10;
            ans.push_back(((sum % 10) + '0'));
        }
        for(i=l2;i<l1;i++)
        {
            sum = (carry + (a1[i]-'0'));
            carry = sum / 10;
            ans.push_back(((sum % 10) + '0'));
        }
        if(carry!=0)
        {
            ans.push_back((carry + '0'));
        }
        reverse(ans.begin(),ans.end());
    }
    return ans;
}
void isSmaller(string str1, string str2)
{
    if(str1[0]=='-')
    {
        a = 1;
        str1.erase(str1.begin() + 0);
    }
    if(str2[0]=='-')
    {
        c = 1;
        str2.erase(str2.begin() + 0);
    }
    int l1,l2,flag=0;
    l1 = str1.length();
    l2 = str2.length();
    if(a == 1 && c==0) //-a - (c) //fine
    {
        add = 1;//add
        sign = 0;//negative
    }
    else if (a==0 && c==1) //a - (-a) //fine
    {
        add = 1;//add
        sign = 1;//positive
    }
    else if(a==0 && c==0) // a-b
    {
        add = 0;//sub
        if(l1<l2)
        {
            sign = 0;//neg
        }
        else if(l1>l2)
        {
            sign = 1;//pos
        }
        else
        {
            if((str1.compare(str2))==0)
            {
                sign  = 1;
            }
            else
            {
                for(int i=0;i<l1 && flag == 0;i++)
                {
                    if(str1[i]<str2[i])
                    {
                        sign = 0;//neg
                        flag = 1;
                    }
                    else if (str1[i]>str2[i])
                    {
                        sign = 1;//pos
                        flag = 1;
                    }
                }
            }
        }
    }
    else//-a - (-c) // -a + c // -25 + 13
    {
        add = 0;//sub
        if(l1<l2)
        {
            sign = 1;//pos
        }
        else if(l1>l2)
        {
            sign = 0;//neg
        }
        else
        {
            if((str1.compare(str2))==0)
            {
                sign  = 1;
            }
            else
            {
                for(int i=0;i<l1 && flag == 0;i++)
                {
                    if(str1[i]<str2[i])
                    {
                        sign = 1;//pos
                        flag = 1;
                    }
                    else if (str1[i]>str2[i])
                    {
                        sign = 0;//neg
                        flag = 1;
                    }
                }
            }
        }
    }
}
string Substraction(string a1,string a2)
{
    int l1,l2,carry,sub;
    string ans,answer;

    l1 = a1.length();
    l2 = a2.length();
    reverse(a1.begin(),a1.end());
    reverse(a2.begin(),a2.end());
    carry = 0;
    for (int i=0; i<l2; i++)
    {
        sub = ((a1[i]-'0')-(a2[i]-'0')-carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        ans.push_back(sub + '0');
    }
    for (int i=l2; i<l1; i++)
    {
        sub = ((a1[i]-'0') - carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        ans.push_back(sub + '0');
    }
    reverse(ans.begin(), ans.end());
    answer = answer + ans;
    return answer;
}
string FindSub(string a1,string a2)
{
    isSmaller(a1,a2);
    string ans;
    if(a1[0]=='-')
    {
        a1.erase(a1.begin() + 0);
    }
    if(a2[0]=='-')
    {
        a2.erase(a2.begin() + 0);
    }
    if(add == 0 && sign == 0)//sub with final sign negative // works fine
    {
        ans = '-' + Substraction(a1,a2);
    }

    else if(add == 0 && sign == 1)//sub with final sign positive //works fine
    {
        ans = Substraction(a1,a2);
    }

    else if(add == 1 && sign == 0)//add with final sign negative //works fine
    {
        ans =  '-' + FindSum(a1,a2);
    }
    else//add with final sign positive// works fine
    {
        ans = FindSum(a1,a2);
    }
    return ans;
}
string Multiply(string a1,string a2)
{
    reverse(a1.begin(),a1.end());
    reverse(a2.begin(),a2.end());
    int l1,l2,i,j;
    l1 = a1.length();
    l2 = a2.length();
    int array[l1+l2];
    for(i=0;i<(l1+l2);i++)
    {
        array[i]=0;
    }
    for(i=0;i<l1;i++)
    {
        for(j=0;j<l2;j++)
        {
            array[i+j] = array[i+j] + ((a1[i]-'0')*(a2[j]-'0'));
        }
    }
    string product;
    int digit,carry;
    for(i=0;i<(l1+l2);i++)
    {
        digit = array[i] % 10;
        carry = array[i] / 10;
        if ((i + 1) < (l1 + l2))
        {
            array[i + 1] = array[i + 1] + carry;
        }
        product =  product + to_string(digit);
    }
    reverse(product.begin(),product.end());
    return product;
}
int main()
{
    string a1,a2;
    int number;
    cout << "Enter the two numbers" << endl;
    cin >> a1;
    cin >> a2;
    cout << "Enter 1 for addition,2 for substraction,3 for multiplication" << endl;
    cin >> number;
    switch (number)
    {
        case 1:cout << FindSum(a1,a2);
            break;
        case 2:cout << FindSub(a1,a2);
            break;
        case 3:cout << Multiply(a1,a2);
            break;
    }
    return 0;
}
