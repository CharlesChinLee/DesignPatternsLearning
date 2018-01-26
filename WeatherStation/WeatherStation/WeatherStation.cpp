// WeatherStation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "weatherstation.h "

int _tmain(int argc, _TCHAR* argv[])
{
	Weather weather_station;
	CenterEngine notify_center;
	notify_center.Regist(&weather_station);
	CurrentConditionsDisplay pad(&weather_station, 3);
	{
		CurrentConditionsDisplay pad2(&weather_station, 5);
		notify_center.NumAlready(18, 28, 39);
	}
	CurrentConditionsDisplay pad3(&weather_station, 24);
	notify_center.NumAlready(-8, 1, 179);
	

	return 0;
}

