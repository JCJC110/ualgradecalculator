#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int convert(char *grade);
const char *classify(float score);
const char *get_highest_classification(float class1, float class2);

int comparator(const void *a, const void *b) {
    double gradeA = ((*(double **)a)[0]);
    double gradeB = ((*(double **)b)[0]);
    if (gradeA > gradeB) return -1;
    if (gradeA < gradeB) return 1;
    return 0;
}

int main(void)
{

	//asking for info for year 2 grades
	char *totalgradesyear2_str = get_string("Total number of units for calculation(yr 2): ");
	int totalgradesyear2 = atoi(totalgradesyear2_str);
	int convertedgradesyr2 [totalgradesyear2];
	int creditsyear2 [totalgradesyear2];
	int creditstotalyr2 = 0;

	//asking for info for year 3 grades
	char *totalgradesyear3_str = get_string("Total number of units for calculation(yr 3): ");
	int totalgradesyear3 = atoi(totalgradesyear3_str);
	int convertedgradesyr3 [totalgradesyear3];
	int creditsyear3 [totalgradesyear3];
	int creditstotalyr3 = 0;

	//(y2) convert letter grade to grade value; get credit info for each unit, eg. A 20; B 20
	if(totalgradesyear2 != 0)
	{
		for (int i=0; i<totalgradesyear2; i++)
		{
			char *grade = get_string("your grade for a unit(Y2): ");
			int credit_year2 = get_int("Credits for this unit: ");
			int grade_value = convert(grade);
			convertedgradesyr2[i] = grade_value;
			creditsyear2 [i] = credit_year2;
			creditstotalyr2 += creditsyear2[i];
		}
	}

	//(y3) convert letter grade to grade value; get credit info for each unit
	for (int i=0; i<totalgradesyear3; i++)
	{
		char *grade = get_string("your grade for a unit(Y3): ");
		int credit_year3 = get_int("Credits for this unit: ");
		int grade_value = convert(grade);
		convertedgradesyr3[i] = grade_value;
		creditsyear3 [i] = credit_year3;
		creditstotalyr3 += creditsyear3[i];
	}

	if (creditstotalyr2 != 100 && totalgradesyear2 != 0)
	{
		printf("wrong credit sum, should total to 100, try again\n");
		return 1;
	}

	if (creditstotalyr3 != 120)
	{
		printf("wrong credit sum, should total to 120, try again\n");
		return 1;
	}

	//weighted conversion for grades in y2 and y3 ie. A 20 = 14x(20/100)
	float weighted_grades_year2 =0;
	for(int i = 0; i<totalgradesyear2; i++)
	{
		float weight = (float)creditsyear2[i] / 100;
        float weighted_grade = convertedgradesyr2[i] * weight;
        weighted_grades_year2 += weighted_grade;
	}

	float weighted_grades_year3 =0;
	for(int i = 0; i<totalgradesyear3; i++)
	{
		float weight = (float)creditsyear3[i] / 120;
        float weighted_grade = convertedgradesyr3[i] * weight;
        weighted_grades_year3 += weighted_grade;
	}
	printf("Weighted year 2 grades: %f\n", weighted_grades_year2);
	printf("Weighted Year 3 Grades: %f\n", weighted_grades_year3);

	//classification 1
	float classification1 = weighted_grades_year3;
	printf("Classification 1: %f\n", classification1);

	//classification 2
	float class2_year2_30 = weighted_grades_year2 * 0.3;
	float class2_year3_70 = weighted_grades_year3 * 0.7;
	float classification2 = class2_year2_30 + class2_year3_70;
	printf("Classification 2: %f\n", classification2);

	//determine the highest classification
	const char *highest_classification = get_highest_classification(classification1, classification2);
	printf("Honors: %s\n", highest_classification);
	return 0;
	//
}


int convert(char *grade)
{
	if (strcmp(grade, "A+") == 0)
		return 15;
	if (strcmp(grade, "A") == 0)
		return 14;
	if (strcmp(grade, "A-") == 0)
		return 13;
	if (strcmp(grade, "B+") == 0)
		return 12;
	if (strcmp(grade, "B") == 0)
		return 11;
	if (strcmp(grade, "B-") == 0)
		return 10;
	if (strcmp(grade, "C+") == 0)
		return 9;
	if (strcmp(grade, "C") == 0)
		return 8;
	if (strcmp(grade, "C-") == 0)
		return 7;
	if (strcmp(grade, "D+") == 0)
		return 6;
	if (strcmp(grade, "D") == 0)
		return 5;
	if (strcmp(grade, "D-") == 0)
		return 4;
	if (strcmp(grade, "E") == 0)
		return 3;
	if (strcmp(grade, "F") == 0)
		return 2;

	else
	printf("please enter a valid letter grade \n");
	return false;


}

const char* get_highest_classification(float classification1, float classification2)
{
    float highest_classification = (classification1 > classification2) ? classification1 : classification2;
    return classify(highest_classification);
}

const char *classify(float score)
{
    if (score >= 12.5)
    {
        return "1st Honors"; // First Honours
    }
    else if (score >= 10.0)
    {
        return "2:1 Honors"; // 2:1
    }
    else if (score >= 7.0)
    {
        return "2:2 Honors"; // Second Honours
    }
    else if (score >= 4.0)
    {
        return "3rd"; // Third Honours
    }
	else if (score >= 3.0)
    {
        return "Marginal Fail"; // Third Honours
    }
	else if (score >= 1.0)
    {
        return "Fail"; // Third Honours
    }
    else
    {
        return "non-submission"; // Fail
    }
}
