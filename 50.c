class Solution {
public:
    double pows(double x,long long N)
    {
        if (N == 0) {
            return 1.0;
        }
        double y = pows(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        if(n==0)return 1.0;
        long long N=n;
        if(n<0)return 1/pows(x,-N);
        else return pows(x,N);
    }
};