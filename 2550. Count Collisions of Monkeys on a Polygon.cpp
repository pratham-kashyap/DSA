// There is a regular convex polygon with n vertices. The vertices are labeled from 0 to n - 1 in a clockwise direction, and each vertex has exactly one monkey. 
// Each monkey moves simultaneously to a neighboring vertex. A neighboring vertex for a vertex i can be:
// - the vertex (i + 1) % n in the clockwise direction, or
// - the vertex (i - 1 + n) % n in the counter-clockwise direction.
// A collision happens if at least two monkeys reside on the same vertex after the movement or intersect on an edge.
// Return the number of ways the monkeys can move so that at least one collision happens. Since the answer may be very large, return it modulo 109 + 7.
// Note that each monkey can only move once.

class Solution {
public:
    int binexp(int n)
    {
        const int MOD = 1e9+7;
        int x = 2;
        int p = 1;
        while(n>0)
        {
            if(n&1)
            p = (p*1LL*x)%MOD;
            x = (x*1LL*x)%MOD;
            n/=2;
        }
        return p;
    }
    int monkeyMove(int n) {
        const int MOD = 1e9+7;
        return (binexp(n)-2+MOD)%(MOD);
    }
};
