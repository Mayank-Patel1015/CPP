#include "records.h"

Student::Student(int id_i, std::string name_i)
{
  id = id_i;
  name = name_i;
}

int Student::get_id()
{
  return id;
}
std::string Student::get_name()
{
  return name;
}

Course::Course(int id_i, std::string name_i, unsigned char credits_i)
{
  id = id_i;
  name = name_i;
  credits = credits_i;
}

int Course::get_id()
{
  return id;
}
std::string Course::get_name()
{
  return name;
}
int Course::get_credits()
{
  return credits;
}

Grade::Grade(int student_id_i, int course_id_i, char grade_i)
{
  student_id = student_id_i;
  course_id = course_id_i;
  grade = grade_i;
}
int Grade::get_student_id()
{
  return student_id;
}
int Grade::get_course_id()
{
  return course_id;
}
char Grade::get_grade()
{
  return grade;
}