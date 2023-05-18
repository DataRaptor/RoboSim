#ifndef __LogicACTIONS
#define __LogicACTIONS



void Action_GoForward(void);

void Action_Break(void);

void Action_SwitchLenLeft(void);
void Action_SwitchLenRight(void);

void Action_RotateLeft(void);
void Action_RotateRight(void);

void Action_RotateLeft_ToLine(void);
void Action_RotateRight_ToLine(void);

void Action_Stop(void);


void Action_SwitchTunnelLeft_T(void);
void Action_SwitchTunnelRight_T(void);

void Action_SwitchTunnelLeft_L(void);
void Action_SwitchTunnelRight_L(void);

void Action_FollowLeftWall(void);
void Action_FollowRightWall(void);

void Action_PassObjectLeft(void);
void Action_PassObjectRight(void);

void Action_END(void);


#endif
