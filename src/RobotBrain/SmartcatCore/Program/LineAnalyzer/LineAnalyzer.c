#include "SmartCat.h"


uint8 L = 0;
uint8 M = 0;
uint8 R = 0;

uint16 L_Counter = 0;
uint16 R_Counter = 0;



void Clear()
{
	L = 0;
	R = 0;
	M = 0;
	
	L_Counter = 0;
	R_Counter = 0;
}



void Decide(uint8 ForwardLineExist)
{
	/*Take Desition*/
		
	if(L == 1 && R == 0 && ForwardLineExist == 0)
	{
		//LeftL
		Planner_Junction_LeftL();
		
		Clear();
	}
	else if(L == 0 && R == 1 && ForwardLineExist == 0)
	{
		//RightL
		Planner_Junction_RightL();
		
		Clear();
	}
	else if(L == 0 && R == 1 && ForwardLineExist == 1)
	{
		//LeftT
		Planner_Junction_LeftT();
		
		Clear();
	}
	else if(L == 1 && R == 0 && ForwardLineExist == 1)
	{
		//RightT
		Planner_Junction_RightT();
		
		Clear();
	}	
	else if(L == 1 && R == 1 && ForwardLineExist == 1)
	{
		//Plus
		Planner_Junction_Plus();
		
		Clear();
	}
	else if(L == 1 && R == 1 && ForwardLineExist == 0)
	{
		//Two way: BottomT, bottom Y
		Planner_TwoWay();
		
		Clear();		
	}
	
	else
	{
		Clear();
	}
}


uint16 ForwardLineConfidance = 0;


void Analyze()
{


	/*Take Desition when all sensors are Blank*/
	if(IRArray.Line.AllZero == 1)
	{
		if(L == 1 || R == 1)
		{
			Decide(0);
			
			ForwardLineConfidance = 0;
		}
	}
	
	
	/*Take Desition when There is a line Exist and the Confidance is greater than the line width counter*/
	if(IRArray.Line.SingleLineExist == 1 && IRArray.Line.LineWidth <= 4 && 
		 IRArray.Line.LineWidth >= 2 && 
		 IRArray.Line.LL == 0 && IRArray.Line.RR == 0
	)
	{
		if(L == 1 && R == 0)
		{
			//Decide(0);	//Let assume there is no line in front (only for MIST Contest)
			
			
			/*V. V. I Code: Works very well
			-------------------------------*/
			if(ForwardLineConfidance < (L_Counter))
			{
				ForwardLineConfidance++;
			}
			else
			{
				Decide(1);
				ForwardLineConfidance = 0;
			}
		}
		else if(L == 0 && R == 1)
		{
			//Decide(0);	//Let assume there is no line in front (only for MIST Contest)
			
			
			/*V. V. I Code: Works very well
			-------------------------------*/
			if(ForwardLineConfidance < (R_Counter))
			{
				ForwardLineConfidance++;
			}
			else
			{
				Decide(1);
				ForwardLineConfidance = 0;
			}			
		}
		else if(L == 1 && R == 1)
		{
			if(ForwardLineConfidance < L_Counter)
			{
				ForwardLineConfidance++;
			}
			else
			{
				Decide(1);
				ForwardLineConfidance = 0;
			}			
		}
	}
	
	
	
	
	
	
	
	/*----------------Updating L M R----------------------*/
	
	
	/*Update L R  only when middle Sensor is active*/
	if(IRArray.Line.LineWidth > 5 && IRArray.Line.M == 1)
	{
		if(IRArray.Line.LL == 1)
		{
			L = 1;
		}
		
		if(IRArray.Line.RR == 1)
		{
			R = 1;
		}
	}
	
	
	/*For Y shape. Middle Sensor Dont Care*/
	if(IRArray.Line.LL == 1 && IRArray.Line.RR == 1)
	{
		L = 1;
		R = 1;
	}	
	
	
	
	
	

	

	

	
	
	
	/*-------------------Updating L M R Length Counter----------------------*/
	
	
	if(L == 1 && IRArray.Line.LL == 1)
	{
		L_Counter++;
	}
	
	if(R == 1 && IRArray.Line.RR == 1)
	{
		R_Counter++;
	}	
	
	

	
	
	
	

	/*Detect Line End*/
	
	if(IRArray.Line.AllZero == 1 && (IRArray.Line.Error < 9 || IRArray.Line.Error > -9) && L == 0 && R == 0)
	{
		Planner_LineEnd();
		Clear();
	}
	
	
	
}










