from questions import *
from timer import *
import pandas as pd
import os

def check_test(test,timings_df,testing):
    if test in ('A','a'):
        timings_df["LCD Screen"] = lcd_test()
    elif test in ('B','b'):
        timings_df["8x8 Matrix"] = matrix_test()
    elif test in ('C','c'):
        timings_df["Haptic"] = haptic_test()
    elif test in ('D','d'):
        timings_df["Thermal"] = thermal_test()
    elif test in ('E','e'):
        timings_df["Auditory"] = auditory_test()
    elif test in ('X','x'):
        testing = False
    else:
        test = input("Wrong input: Please input A, B, C, D, E or X to exit\n")
        check_test(test)

    return timings_df, testing


def check_answer_al(answer,question,score,timings,quiz):
    if answer in ('A','B','C','D','a','b','c','d'):
        if answer.upper() == quiz[question]["answer"]:
            score += 1
            print("You got the right answer! Score = " + str(score) + '/10')
        else:
            print(quiz[question]["answer"])
            print("The answer was incorrect. Score = " + str(score) + '/10')
            pass
        question += 1
        time = toc()
        timings.append(time)
        tic()
    else:
        print("Wrong input: Please input A, B, C or D")

    return question,score,timings

def check_answer_num(answer,question,score,timings,quiz):
    if answer in ('1','2','3'):
        if answer == quiz[question]:
            score += 1
            print("You got the right answer! Score = " + str(score) + '/10')
        else:
            print("The answer was incorrect. Score = " + str(score) + '/10')
        question += 1
        time = toc()
        timings.append(time)
        tic()
    else:
        print("Wrong input: Please input 1, 2 or 3")

    return question,score,timings

def lcd_test():
    timings = []
    question = 1
    score = 0
    tic()
    while question < 11:    # 10 questions
        print("\nQuestion " + str(question) + ":")
        print("Please select the correct option from the following:\n" + lcd_quiz[question]["options"])
        answer = input("Enter Answer: ")

        question,score,timings = check_answer_al(answer,question,score,timings,lcd_quiz)
    print("\nYou have come to the end of this test. Thank you for your participation.")
    print(timings)

    return timings

def matrix_test():
    timings = []
    question = 1
    score = 0
    tic()
    while question < 11:    # 10 questions
        print("\nQuestion " + str(question) + ":")
        print("Please select the correct option from the following:\n" + matrix_quiz[question]["options"])
        answer = input("Enter Answer: ")

        question,score,timings = check_answer_al(answer,question,score,timings,matrix_quiz)
    print("You have come to the end of this test. Thank you for your participation.")
    print(timings)

    return timings

def haptic_test():
    timings = []
    question = 1
    score = 0
    tic()
    while question < 11:    # 10 questions
        print("\nQuestion " + str(question) + ":")
        print("Please select the vibrational motor (1,2 or 3) that you think vibrated")
        answer = input("Enter Answer: ")

        question,score,timings = check_answer_num(answer,question,score,timings,haptic_quiz)
    print("You have come to the end of this test. Thank you for your participation.")
    print(timings)

    return timings

def thermal_test():
    timings = []
    question = 1
    score = 0
    tic()
    while question < 11:    # 10 questions
        print("\nQuestion " + str(question) + ":")
        print("Please select the peltier chip (1,2 or 3) that you think turned cold")
        answer = input("Enter Answer: ")

        question,score,timings = check_answer_num(answer,question,score,timings,thermal_quiz)
    print("You have come to the end of this test. Thank you for your participation!")
    print(timings)

    return timings

def auditory_test():
    timings = []
    question = 1
    score = 0
    tic()
    while question < 11:    # 10 questions
        print("\nQuestion " + str(question) + ":")
        print("Please select the correct option from the following:\n" + auditory_quiz[question]["options"])
        answer = input("Enter Answer: ")

        question,score,timings = check_answer_al(answer,question,score,timings,auditory_quiz)
    print("You have come to the end of this test. Thank you for your participation.")
    print(timings)

    return timings

timings_df = pd.DataFrame({"LCD Screen":[],"8x8 Matrix":[],"Haptic":[],"Thermal":[],"Auditory":[]})
testing = True
person = 8

while testing == True:
    test = input("Please select test: (A) Visual-LCD Screen (B) Visual-8x8 Matrix (C) Haptic (D) Thermal (E) Auditory (X) To Exit\n")
    timings_df, testing = check_test(test,timings_df,testing)

timings_df.set_index([pd.Index([1,2,3,4,5,6,7,8,9,10])],inplace=True)
os.makedirs('Results', exist_ok=True)
timings_df.to_csv('Results/Timings_' + str(person) + '.csv')