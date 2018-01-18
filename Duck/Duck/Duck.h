#ifndef DUCK_H
#define DUCK_H
#include <iostream>
using namespace std;

class QuackBehavior
{
public:
	virtual void performQuack() = 0;
};
class FlyBehavior
{
public:
	virtual void performFly() = 0;
};

class Duck
{
public:
	QuackBehavior *ptr_quackBehavior;
	FlyBehavior *ptr_flyBehavior;
public:
	void swim();
	virtual void display() = 0;
	void performQuack()
	{
		ptr_quackBehavior->performQuack();
	};
	void performFly()
	{
		ptr_flyBehavior->performFly();
	};
	void setQuackBehavior(QuackBehavior*ptr)
	{
		delete ptr_quackBehavior;
		ptr_quackBehavior = ptr;
	}
	void setFlyBehavior(FlyBehavior* ptr)
	{
		delete ptr_flyBehavior;
		ptr_flyBehavior = ptr;
	}
	virtual ~Duck(){
		delete ptr_quackBehavior;
		delete ptr_flyBehavior;
	}
};



class Quack : public QuackBehavior
{
	void performQuack(){
		cout << "Quack Quack!" << endl;
	}
};
class Squeak : public QuackBehavior
{
	void performQuack(){
		cout << "Squeak Squeak!" << endl;
	}
};
class MuteQuack : public QuackBehavior
{
	void performQuack(){
		cout << "I can not make sound!" << endl;
	}
};
class FlyWithWings : public FlyBehavior
{
	void performFly(){
		cout << "I am flying now!" << endl;
	}
};
class FlyNoWay : public FlyBehavior
{
	void performFly(){
		cout << "I have no wings and can not Fly!" << endl;
	}
};



class MallardDuck : public Duck
{
public:
	MallardDuck(){ 
		ptr_quackBehavior = new Quack(); 
		ptr_flyBehavior = new FlyWithWings();
	};
	void display(){
		cout << "I am a mallardduck" << endl;
	}
};


class MiniDuckSimulator : public Duck
{
public:
	MiniDuckSimulator(){
		ptr_flyBehavior = new FlyNoWay();
		ptr_quackBehavior = new Squeak();
	}
	void display(){
		cout << "I am a miniducksimulator" << endl;
	}
};




#endif 