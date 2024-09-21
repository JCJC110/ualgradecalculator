def convert(grade):
    grades = {
        "A+": 15, "A": 14, "A-": 13, "B+": 12, "B": 11,
        "B-": 10, "C+": 9, "C": 8, "C-": 7, "D+": 6,
        "D": 5, "D-": 4, "E": 3, "F": 2
    }
    return grades.get(grade, None)

def classify(score):
    if score >= 12.5:
        return "1st Honors"
    elif score >= 10.0:
        return "2:1 Honors"
    elif score >= 7.0:
        return "2:2 Honors"
    elif score >= 4.0:
        return "3rd"
    elif score >= 3.0:
        return "Marginal Fail"
    elif score >= 1.0:
        return "Fail"
    else:
        return "non-submission"

def get_highest_classification(classification1, classification2):
    highest_classification = max(classification1, classification2)
    return classify(highest_classification)

def main():
    # Asking for info for year 2 grades
    totalgradesyear2 = int(input("Total number of units for calculation (yr 2): "))
    convertedgradesyr2 = [0] * totalgradesyear2
    creditsyear2 = [0] * totalgradesyear2
    creditstotalyr2 = 0

    # Asking for info for year 3 grades
    totalgradesyear3 = int(input("Total number of units for calculation (yr 3): "))
    convertedgradesyr3 = [0] * totalgradesyear3
    creditsyear3 = [0] * totalgradesyear3
    creditstotalyr3 = 0

    # (y2) convert letter grade to grade value; get credit info for each unit, e.g., A 20; B 20
    for i in range(totalgradesyear2):
        grade = input("Your grade for a unit (Y2): ")
        credit_year2 = int(input("Credits for this unit: "))
        grade_value = convert(grade)
        convertedgradesyr2[i] = grade_value
        creditsyear2[i] = credit_year2
        creditstotalyr2 += creditsyear2[i]

    # (y3) convert letter grade to grade value; get credit info for each unit
    for i in range(totalgradesyear3):
        grade = input("Your grade for a unit (Y3): ")
        credit_year3 = int(input("Credits for this unit: "))
        grade_value = convert(grade)
        convertedgradesyr3[i] = grade_value
        creditsyear3[i] = credit_year3
        creditstotalyr3 += creditsyear3[i]

    if creditstotalyr2 != 100:
        print("Wrong credit sum, should total to 100, try again")
        return 1

    if creditstotalyr3 != 120:
        print("Wrong credit sum, should total to 120, try again")
        return 1

    # Weighted conversion for grades in y2 and y3, e.g., A 20 = 14 * (20 / 100)
    weighted_grades_year2 = 0
    for i in range(totalgradesyear2):
        weight = creditsyear2[i] / 100
        weighted_grade = convertedgradesyr2[i] * weight
        weighted_grades_year2 += weighted_grade

    weighted_grades_year3 = 0
    for i in range(totalgradesyear3):
        weight = creditsyear3[i] / 120
        weighted_grade = convertedgradesyr3[i] * weight
        weighted_grades_year3 += weighted_grade

    print(f"Weighted year 2 grades: {weighted_grades_year2}")
    print(f"Weighted year 3 grades: {weighted_grades_year3}")

    # Classification 1
    classification1 = weighted_grades_year3
    print(f"Classification 1: {classification1}")

    # Classification 2
    class2_year2_30 = weighted_grades_year2 * 0.3
    class2_year3_70 = weighted_grades_year3 * 0.7
    classification2 = class2_year2_30 + class2_year3_70
    print(f"Classification 2: {classification2}")

    # Determine the highest classification
    highest_classification = get_highest_classification(classification1, classification2)
    print(f"Honors: {highest_classification}")
    return 0

if __name__ == "__main__":
    main()
