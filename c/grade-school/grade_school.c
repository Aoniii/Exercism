#include "grade_school.h"

void init_roster(roster_t *roster) {
	roster->count = 0;
}

bool add_student(roster_t *roster, char *name, uint8_t grade) {
	if (roster->count >= MAX_STUDENTS)
		return (false);
	if (strlen(name) >= MAX_NAME_LENGTH)
		return (false);

	for (size_t i = 0; i < roster->count; i++)
		if (strcmp(roster->students[i].name, name) == 0)
			return (false);

	student_t student = {0};
	student.grade = grade;
	strncpy(student.name, name, MAX_NAME_LENGTH);

	size_t pos = 0;
	while (pos < roster->count) {
		student_t *cur = &roster->students[pos];
		if (grade < cur->grade)
			break;
		if (grade == cur->grade && strcmp(name, cur->name) < 0)
			break;
		pos++;
	}

	for (size_t i = roster->count; i > pos; i--)
		roster->students[i] = roster->students[i - 1];

	roster->students[pos] = student;
	roster->count++;
	return (true);
}

roster_t get_grade(roster_t *roster, uint8_t grade) {
	roster_t ret;
	init_roster(&ret);

	for (size_t i = 0; i < roster->count; i++)
		if (roster->students[i].grade == grade)
			add_student(&ret, roster->students[i].name, grade);
	return (ret);
}
