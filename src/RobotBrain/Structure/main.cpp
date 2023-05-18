#include "SmartCat.h"



//StrictPath triangle = Path(
//		_(_0000001) -> GoLeft (),
//		_(_1000000) -> GoRight(),
//		_(_0000010) -> Ignore ()
//);


//Path square = Path( 3,
//		_(_0000001) -> GoLeft (),
//		_(_1000000) -> GoRight(),
//		_(_0000010) -> Ignore (),
//		_(_1000000) -> GoRight(),
//);


//Junction j1 = _(_0100000) -> GoRight();
//Junction j2 = _(_1000000) -> GoLeft ();
//Junction j3 = _(_0100010) -> GoLeft ();



//Action GoLeft = Action(
//		
//		
//)


typedef void Action;

Action A010()
{
	api.GoForward();
}

int main()
{
	
	SartCatConfig config;
	DefalutConfig(&conf);
	
	config.UseEncoder = 1;
	config.IRSensorCount = 8;
	config.PID.Ki = 150;
	config.PID.Kd = 140;
	config.PID.Kp = 50;
	config.CustomLogic = 1;
	config.UseSimulator = 1;
	config.Events.DesitionRequired = 
	config.Events.USBDataRecieved = 
	
	config.Events.Button1Pressed = 
	config.Events.Button2Pressed = 
	config.Events.Button3Pressed = 
	config.Events.Button4Pressed = 
	
	config.Track.T1 = track1;
	config.Track.T2 = track1;
	
	InitBot(&config);
	
	
	
	
	Path triangleL;
	triangleL:01000100 > A100;
	triangleL:00100100 > A200;
	triangleL:00010100 > A010;
	
	OBstacle obstcl;
	obstcl:010 > O101;
	
	
	Side t1_left;
	t1_left += triangleL;
	
	
	Track first;
	first.GeneralRule += 01000100 > A100;
	first.GeneralRule += 00010100 > A010;
	first.GeneralRule += 00100100 > A200;
	first += t1_left;
	first += t1_Right;
	first += t1_bottom;
	
	
	Track second;
	
	
	
	while(1)
	{
		
		
		
		
	}
}


using namespace SmartCat.OS;
using namespace SmartCat.OS.Threading;
using namespace SmartCat.OS.Timer;
using namespace SmartCat.IO;
using namespace SmartCat.Core;
using namespace SmartCat.PathPlanner;
using namespace SmartCat.SensorAnalyzer;
using namespace SmartCat.SimulatorApi;

namespace SmartCat
{
	/// <summary>
  /// Interaction logic for MainWindow.xaml
  /// </summary>
	class Program : SmartCatCore
	{
		/*Initialization Function*/
		void Setup()
		{
			

			
		}
		
		/*Infinite Loop*/
		void Loop()
		{
			
			
			
		}
	};
}


















int main()
{
	
	
	
	
	
	
  while (1)
  {
		
		
  }
}

