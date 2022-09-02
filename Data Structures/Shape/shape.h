#ifndef SHAPE_H
#define SHAPE_H

//Shape interface
typedef struct ShapeIF{
  double (*getArea)(void*);
} ShapeIF;

//Shape
typedef struct{
  int x, y;
  void * instance;
  char * type;
  ShapeIF * shapeIF;
}Shape;

static Shape * shape_ctor(int, int, char*);

//Rectangle
typedef struct{
  double l,w;
  void * shape;
  void * instance;
  ShapeIF * shapeIF;
}Rectangle;

Rectangle * rectangle_ctor(double, double, double, double);
double rectangle_getArea(void *);

//CircleIF
typedef struct{
  double (*getCircumference)(void *);
} CircleIF;

typedef struct{
  double r;
  void *shape;
  void *instance;
  ShapeIF * shapeIF;
  CircleIF * circleIF;
} Circle;

Circle * circle_ctor(double, double, double);
double circle_getArea(void *);
double circle_getCircumference(void *);

//Ring
typedef struct{
  double r1;
  void * shape;
  void * circle;
  void * instance;
  ShapeIF * shapeIF;
  CircleIF * circleIF;
} Ring;

Ring * ring_ctor(double, double, double, double);
double ring_getArea(void *);
double ring_getCircumference(void *);

#endif