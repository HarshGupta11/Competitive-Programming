#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
struct SegmentTreeNode {
       int unmatchedopen, unmatchedclose;
       string A;
  // variables to store aggregate statistics and
  // any other information required to merge these
  // aggregate statistics to form parent nodes
  
  void assignLeaf(char value) {
       string temp(1,value);
       if(value == '('){
           unmatchedopen = 1; unmatchedclose = 0;
       }
       else{
           unmatchedopen = 0;
           unmatchedclose = 1;
       }      
       A = temp;
    // T is the type of input array element
    // Given the value of an input array element,
    // build aggregate statistics for this leaf node
  }
  
  void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
       int newmatch = min(left.unmatchedopen,right.unmatchedclose);
       unmatchedopen = left.unmatchedopen + right.unmatchedopen - newmatch;
       unmatchedclose = left.unmatchedclose + right.unmatchedclose - newmatch;
       A = left.A + right.A;
      // cout << unmatchedopen << ' ' << unmatchedclose << '\n';
    // merge the aggregate statistics of left and right
    // children to form the aggregate statistics of
    // their parent node
  }
  
  bool getValue() {
       return (unmatchedclose == 0 && unmatchedopen == 0);
    // V is the type of the required aggregate statistic
    // return the value of required aggregate statistic
    // associated with this node
  }
};

template<class T, class V>
class SegmentTree {
  SegmentTreeNode* nodes;
  int N;
 
public:
  SegmentTree(T arr[], int N) {
    this->N = N;
    nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
    buildTree(arr, 1, 0, N-1);
  }
  
  ~SegmentTree() {
    delete[] nodes;
  }
  
  V getValue(int lo, int hi) {
    SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
    return result.getValue();
  }
  
  void update(int index) {
    update(1, 0, N-1, index);
  }
  
  private:	
  void buildTree(T arr[], int stIndex, int lo, int hi) {
    if (lo == hi) {
      nodes[stIndex].assignLeaf(arr[lo]);
      return;
    }
    
    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    buildTree(arr, left, lo, mid);
    buildTree(arr, right, mid + 1, hi);
    nodes[stIndex].merge(nodes[left], nodes[right]);
  }
  
  SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi) {
    if (left == lo && right == hi)
      return nodes[stIndex];
    	
    int mid = (left + right) / 2;
    if (lo > mid)
      return getValue(2*stIndex+1, mid+1, right, lo, hi);
    if (hi <= mid)
      return getValue(2*stIndex, left, mid, lo, hi);
    	
    SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
    SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
    SegmentTreeNode result;
    result.merge(leftResult, rightResult);
    return result;
  }
  
  int getSegmentTreeSize(int N) {
    int size = 1;
    for (; size < N; size <<= 1);
    return size << 1;
  }
  
  void update(int stIndex, int lo, int hi, int index) {
    if (lo == hi) {
       if(nodes[stIndex].A == ")"){
               nodes[stIndex].A = "(";            
               nodes[stIndex].unmatchedopen = 1; nodes[stIndex].unmatchedclose = 0;
       }
       else{
               nodes[stIndex].A = ")";            
               nodes[stIndex].unmatchedopen = 0; nodes[stIndex].unmatchedclose = 1;    
       }                
    return;
    }
    
    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    if (index <= mid)
      update(left, lo, mid, index);
    else
      update(right, mid+1, hi, index);
    
    nodes[stIndex].merge(nodes[left], nodes[right]);
  }
};

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    int n,m,k;
    string A;
    for(int i = 1;i<=10;++i){
        cin >> n;    
        cout << "Test " << i << ":\n";    
        cin >> A;
        char B[n];
        strcpy(B,A.c_str());
       // cout << B << '\n';
        SegmentTree<char,bool> tree(B,n);
        cin >> m; 
        while(m--){
              cin >> k;
              if(k==0){
                  if(tree.getValue(0,n-1) == true) cout << "YES\n";
                  else                             cout << "NO\n";
              }
              else      tree.update(k-1); 
        } 
    }          
   
    return 0;
}
