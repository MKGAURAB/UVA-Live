/*
 *  6076 - Yukari's Birthday.cpp
 *
 *  Created on: 2014-10-15-21.56.46, Wednesday
 *      Author: Md. Khairullah gaurab
 */
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int INF = 2000000000;
const int MOD = 10007;

typedef long long Long;
typedef double DD;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define sf          scanf
#define pf          printf
#define mem(a,b)    memset(a,b,sizeof(a))
#define pb          push_back
#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define REPI(i,a,b,c) for(int i=a; i<=b; i+=c)
#define REPR(i,a,b) for(int i=b; i>=a; --i)
#define REPRD(i,a,b,c) for(int i=b; i>=a; i-=c)
#define mp(a,b)     make_pair(a,b)
#define fs          first
#define sc          second
#define SZ(s)       ((int)s.size())
#define PI          3.141592653589793
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<DD>
#define VL          vector<Long>
#define VVL         vector<VL >
#define lim         40010
#define tlim        (1<<(ceil(log2(lim))+1))
#define unq(vec)    stable_sort(vec.begin(),vec.end());\
                    vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(BE(a));
#define sorta(a)    stable_sort(BE(a))
#define sortc(a)    sort(BE(a),comp)

Long N, resR, resK;
template <typename T>
T BigMod(T base, T exp)
{
    //base %= modulus;
    T result = 1;
    while (exp > 0)
    {
        if (exp & 1) result = (result * base) ;
        base = (base * base);
        exp >>= 1;
    }
    return result;
}

int main(int argc, const char **argv)
{
    ios::sync_with_stdio(false);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w+",stdout);
    while(cin>>N)
    {
        resR = 1, resK = N-1;
        REP(R,1,40)
        {
            Long left = 2, right = (Long) pow((double)N,(double)1/R);
            while(left<=right)
            {
                Long mid = (left+right)>>1;
                Long tmpres = BigMod(mid,(Long)R+1);
                tmpres = (mid - tmpres)/(1-mid);
                if(tmpres==N or tmpres==(N-1))
                {
                    if(mid*R<resR*resK)
                    {
                        resR = R;
                        resK = mid;
                    }
                    break;
                }
                if(tmpres>N) right = mid - 1;
                else left = mid + 1;
            }
        }
        cout<<resR<<" "<<resK<<endl;
    }
    return 0;
}




