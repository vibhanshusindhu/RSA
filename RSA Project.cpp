#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
string enter_prime()
{
    string str1[]={"567891011121314151617",
            "653061224489795918369",
            "661662663664665666667",
            "666276812967623946997",
            "666666555554444331223",
            "777777775555552323323",
            "786655453628211510631",
            "808793517812627212561",
            "827125343133121974913",
            "841784729676625576529",
            "877666555544444333333",
            "975319753197531975319",
            "11111111111111111011",
            "11138479445180240497",
            "11976506590973322187",
            "12345678901234567891",
            "12345678910987654321",
            "12797382490434158663",
            "12904149405941903143",
            "13080048459073205527"};
    return str1[rand()%20];
}
string add(string str1, string str2)
{
	int n1=str1.length(),n2=str2.length();
    if (n1>n2)
        swap(str1, str2);
    string str = "";
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}
bool small(string str1, string str2)
{
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
    return true;
    if (n2 < n1)
    return false;

    for (int i=0; i<n1; i++)
    if (str1[i] < str2[i])
        return true;
    else if (str1[i] > str2[i])
        return false;

    return false;
}
string multi_prime(string str1,string str2)
{
    int m=str1.length();
    int n=str2.length();
    if (m==0||n==0)
        return "0";
    int result[m+n]={0};
    int i_n1=0,i_n2=0;
    for(int i=m-1;i>=0;i--)
    {
        int carry=0;
        int num1=str1[i]-'0';

        i_n2=0;
        for(int j=n-1;j>=0;j--)
        {
            int num2=str2[j]-'0';
            int sum=(num1*num2)+result[i_n1+i_n2]+carry;
            carry=(sum/10);
            result[i_n1+i_n2]=(sum%10);
            i_n2++;
        }
        if(carry>0)
            result[i_n1+i_n2]+=carry;
        i_n1++;
    }
    int i = (m+n) - 1;
    while (i>=0 && result[i] == 0)
    i--;
    if (i == -1)
    return "0";
    string s = "";

    while (i >= 0)
        s += to_string(result[i--]);

    return s;
}
string plif(string str1,string str2)
{
    string res;
    int m=str1.length();
    int n=str2.length();
    str1[m-1]=(char)(((int)(str1[m-1]))-1);
    str2[n-1]=(char)(((int)(str2[n-1]))-1);
    res=multi_prime(str1,str2);
    return res;
}
string diff(string str1, string str2)
{
    if(small(str1, str2)) swap(str1, str2);
    string str="";
    int n1=str1.length(),n2=str2.length();
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    int carry=0;
    for(int i=0; i<n2; i++)
    {
        int sub=((str1[i]-'0')-(str2[i]-'0')-carry);
        if(sub<0)
        {
            sub=sub+10;
            carry=1;
        }
        else carry=0;
        str.push_back(sub+'0');
    }
    for(int i=n2; i<n1; i++)
    {
        int sub=((str1[i]-'0')-carry);
        if(sub<0)
        {
            sub=sub+10;
            carry=1;
        }
        else carry=0;
        str.push_back(sub+'0');
    }
    reverse(str.begin(), str.end());
    for(int i=0; i<str.length(); i++)
    {
    	if(str[i]!='0') return str.substr(i);
	}
    return "0";
}
bool issmallorequal(string str1, string str2)
{
    int n1 = str1.length(), n2 = str2.length();
    bool z1=true,z2=true;
    for(int i=0; i<n1; i++) if(str1[i]!='0') z1=false;
    for(int i=0; i<n2; i++) if(str2[i]!='0') z2=false;
    if(z1 && z2) return true;
    if (n1<n2) return true;
    if (n2<n1) return false;
    for(int i=0; i<n1; i++)
    	if(str1[i] < str2[i]) return true;
    else if (str1[i] > str2[i]) return false;
    return true;
}
bool isequal(string str1, string str2)
{
    int n1=str1.length(), n2=str2.length();
    bool z1=true,z2=true;
    for(int i=0; i<n1; i++) if(str1[i]!='0') z1=false;
    for(int i=0; i<n2; i++) if(str2[i]!='0') z2=false;
    if(z1 && z2) return true;
    if(n1!=n2) return false;
    for(int i=0; i<n1; i++)
        if(str1[i]!=str2[i]) return false;
    return true;
}
string divide(string num, string div)
{
    string ans="";
    int pos=0;
    string temp="";
    while(pos<num.size())
	{
        if(temp[0]=='0')
            temp[0]=num[pos];
        else
            temp+=num[pos];
        if(small(temp,div))
		{
            if(ans.size()!=0)
                ans+='0';
        }
        else
		{
            for(int i=9;i>=0;i--)
			{
                string t="";
                t+=i+'0';
                if(issmallorequal(multi_prime(t,div),temp))
				{
                    ans+=t;
                    if(isequal(multi_prime(t,div),temp))
                        temp="";
                    else
                        temp=diff(multi_prime(t,div),temp);
                    break;
                }
            }
        }
        pos++;

    }
    if(ans.size()==0)
        return "0";
    return ans;
}
string modulo(string str1,string str2)
{
        return diff(str1,multi_prime(divide(str1,str2),str2));
}
int modulo(string str,int a)
{
    int res = 0;
    for (int i = 0; i < str.length(); i++)
         res = (res*10 + (int)str[i] - '0') %a;

    return res;
}
string power(string str,int n)
{
    if(n==0)
        return "1";
    if(n==1)
        return str;
    string temp=power(str,n/2);
    if(n%2==0)
        return multi_prime(temp,temp);
    else
        return multi_prime(str,multi_prime(temp,temp));
}
string power(string x,string e,string n)
{

    if(e=="0")
        return "1";
    if(e=="1")
        return modulo(x,n);
    string temp = modulo(power(x,divide(e,"2"),n),n);

    if(isequal(modulo(e,"2"),"0"))
        return modulo(multi_prime(temp,temp),n);
    else
        return modulo(multi_prime(x,modulo(multi_prime(temp,temp),n)),n);

}
string gcd(string a, string b)
{
    if (b=="0")
        return a;
    return gcd(b, modulo(a,b));
}
string enc(string phi_n)
{
    string e="3";
    while(1)
    {
        if(isequal(gcd(e,phi_n),"1")==1)
			break;
        e=add(e,"2");
    }
    return e;
}
string dec(string phi_n,string e)
{
    string k="1",d;
    while(1)
    {
        if(isequal(modulo(add("1",multi_prime(k,phi_n)),e),"0"))
        {
            d=divide(add("1",multi_prime(k,phi_n)),e);
            break;
        }
        k=add(k,"1");
    }
    return d;
}
string strtonum(string s)
{
    string ans="";
    for(int i=s.length()-1,k=0;i>=0;i--,k++)
	{
        int t=s[i]+0;
        string temp;
        while(t!=0)
		{
            temp+=t%10+'0';
            t/=10;
        }
        reverse(temp.begin(),temp.end());
        ans=add(ans,multi_prime(power("128",k),temp));
    }
    return ans;
}
string numtostr(string str)
{
    string ans="";
    string n=str;
    while(!small(n,"128"))
	{
        ans+=modulo(n,128);
        n=divide(n,"128");
    }
    ans+=modulo(n,128);
    reverse(ans.begin(),ans.end());
    return ans;
}
string encrypted(string msg,string e,string n)
{
    string c,msgnum;
    msgnum=strtonum(msg);
    c=modulo(power(msgnum,e,n),n);
    cout<<"Encrypted."<<endl;
    return c;
}
string decrypted(string c,string d,string n)
{
    string m,dnum;
    dnum=modulo(power(c,d,n),n);
    m=numtostr(dnum);
    return m;
}
int main()
{
    cout<<"\t\t"<<"                              RSA Cryptography Program\n\n\tDone by:\n\tMayand Kumar\n\tMadhur Vaidya\n\tVibhanshu Singh Sindhu\n\tMarco Manyang Monydit\n\n";
    srand(time(0));
    string str1,str2,n,phi_n,e,d,msg,c,m;
    //cout<<"Taking the 1st prime no.=";
    str1=enter_prime();
    //cout<<str1<<endl;
    //cout<<"\nTaking the 2nd prime no.=";
    str2=enter_prime();
    //cout<<str2<<endl<<endl;
    n=multi_prime(str1,str2);
    //cout<<n<<endl;
    phi_n=plif(str1,str2);
    //cout<<phi_n<<endl;
    e=enc(phi_n);
    //cout<<e<<endl;
    d=dec(phi_n,e);
    //cout<<d<<endl;
    here:
    cout<<"\nEnter the message for encryption:";
    getline(cin,msg);
    c=encrypted(msg,e,n);
    cout<<"\n\nThe encrypted message is:"<<c;
    m=decrypted(c,d,n);
    cout<<"\n\nThe Decrypted message is:"<<m;
    cout<<"\nDecrypted."<<endl;
    cout<<"New Message? (y/n)";
    if(getch()=='y'||getch()=='Y')
        goto here;
    return 0;
}
