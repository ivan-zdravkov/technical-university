#include "Collision.h"

void Collision::Add(int x1, int y1, int x2, int y2)
{
	EventQueue *p = new EventQueue;
	p->segmentBegin.endPointX = x1;
	p->segmentBegin.endPointY = y1;
	p->segmentEnd.endPointX = x2;
	p->segmentEnd.endPointY = y2;
	p->next = EQ;
	EQ = p;
}

int Collision::Check(int x1, int y1, int x2, int y2)
{
	if(EQ == NULL) // If the list is empty, we add the new Line Segment and exit the method.
	{
		Add(x1, y1, x2, y2);
		return 0;
	}
	else // If the list is not empty...
	{
		int collisionFlag = 0; // Initializing a collision flag, that will become '1' if the Line Segment, we are checking collides with an existing Line Segment in the list. 
		EventQueue *p;
		p = EQ;
		while(p != NULL)
		{
			if(CollisionDetection(x1, y1, x2, y2, p->segmentBegin.endPointX, p->segmentBegin.endPointY, p->segmentEnd.endPointX, p->segmentEnd.endPointY))	 
			{ // If the lines collide, we use the method Remove, to remove the colliding Line Segment from the list, 
				Remove(p);  
				p = EQ;
				collisionFlag = 1; // The flag becomes '1' if we have a collision.
			}
			p = p->next;
		}
		if(!collisionFlag) // If the flag stays '0'. There is no collision, and we add the new Line Segment and exit the method.
		{
			Add(x1, y1, x2, y2);
			return 0;
		}
		else  // If the flag is '1', we have already removed all the colliding Line Segments, we add nothing and simply exit. 
			return 0;
	}
}

int Collision::CollisionDetection(int p0_x, int p0_y, int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y) // Untouched method from the internet
{
	//Returns 1 if the lines intersect, otherwise 0
	float s1_x, s1_y, s2_x, s2_y, sn, tn, sd, td, t;
    s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;
 
    sn = -s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y);
    sd = -s2_x * s1_y + s1_x * s2_y;
    tn =  s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x);
    td = -s2_x * s1_y + s1_x * s2_y;
 
    if (sn >= 0 && sn <= sd && tn >= 0 && tn <= td)
    {
        // Collision detected
        t = tn / td;
        return 1;
    }
	return 0; // No collision
}

void Collision::Remove(EventQueue *entryToRemove)
{
	if(!entryToRemove->next)
		delete entryToRemove;
	else
	{
		EventQueue *assistingNode;
		assistingNode = entryToRemove->next;
		*entryToRemove = *entryToRemove->next;
		delete assistingNode;
	}
}

EventQueue Collision::Get(void)
{
	return *EQ;
}



