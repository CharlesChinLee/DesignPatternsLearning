#ifndef WEATHERSTATION_H
#define WEATHERSTATION_H
#include <list>
#include <iostream>
using namespace std;

class Notify
{
public:
	virtual void OnUpdate(float temp, float hum, float pre) = 0;
};

class CenterEngine
{
private:
	Notify * ptr_notify;
public:
	CenterEngine(){
		ptr_notify = NULL;
	}
	void Regist(Notify* ptr)
	{
		if (!ptr_notify)
		{
			ptr_notify = ptr;
		}
	}
	void NumAlready(float temp, float hum, float pre){
		ptr_notify->OnUpdate(temp, hum, pre);
	}
};

class Observer
{
public:
	virtual void update(float,float,float) = 0;
};
class DisplayElement
{
public:
	virtual void display() = 0;
};

class Subject
{
public:
	virtual void registerOb(Observer*) = 0;
	virtual void unregisterOb(Observer*) = 0;
	virtual void notify() = 0;
};

class Weather : public Notify, public Subject
{
private:
	list<Observer*> observers;
	float temperature;
	float humidity;
	float pressure;
public:
	Weather(){
		observers.clear();
		temperature = 0;
		humidity = 0;
		pressure = 0;
	};
	void registerOb(Observer* ob){
		observers.push_back(ob);
	};
	void unregisterOb(Observer* ob){
		list<Observer*>::iterator itr = find(observers.begin(), observers.end(), ob);
		if (itr != observers.end())
		{
			observers.erase(itr);
		}
	};
	void OnUpdate(float temp, float hum, float pre){
		temperature = temp;
		humidity = hum;
		pressure = pre;
		notify();
	};
	void  notify(){
		list<Observer*>::iterator itr;
		for (itr = observers.begin(); itr != observers.end();itr++)
		{
			(*itr)->update(temperature, humidity, pressure);
		}
	};
};

class CurrentConditionsDisplay : public Observer, public DisplayElement
{
private:
	int number;
	float temperature;
	float humidity;
	Subject* weatherData;
public:
	CurrentConditionsDisplay(Subject* weather,int num)
	{
		number = num;
		temperature = 0;
		humidity = 0;
		weatherData = weather;
		weather->registerOb(this);
	}
	void update(float temp, float hum, float pre)
	{
		temperature = temp;
		humidity = hum;
		display();
	}
	void display()
	{
		cout << "I'm the displaypad of CurrentConditionDisplay_" << number << endl;
		cout << "Temperature = " << temperature << "буC" << " Humidity = " << humidity << "бу" << endl;
	}
	~CurrentConditionsDisplay()
	{
		cout << "Bye CurrentConditionDisplay_" << number << endl;
		weatherData->unregisterOb(this);
	}
};

#endif
