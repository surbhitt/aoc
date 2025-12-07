import os
import requests
import sys

my_cookie = {"session": "53616c7465645f5faab9015b3d5115b0d9eab461de89deaf4fd57c3b3d36fef3d6166cddcfc6ee09c5de4981784646a10818f5781b012bd91b42e95442f4e8ea"}
args = sys.argv 
if len(args) < 2:
    print("Usage: python get_input.py <n_puzzle_input>")
    exit(1)

n = args[1]
res = requests.get(f"https://adventofcode.com/2025/day/{n}/input", cookies=my_cookie)
if res.status_code != 200:
    print(f"** Something went wrong {res.status_code}**")
    print(res.text)
    exit(0)

if os.path.exists(f"input_{n}.txt"):
    print("-- Getting part 2 --")
    os.rename(f"input_{n}.txt", f"input_{n}_1.txt")

with open(f"input_{n}.txt", "w")  as f:
    f.write(res.text)
    print(f"-- DONE input_{n}.txt --")
