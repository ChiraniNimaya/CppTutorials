#include <iostream>

class A{
 private:
  int data_a;
 public:
  A(int x){
   data_a=x;
  }
  friend int fun(A, B);
};

class B{
 private:
  int data_b;
 public:
  B(int x){
   data_b=x;
  }
  friend int fun(A, B);
};

int fun(A a, B b){
 return a.data_a+b.data_b;
};

int main(){
 A a(10);
 B b(20);
 std::cout<<fun(a,b)<<std::endl;
 return 0;
}
