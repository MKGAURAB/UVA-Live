/*
 *  6073 - Math Magic.cpp
 *
 *  Created on: 2014-10-15-23.44.37, Wednesday
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
const int MOD = 1000000007;

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

Long DP[110][1010][50];
int can[1100], cpos[1100], lcma[1010][1010], N, M, K, L;
Long REC(int pos, int sum, int lcm)
{
    if(pos==K)
    {
        return (sum==N and can[lcm]==M)?1:0;
    }
    Long &ret = DP[pos][sum][lcm];
    if(~ret) return ret;
    ret = 0;
    REP(i,0,(L-1))
    {
        int sumt = sum+can[i];
        int lcmt = lcma[can[i]][can[lcm]];
        if(sumt<=N and lcmt<=M) ret += REC(pos+1,sumt,cpos[lcmt]), ret %= MOD;
    }
    return ret;
}
int main(int argc, const char **argv)
{
    ios::sync_with_stdio(false);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w+",stdout);
    REP(i,1,1000)
    REP(j,1,1000) lcma[i][j] = ((i*j)/__gcd(i,j));
    while(cin>>N>>M>>K)
    {
        L = 0;
        REP(i,1,M)
        {
            if(!(M%i)) {can[L]=i; cpos[i]=L;L++;}
        }
        mem(DP,-1);
        Long ans = REC(0,0,0);
        cout<<ans<<"\n";
    }
    return 0;
}




