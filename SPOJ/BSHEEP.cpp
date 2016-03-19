#include "bits/stdc++.h"
using namespace std;

struct Point {
  int x, y, index;
  bool operator <(const Point &p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
};
int cross(const Point &O, const Point &A, const Point &B)
{
  return (long)(A.x - O.x) * (B.y - O.y) - (long)(A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point>& P)
{
  int n = P.size(), k = 0;
  vector<Point> H(2*n);

  // Sort points lexicographically
  sort(P.begin(), P.end());

  // Build lower hull
  for (int i = 0; i < n; ++i) {
    while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
    H[k++] = P[i];
  }

  // Build upper hull
  for (int i = n-2, t = k+1; i >= 0; i--) {
    while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
    H[k++] = P[i];
  }

  H.resize(k);
  H.pop_back();
  return H;
}

Point minimum;

double distance2(Point &A, Point &B)
{
       int dx = B.x-A.x, dy = B.y-A.y;
       return sqrt(dx*dx+dy*dy);       
}

int func(Point A, Point B)
{
    return ((A.x - minimum.x)*(B.y-minimum.y) - (A.y-minimum.y)*(B.x - minimum.x) >= 0);
}

int main()
{
    ios::sync_with_stdio(false);
    int T,N,i,x,y,minindex;
    Point temp;
    double dist;
    cin >> T;
    while(T--){
          dist = 0;     
          cin >> N;
          set<pair<int,int> > SET;
          set<pair<int,int> >::iterator it;
          vector<Point> A;  
          for(i = 1;i<=N;++i){
              cin >> x >> y;
              it = SET.find(make_pair(x,y));
              if(it == SET.end()){
                 SET.insert(make_pair(x,y));
                 temp.x = x;
                 temp.y = y;
                 temp.index = i;
                 A.push_back(temp);
              }
          }
          if(A.size() == 1){
             cout << "0.00\n"
                  << A[0].index << "\n\n";
             continue;
          }          
          A = convex_hull(A);
          if(A.size() == 2){
             dist+= 2*distance2(A[0],A[1]);
             cout << fixed << setprecision(2) << dist << '\n'
                  << A[0].index << ' ' << A[1].index << "\n\n";
             continue;
          }
            
                   
          minindex = 0;
          for(i = 1;i<A.size();++i){
              dist+= distance2(A[i],A[i-1]);  
              if(A[i].y < A[minindex].y) minindex = i;
              else if(A[i].y == A[minindex].y && A[i].x < A[minindex].x) minindex = i;
          }
          dist+= distance2(A[i-1],A[0]);
          minimum = A[minindex];
          A[minindex] = A[0];
          A[0] = minimum;
          sort(A.begin()+1, A.end(),func);
          cout << fixed << setprecision(2) << dist << '\n';
          for(i = 0;i<A.size();++i){
              cout << A[i].index << ' ' ;
          }
          cout << "\n\n";
    }  
                
          
     
                    
                     
    return 0;
}
