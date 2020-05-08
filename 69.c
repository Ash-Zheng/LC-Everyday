class Solution {
public:
    int helper(int l,int r,int x)
    {
        if(r<=l)return l;
        long long mid=(l+r)>>1;
        long long t=mid*mid;
        if(t>x)return helper(l,mid,x);
        else return helper(mid+1,r,x);
    }
    int mySqrt(int x) {
        int mid=x>>1;
        if(x>4)mid=helper(0,mid,x);
        else mid=helper(mid,x,x);
        long long t=(long long)mid*mid;
        if(t>x)return mid-1;
        else return mid;
    }
};