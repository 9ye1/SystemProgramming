#ifndef _POLYL_

#define _POLYL_

#include "list.h"

List makePolyList(double input[], int size);
void printPolyList(List fx);
int compExp(Element e1, Element e2);
Element addTwoElement(Element e1, Element e2);
List addPolyList(List l1, List l2);
List subPolyList(List l1, List l2);

#endif