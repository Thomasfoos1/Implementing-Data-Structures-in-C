#include <stdio.h>
#include <stdlib.h>
#include "shape.h"
#include "queue.h"

//Shape functions
static Shape * shape_ctor(int x, int y, char * type) {
  Shape * s = malloc(sizeof(Shape));
  s->x = x;
  s->y = y;
  s->type = type;
  s->shapeIF = malloc(sizeof(ShapeIF));
  return s;
}

//Rectangle functions
Rectangle * rectangle_ctor(double x, double y, double l, double w){
  Rectangle * r = malloc(sizeof(Rectangle));

  //Super
  Shape * shape = shape_ctor(x, y, "Rectangle");
  shape->instance = r;
  shape->shapeIF->getArea = &rectangle_getArea;
  r->shape = shape;
  r->shapeIF = shape->shapeIF;

  r->l = l;
  r->w = w;

  return r;
}

double rectangle_getArea(void * p){
  Shape * s = (Shape *) p;
  Rectangle * r = (Rectangle*)s->instance;
  return (r->l * r->w);
}

//Circle functions
Circle * circle_ctor(double x, double y, double r){
  Circle * c = malloc(sizeof(Rectangle));
 
   //Super
  Shape * shape = shape_ctor(x, y, "Circle");
  shape->instance = c;
  shape->shapeIF->getArea = &circle_getArea;
  c->shape = shape;
  c->shapeIF = shape->shapeIF;

  c->circleIF = malloc(sizeof(CircleIF));
  c->circleIF->getCircumference = &circle_getCircumference;

  c->r = r;

  return c;
}

double circle_getArea(void * p) {
  Shape * s = (Shape*) p;
  Circle * c = (Circle*) s->instance;
  return(c->r * c->r * 3.14);
}

double circle_getCircumference(void * p) {
  Shape * s = (Shape*) p;
  Circle * c = (Circle*) s->instance;
  return(2 * c->r * 3.14);
}

//ring functions
Ring * ring_ctor(double x, double y, double r, double r1){
  Ring * ring = malloc(sizeof(Ring));
  Circle * c = circle_ctor(x, y, r);
  ring->circle = c;
  ring->shape = c->shape;
  c->instance = ring;
  
  ring->shapeIF = c->shapeIF;
  ring->shapeIF->getArea = &ring_getArea;

  ring->circleIF = c->circleIF;
  ring->circleIF->getCircumference = &ring_getCircumference;

  ring->r1 = r1;
  
  return ring;
}

double ring_getArea(void * p){
  Shape * s = (Shape*)p;
  Circle * c = (Circle*)s->instance; 
  Ring * r = (Ring *)c->instance;

  double area = (3.14 * c->r * c->r) - (3.14 * r->r1 * r->r1);
  if (area < 0) {
    return -1*area;
  }
  return area;
}

double ring_getCircumference(void * p){
  Shape * s = (Shape*)p;
  Circle * c = (Circle*)s->instance; 
  Ring * r = (Ring *)c->instance;

  return (3.14 * c->r * 2) + (3.14 * r->r1 * 2);
}

int main(){
  Queue * q = newQueue();
  Shape * s1 = rectangle_ctor(10, 0, 10, 5)->shape;
  enqueue(q, s1);
  Shape * s2 = circle_ctor(10, 0, 1)->shape;
  enqueue(q, s2);
  Shape * s3 = rectangle_ctor(10, 0, 5, 5)->shape;
  enqueue(q, s3);
  Shape * s4 = circle_ctor(10, 0, 10)->shape;
  enqueue(q, s4);
  Shape * s5 = ring_ctor(0, 0, 3, 1)->shape;
  enqueue(q,s5);

  Circle * c = circle_ctor(10, 10, 3);
  printf("radius: %2f, circumference: %2f, Area: %2f\n", c->r, c->shapeIF->getArea(c->shape), c->circleIF->getCircumference(c->shape));

  Ring * r = ring_ctor(10, 10, 3, 10);
  printf("radius: %2f, circumference: %2f, Area: %2f\n", r->r1 , r->shapeIF->getArea(r->shape), r->circleIF->getCircumference(r->shape));

  while (q->size != 0) {
    Shape * s = (Shape*)dequeue(q);
    printf("%s\n", s->type);
    printf("The area is %.2f\n", s->shapeIF->getArea(s));
  }
}