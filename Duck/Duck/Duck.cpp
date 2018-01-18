// Duck.cpp : �������̨Ӧ�ó������ڵ㡣
// ��һ�����ģʽ 

#include "stdafx.h"
#include "Duck.h"



int _tmain(int argc, _TCHAR* argv[])
{
	{
		Duck *mallardduck = new MallardDuck();
		Duck *miniducksim = new MiniDuckSimulator();
		mallardduck->display();
		mallardduck->performFly();
		mallardduck->performQuack();
		miniducksim->display();
		miniducksim->performFly();
		miniducksim->performQuack();
				   
		miniducksim->setQuackBehavior(new MuteQuack());
		miniducksim->display();
		miniducksim->performQuack();
		delete mallardduck;
		delete miniducksim;
	}
	cout << "exit now" << endl;
	return 0;
}

