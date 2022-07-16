
#include<bits/stdc++.h>

using namespace std;

template<typename T>

void print(vector<T> vec)
{
    for(int i = 1; i < vec.size(); i++)
        cout << vec[i] << ", ";
    cout<<endl;
}

int findSum(string s, char c)
{
    int sum=0;
    vector <string> tokensVector;
    vector<int> negativesVector;
    stringstream check1(s);

    string tempString;
    
    while(getline(check1, tempString, c))
    {
            tokensVector.push_back(tempString);
    }
    
    for(int i=1;i<tokensVector.size();i++)
    {
        int t = stoi(tokensVector[i]);
        
        if(t >= 0)
        {
            int temp = stoi(tokensVector[i]);
            sum = sum + temp; 
        }
        else
        {
            int temp = stoi(tokensVector[i]);
            negativesVector.push_back(temp);
        }
    }

    if(negativesVector.size()!=0)
    {
        sum=-1;
        cout<<"Negatives not allowed !\n";
        print(negativesVector);
    }
    return sum;
}

int Add(string numbers)
{
    regex reg1("(//[;,-]\n)((-)?([0-9]+)([;,-]))*(-)?([0-9]+)");
    
    regex reg2("(((-)?[0-9]+)([,]))*(-)?([0-9]+)");
    
    if ( regex_match(numbers,reg1) )
    {
        return findSum(numbers,numbers[2]);
    }
    else if(regex_match(numbers,reg2))
    {
        int sum=0;
        vector <string> tokensVector;
        vector<int> negativesVector;
        
        stringstream check1(numbers);
    
        string tempString;
        
        while(getline(check1, tempString, ','))
        {
                tokensVector.push_back(tempString);
        }
        
        for(int i=0;i<tokensVector.size();i++)
        {
            int t = stoi(tokensVector[i]);
            if(t >= 0)
            {
                int temp = stoi(tokensVector[i]);
                sum = temp + sum;
            }
            else
            {
                int temp = stoi(tokensVector[i]);
                negativesVector.push_back(temp);
            }
        }

        if(negativesVector.size()!=0)
        {
            sum=-1;
            cout<<"Negatives not allowed !\n";
            print(negativesVector);
        }

        return sum;
    }
    else
    {
        cout<<"Invalid !\n";
        return -1;
    }
}

int main()
{
    string s1,s2;
    int ans;
    cin>>s1;
     //if s1 is starting from // and delimiter (Ex. //; and delimiter is ;)  then take s2
    if(s1[0]=='/' && s1[1]=='/')
    {
        cin>>s2;
        ans=Add(s1+"\n"+s2); // if s2 is 1;2 then final string become //;\n1;2 and pass to Add
    }
    else
        ans=Add(s1);// if string s1 which contain comma(,) as delimiter

    if(ans!=-1)
        cout<<ans<<endl;
    return 0;
}