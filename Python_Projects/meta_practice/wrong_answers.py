#!/usr/bin/env python3

def getWrongAnswers(N: int, C: str) -> str:
  # Write your code here
  wrongAnswer = ""
  
  for i in C:
    if i == "A":
      wrongAnswer += "B"
    else:
      wrongAnswer += "A"
  return wrongAnswer

N = 3
C = "ABA"

print(getWrongAnswers(N, C))

N = 5
C = "AAAAA"

print(getWrongAnswers(N, C))