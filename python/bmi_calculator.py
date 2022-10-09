def bmi_calculator(weight, height):
    bmi = weight / (height/100)**2

    if bmi < 18.5:
        print("BMI is falls within underweight range")
    elif bmi < 25:
        print("BMI is falls within healthy range")
    elif bmi < 30:
        print("BMI is falls within overweight range")
    else:
        print("BMI is falls within obesity range")


weight = float(input("Enter your weight in kg: "))
height = float(input("Enter your height in cm: "))
bmi_calculator(weight, height)
