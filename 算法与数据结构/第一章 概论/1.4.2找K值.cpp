//顺序找K值
    template <class Type>
    class Item{
    private:
      Type key;       //关键码域
                      //其他域
    public:
      Item(Type value):key(value){}
      Type getKey(){return key;}    // 取关键码值
      void setKey(Type k){key=k;}   // 置关键码
    };
    vector<Item<Type>*> datallist;
    template <class Type> int SepSearch(vector<Item<Type>*>& dataList,int length,Type k){
      int i=length;
      dataList[0]->setkey(k);
      while(dataList[i]->getKey()!=k) i--;  // 将第0个元素设为待检索值，设监视哨
      return i;                             // 返回元素位置
    }

// 二分法找K值
  tempplate <class Type> int  BinSearch (vector<Item<Type>*>& dataList,
  int length,Type k){
    int low=1，high=length,mid;
    while (low<=high){
      mid=(low+high)/2;
      if(K<dataList[mid]->getKey())
        high = mid-1;                     //右缩检索区间
      else if (k>dataList[mid]->getKey())
        low = mid+1;                      //左缩检索区间
      else return mid;                    // 成功返回位置
      }
    return 0;                             // 检索失败，返回0
    }