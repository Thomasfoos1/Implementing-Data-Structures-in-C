#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct{
  double (*getPay)(void*);
} EmployeeIF;

typedef struct{
  char * name;
  void * instance;
  EmployeeIF * employeeIF;
} Employee;

typedef struct{
  double salary;
  void * instance;
  Employee * employee;
  EmployeeIF * employeeIF;
} SalaryEmployee;

SalaryEmployee * salary_ctor(char * name, double salary);
double salary_getPay(Employee *);

typedef struct{
  double wage;
  int hours;
  void * instance;
  Employee * employee;
  EmployeeIF * employeeIF;
} HourlyEmployee;

HourlyEmployee * hourly_ctor(char * name, double wage, int hours);
double hourly_getPay(Employee *);

typedef struct{
  double totalSales;
  double commisionRate;
  void * instance;
  Employee * employee;
  EmployeeIF * employeeIF;
} CommissionEmployee;

CommissionEmployee * commission_ctor(char * name, double totalSales, double commisionRate);
double commission_getPay(Employee * e);

#endif