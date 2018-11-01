/*
#############################################################################################################################
#																															#
# The collision class is used to create a single object, that contains the coordinates of all the Line Segments in a list.	#
# The created object makes a list, that trough the method Check gets the coordinates of 2 points that form a Line Segment.	# 
# It checks in a list whether or not the just received Line Segment collides with one or more Line Segments.				#
#	If it DOES collide, all the colliding Line Segments are deleted from the list.											#
#	If it DOES NOT collide, the new Line Segment is added to the list.														#
# There are 2 public methods: Check() and Get().																			#
#																															#			
#############################################################################################################################
#																															#
# Check(x1, y1, x2, y2) takes as arguments the coordinates of a single Line Segment, where									#
#																															#
#	x1 - X coordinate of StartPoint																							#
#	y1 - Y coordinate of StartPoint																							#
#	x2 - X coordinate of EndPoint																							#
#	y2 - Y coordinate of EndPoint																							#
#																															#
# StartPoint and EndPoint can be switched!!!																				#
# Any of the 2 points that make up the segment can be StartPoint or EndPoint!												#
#																															#
#############################################################################################################################
#																															#
# Get(), returns pointer to the first element of the list																	#
#																															#
#############################################################################################################################
*/

#include "stdio.h"

struct Endpoint
{
	int endPointX;
	int endPointY;
};

struct EventQueue
{
	Endpoint segmentBegin;
	Endpoint segmentEnd;
	EventQueue *next;
};

class Collision
{
private:
	EventQueue *EQ;
	void Add(int x1, int y1, int x2, int y2); 
	void Remove(EventQueue *entryToRemove);
	int CollisionDetection(int p0_x, int p0_y, int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y);
public:
	Collision();
	int Check(int x1, int y1, int x2, int y2);
	EventQueue Get(void);
};

Collision::Collision() 
{
	EQ = NULL;
}