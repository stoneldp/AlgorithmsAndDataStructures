/*线性表类模板*/
template<class T>class List{
void clear();//置空线性表
bool isEmpty();//线性表为空时，返回true
bool append(const T value);//在表尾添加一个元素value，表的长度增1
bool insert(const int p,const T value);//在位置p上插入一个元素value，表的长度增1；
bool delete(const int p);//删除位置p上的元素，表的长度减1；
bool getPos(int& p，constr T value);//查找值为value的元素并返回其位置
bool getValue(const int p,T& value);//把位置p元素值返回到变量value
bool setValue(const int p,const T value);//用value修改位置p的元素值
}；