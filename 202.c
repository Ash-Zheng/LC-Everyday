class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n!=1&&set.count(n)==0)
        {
            set.insert(n);
            int temp=n,a,sum=0;
            while(temp>0)
            {
                a=temp%10;
                temp/=10;
                sum+=a*a;
            }
            n=sum;          
        }
        if(n==1)return true;
        else return false;
    }
};