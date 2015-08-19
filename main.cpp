/* 
 * File:   main.cpp
 * Author: caoshan
 *
 * Created on August 18, 2015, 4:45 PM
 */

#include <cstdlib>
#include <iterator>
#include <iostream>

using namespace std;

/*
 * 
 */
class Animal{
public:
    void getFamily(){cout<<" we are animals"<<endl;}
    virtual void getClass(){cout<<"I am an Animal"<<endl;}
    void returnClass(){cout<<"I am an Animal"<<endl;} //如果没有Virtual,父类的方法不会被隐藏. 
};

class dog: public Animal{
public:
    void getClass(){cout<<"I am a dog"<<endl;}
    void returnClass(){cout<<"I am an Dog";} ///这个方法不会被执行.
};

void whatClassAreYou(Animal *animal)
{
    animal->getClass();
    animal->returnClass();
}

class GermanShepard:public dog{
public: 
    void getClass(){cout<<"I am a German Shepard"<<endl;}
    void getDeviverd(){cout <<" I am  Animal and a Dog"<<endl;}
};

int main(int argc, char** argv) {
    Animal *animal=new Animal; //注意这里的class initialization is diff to JAVA and C#
    dog *Dog=new dog;
    whatClassAreYou(animal); //注意这里到输出,注意继承类之间的执行.
    whatClassAreYou(Dog);
    
    //Polymophyism 
    dog Spot;
    GermanShepard Max;
    Animal* ptrDog =&Spot;
    Animal* ptrShepard= &Max;
    
    ptrDog->getFamily();
    ptrDog->getClass();
    
    ptrShepard->getFamily();
    ptrShepard->getClass();
    // we can not see the GermanShepard Method,because this is ptrDog and 
    //PtrShepard are both Animal Class Objects.
    return 0;
}

