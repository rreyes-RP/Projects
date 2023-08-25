'''
Write a program that interprets the Body Mass Index (BMI) based on a user's weight and height.

It should tell them the interpretation of their BMI based on the BMI value.

Under 18.5 they are underweight
Over 18.5 but below 25 they have a normal weight
Over 25 but below 30 they are slightly overweight
Over 30 but below 35 they are obese
Above 35 they are clinically obese.
'''
import math

def checkBmi(height, weight):
    bmi = math.ceil(weight / height ** 2)
    
    if bmi < 18.5:
        print(f"Your BMI is {bmi}, you are underweight.")
    elif bmi >= 18.5 and bmi < 25:
        print(f"Your BMI is {bmi}, you have a normal weight.")
    elif bmi >= 25 and bmi < 30:
        print(f"Your BMI is {bmi}, you are slightly overweight.")
    elif bmi >= 30 and bmi < 35:
        print(f"Your BMI is {bmi}, you are obese.")
    else:
        print(f"Your BMI is {bmi}, you are clinically overweight.")
    pass


height = float(input("enter your height in m: "))
weight = float(input("enter your weight in kg: "))
checkBmi(height,weight)    
