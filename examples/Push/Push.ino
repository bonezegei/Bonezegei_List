/*
  Author: Jofel Batutay
  Date: July 2023

  Basic Example for Bonezegei_List
  
  It has mostly similiar functions with the standard "list" in c++
*/


#include "Bonezegei_List.h"

typedef struct {
  uint64_t id;
  char *name;
} student;

Bonezegei_List<uint16_t> list;
Bonezegei_List<student> students;


void setup() {
  Serial.begin(115200);

  //Push Integer
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  list.push_back(5);
  list.push_back(6);

  Serial.println("\n Integer Sample:");
  for (uint16_t number : list) {
    Serial.println(number);
  }

  //Push Object Structure
  students.push_front(student{ 2023001, (char *)"Bonezegei" });
  students.push_front(student{ 2023002, (char *)"Library" });
  students.push_back(student{ 2023003, (char *)"List" });

  Serial.println("\n Structure Sample:");
  for (student stud : students) {
    Serial.print("ID: ");
    Serial.print((int)stud.id);
    Serial.print("  name: ");
    Serial.println(stud.name);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
