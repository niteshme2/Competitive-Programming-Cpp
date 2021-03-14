#include <bits/stdc++.h>
using namespace std;

#define d double
#define M 100010
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

class Point
{
public:
    d x,y;
};

Point pt[M];
Point strip[M];

bool cmpx(Point &a, Point &b){
    return a.x < b.x;
}

bool cmpy(Point &a, Point &b){
    return a.y < b.y;
}

d dist(Point &a, Point &b){
    d x1,x2,y1,y2;
    x1 = a.x; x2 = b.x;
    y1 = a.y; y2 = b.y;
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

d perimeter(Point &a, Point &b, Point &c){
    return dist(a,b)+dist(b,c)+dist(a,c);
}

d ClosestPair(int s, int e){
    if(s == e)
        return 1e9;
    if(s+1 == e)
        return 1e9;
    if(s+2 == e)
        return perimeter(pt[s],pt[s+1],pt[s+2]);

    int mid = s + (e-s)/2;
    d d1 = ClosestPair(s,mid);
    d d2 = ClosestPair(mid+1,e);
    d d_min = min(d1,d2);
    Point m = pt[mid];
    int idx=0;
    for(int i=s; i<=e; i++)
    {
        if( abs(pt[i].x - m.x) < d_min)
            strip[idx++] = pt[i];
    }

    sort(strip, strip+idx, cmpy);

    for(int i = 0; i < idx ; i++)
    {
        for(int j = i+1; j < idx && (strip[j].y - strip[i].y)<d_min; j++)
        {
            for(int k = j+1; k < idx && (strip[k].y - strip[j].y)<d_min; k++)
            {
                d_min = min(d_min, perimeter(strip[i],strip[j],strip[k]));
            }
        }
    }
    return d_min;
}

int main(){
    clock_t z = clock();
    int  t;
    cin >> t;
    for(int i =1; i<=t; i++)
    {
        int n;
        cin >> n;
        for(int i = 0; i<n; i++)
            cin >> pt[i].x >> pt[i].y;
        sort(pt, pt+n, cmpx);
        cout<<fixed<<setprecision(10)<<"Case "<<i<<": "<<ClosestPair(0,n-1)<<endl;
    }
    debug("Total Time: %.6f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
	return 0;
}


