#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
//template <class T, class V>
struct SegmentTreeNode {
       long long int prefixsum , suffixsum, maxsum, sum;
  // variables to store aggregate statistics and
  // any other information required to merge these
  // aggregate statistics to form parent nodes
  
  void assignLeaf(int value) {
       prefixsum = suffixsum = maxsum = sum = value;
    // T is the type of input array element
    // Given the value of an input array element,
    // build aggregate statistics for this leaf node
  }
  
  void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
       sum = left.sum + right.sum;
       prefixsum = max(left.prefixsum, left.sum+right.prefixsum);
       suffixsum = max(right.suffixsum, right.sum+left.suffixsum);
       maxsum = max(suffixsum,max(prefixsum,max(left.suffixsum + right.prefixsum,max(left.maxsum, right.maxsum))));
    // merge the aggregate statistics of left and right
    // children to form the aggregate statistics of
    // their parent node
  }
  
  long long int getValue() {
      return maxsum;         
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
  
  void update(int index, T value) {
    update(1, 0, N-1, index, value);
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
  
  void update(int stIndex, int lo, int hi, int index, T value) {
    if (lo == hi) {
    nodes[stIndex].assignLeaf(value);
    return;
    }
    
    int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
    if (index <= mid)
      update(left, lo, mid, index, value);
    else
      update(right, mid+1, hi, index, value);
    
    nodes[stIndex].merge(nodes[left], nodes[right]);
  }
};

int main(int argc, char *argv[])
{
    int n,m,a,b,choice;
    scanf("%d",&n);
    int A[n];
    for(int i = 0;i<n;++i) scanf("%d",&A[i]);
    SegmentTree<int, long long int > tree(A,n);
    scanf("%d",&m);
    while(m--){
          scanf("%d%d%d",&choice,&a,&b);
          if(choice == 0){
             tree.update(a-1,b);
          }
          else if(choice == 1){       
               printf("%lld\n",tree.getValue(a-1,b-1));
          }
    }
               
    
    
    return 0;
}
