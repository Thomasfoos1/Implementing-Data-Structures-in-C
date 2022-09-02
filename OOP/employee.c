#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

static Employee * employee_ctor(char* name){
  Employee * e = malloc(sizeof(Employee));
  e->name = name;
  e->employeeIF = malloc(sizeof(EmployeeIF));

  return e;
}

SalaryEmployee * salary_ctor(char * name, double salary){
  SalaryEmployee * s = malloc(sizeof(SalaryEmployee));

  //super
  Employee * e = employee_ctor(name);
  e->instance = s;
  s->employee = e;
  e->employeeIF->getPay = &salary_getPay;
  s->employeeIF = e->employeeIF;

  s->salary = salary;

  return s;
}

double salary_getPay(Employee * e) {
  SalaryEmployee* s = (SalaryEmployee*) e->instance;
  return s->salary;
}

HourlyEmployee * hourly_ctor(char * name, double wage, int hours){
  HourlyEmployee * h = malloc(sizeof(HourlyEmployee));

  //super
  Employee * e = employee_ctor(name);
  e->instance = h;
  h->employee = e;
  e->employeeIF->getPay = &hourly_getPay;
  h->employeeIF = e->employeeIF;

  h->wage = wage;
  h->hours = hours;

  return h;
}

double hourly_getPay(Employee * e){
  HourlyEmployee * h = (HourlyEmployee*)e->instance;
  return h->hours * h->wage;
}

//Commission Employee
CommissionEmployee * commission_ctor(char * name, double totalSales, double commisionRate) {
  CommissionEmployee* c = malloc(sizeof(CommissionEmployee));

  //super
  Employee* e = employee_ctor(name);
  e->employeeIF->getPay = &commission_getPay;
  e->instance = c;
  c->employee = e;
  c->employeeIF = e->employeeIF;

  c->totalSales = totalSales;
  c->commisionRate = commisionRate;

  return c;
}

double commission_getPay(Employee * e){
  CommissionEmployee* c = (CommissionEmployee*) e->instance;
  return c->commisionRate * 0.01 * c->totalSales;
}