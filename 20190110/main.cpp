#include <iostream>
using namespace std;
class Complex{
public:
    double shi;
    double xu;
    Complex(double shi,double xu){
        this->shi = shi;
        this->xu = xu;
    }
    /*
    Complex & operator + (Complex &obj){
        xu = xu + obj.xu;
        shi = shi + obj.shi;
        return *this;
    }
    */
    /*Complex & operator++(){
        shi++;xu++;
        return *this;
    }
    */
    /*
    Complex operator++(int){
        Complex temp = *this;
        shi++;xu++;
        return temp;
    }
    */
    friend Complex & operator++(Complex& obj,int);
    friend Complex & operator++(Complex& obj);
    friend Complex & operator+(Complex obj1,Complex obj2);
    friend ostream & operator<<(ostream& out,Complex& obj);
    friend istream & operator>>(istream& in,Complex& obj);
};
Complex & operator++(Complex& obj,int){
    Complex temp = obj;
    obj.shi++;obj.xu++;
    return temp;
}
Complex & operator++(Complex& obj){
    ++obj.shi;++obj.xu;
    return obj;
}
Complex & operator+(Complex obj1,Complex obj2){
    obj1.shi += obj2.shi;
    obj1.xu += obj2.xu;
    return obj1;
}
ostream & operator<<(ostream& out,Complex& obj){
    out<<obj.shi<<"+"<<obj.xu<<"i";
    return out;
}
istream & operator>>(istream& in,Complex& obj){
    in>>obj.shi>>obj.xu;
    return in;
}
int main(){
    Complex a(1,2);Complex b(3,4);
    a = a + b;
    cout<<a<<endl;
    ++a;
    cout<<a<<endl;
    cout<<a++<<endl;
    cout<<a<<endl;
}