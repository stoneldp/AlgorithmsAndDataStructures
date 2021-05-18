//顺序表类定义：
class arrList:public List<T>{     //顺序表，向量
private:                          //线性表的取值类型和取值空间
T*aList;                          //私有变量，存储顺序表的实例
int maxSize;                      //私有变量，顺序表实例的最大长度
int curLen;                       //私有变量，顺序表实例的当前长度
int position;                     //私有变量，当前处理位置
public:
arrList(const int size){          //创建新表，设置表实例的最大长度
maxSize=size;aList=new T[maxSize];
curLen=position=0;
}
~arrList(){                        //析构函数，用于消除该表实例
delete[]aList;
}
void clear(){                     //将顺序表存储的内容清除，成为空表
delete[]aList;curLen=position=0;
aList=new T [maxSize];
}
int length();                     //返回当前实际长度
bool append(const T value);       //在表尾添加元素V
bool delete(const int p);         //插入元素
bool setValue(const int p,const T value);//删除位置p上元素
bool getValue(const int p,T& value);//设元素值
bool getPos(int &p,const T value);//查找元素
};

//顺序表的插入
//设元素的类型为T、aList是存储顺序表的数组，maxSize是其最大长度；
//p为新元素value的插入位置，插入成功则返回true，否则返回false
template<class T> bool arrList<T>::insert(const int p,const T value){
int i;
if(curLen>=maxSize){                                  //检查顺序表是否溢出
cout<<"The list is overflow"<<endl;return false;
}
if(p<0||p>curLen){                                    //检查插入位置是否合法
cout<<"Insertion point is illegal"<<endl;return false;
}
for(i=curLen;i>p;i--)
aList[i]=aList[i-1];                                   //从表尾curLen-1起往右移动直到p
aList[p]=value;                                        //位置p处插入新元素
curLen++;                                              //表的实际长度增1
return true;
}


//顺序表的删除
//设元素的类型为T；aList是存储顺序表的数组；p为即将删除元素的位置
//删除成功则返回true，否则返回false
template<class T>                                      //顺序表的元素类型为T
bool arrList<T>::delete(const int p){
int i;
if(curLen<=0){                                         //检查顺序表是否为空
cout<<"No element to delete \n"<<endl;
return false;
}
if(p<0||p>curLen-1){                                   //检查删除位置是否合法
  cout<<"deletion is illegal\n"<<endl;
  return false;
}
for(i=p;i<curLen-1;i++)
aList[i]=aList[i+1];                                   //从位置p开始每一个元素左移直到curLen
curLen--;                                              //表的实际长度减1
return true;
}