#ifndef __PlannerLogicDecisionMaker
#define __PlannerLogicDecisionMaker



void Planner_LeftWall(void);
void Planner_RightWall(void);
void Planner_Obstacle(void);
void Planner_LineEnd(void);
void Planner_Cave(void);
void Planner_Junction_LeftL(void);
void Planner_Junction_RightL(void);
void Planner_Junction_LeftT(void);
void Planner_Junction_RightT(void);
void Planner_Junction_BottomT(void);

void Planner_Junction_Plus(void);


void Planner_TwoWay(void);
//	void Junction_Plus(void);
//	void Junction_LeftV(void);
//	void Junction_RightV(void);


void Planner_Cave_LeftL(void);
void Planner_Cave_RightL(void);

void Planner_Cave_LeftT(void);
void Planner_Cave_RightT(void);
//void Cave_BottomT(void);



#endif
