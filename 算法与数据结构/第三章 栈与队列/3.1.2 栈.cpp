//栈的抽象数据类型
template <class T>
class Stack{
public：                //栈的运算集
void clear();           //变为空栈
bool push(const T item);//item入栈，成功返回真，否则假
bool pop(T& item);      //返回栈内容并弹出，成功返回真，否则假
bool top(T& item);      //返回栈顶但不弹出，成功返回真，否则假
bool isEmpty();         //若栈已空返回真
bool isFull();          //若栈已满返回真
};

//顺序栈的类定义
template <class T> class arrStack:public Stack<T>{
private:                          //栈的顺序存储
int mSize;                        //栈中最多可存放的元素个数
int top;                          //栈顶位置，应小于MSize
T *st;                            //存放栈元素的数组
public:                           //栈的运算的顺序实现
arrStack(int size){               //创建一个给定长度的顺序栈实例
mSize=size;top=-1;st=new T[mSize];
}
arrStack(){                       //创建一个顺序栈的实例
top=-1;
}
~arrStack(){delete [] st;}
void clear(){top = -1;}           //清空栈
}

//压入栈顶
bool arrStack<T>::push(const T item){
if(top==mSize-1){ //栈已满
cout<<"栈满溢出"<<endl;
return false;
}
else
{
//新元素入栈并修改栈顶指针
st[++top]=item;
return true;
}
}

//从栈顶弹出
bool arrStack<T>::pop(T & item){  //出栈
if(top==-1){                      //栈为空
cout<<"栈为空，不能执行出栈操作"<<endl;
return false;
}else{
item = st[toop--];  //返回栈顶，并缩减1
return true;
}
}

//链式栈的创建
template<class T>class InkStack:public Stack<T>{
private:  //栈的链式存储
    Link<T>*top;  //指向栈顶的指针
    int size;  //存放元素的个数
public:        //栈运算的链式实现
    InkStack(int defSize){  //构造函数
    top=NULL;size=0;
    }
    ~InkStack(){  //析构函数
    clear();
    }
}

//入栈操作的链式实现
bool InksStack<T>::push(const T item){
    Link<T>*tmp=new Link<T>(item.top);
    top=tmp;
    size++;
    return true;
}
Link(const T info,Link*nextValue){  //具有两个参数的link构造函数
    date=info;
    next=nextValue;
}

//出栈操作的链式实现
bool InkStack<T>::pop(T& item){
    link <T>*tmp;
    if(size==0){
        cout<<"栈为空，不能执行出栈操作"<<endl;
        return false;
    }
    item=top->date;
    tmp=top->next;
    delete top;
    top=tmp;
    size--;
    return true;
}