#include <iostream>
using namespace std;
class Rectangle{
 public:
  int w,h;
  int Area(){
  	return w*h;
  }
   int Perimeter(){
   return 2*(w+h);
   }
   void init(int w_,int h_){
   w=w_;h=h_;
   }
   };//必须要有分号
  /* // 声明和定义分离
  class Rectangle{
  public:
  int w,h;
  int Area();//成员函数在此声明
  int Perimeter();
  void init(int w_,int h_);
  };
  int Rectangle::Area(){
   return w*h;
   }
   int Rectangle::Perimeter(){
   	return 2*(w+h);
   }
   void Rectangle::init(int w_,int h_){w=w_;h=h_;
   }
   */
    int main()
	{
	int w,h;
	Rectangle r;//r是一个对象
	cin>>w>>h;
	r.init(w,h);
	cout<<r.Area()<<endl<<r.Perimeter();
	return 0;
	}
