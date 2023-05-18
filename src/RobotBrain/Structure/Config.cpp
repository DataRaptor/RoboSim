


using SmartCat.Settings

namespace SmartCat
{
	SmartCatConfig settings1()
	{
		SmartCatConfig config;
		
		DefalutConfig(&conf);
		config.UseEncoder = 1;
		config.IRSensorCount = 8;
		config.PID.Ki = 150;
		config.PID.Kd = 140;
		config.PID.Kp = 50;
		config.CustomLogic = 1;
		config.UseSimulator = 1;
	}


	





}













