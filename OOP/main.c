#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

int main(){
  Employee ** employees = malloc(sizeof(Employee*) * 3);

  employees[0] = salary_ctor("thomas", 50000)->employee;

  employees[1] = hourly_ctor("thomas", 10.50, 2)->employee;

  employees[2] = commission_ctor("Nate", 100000, 15)->employee;

  for (int i=0; i<3; i++) {
    printf("Name: %s Pay: %.2f\n", employees[i]->name, employees[i]->employeeIF->getPay(employees[i]));
  }
}