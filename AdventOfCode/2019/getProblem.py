import urllib
import typing
import os
import sys
import http.client

def fetch(url: str, method='GET', headers={}) -> bytes:
    connection = http.client.HTTPSConnection('adventofcode.com')
    connection.request(method, url, headers=headers)
    resp = connection.getresponse()
    if resp.status == 404:
        print("Got status code 404, is the problem available yet?\nExiting...")
        exit()
    elif resp.status != 200:
        print("Got status code %d, something went wrong.\nExiting...")
        exit()
    return resp.read()

def getInput(day: int) -> str:
    cookie = ""
    if cookie == "":
        print("Please set your session cookie!")
        exit()
    return fetch("/2019/day/%d/input" % day, "GET", {'Cookie': "session=%s" % cookie})


try:
    day = int(sys.argv[1])
except:
    print("%s is not a number.\nPlease provide the problem number on which you want to work!" % sys.argv[1])
    exit()

print("Trying to import problem number %d" % day)
input = getInput(day)
print("Got input successfully!\n")

print("Trying to creating folder...")
if not os.path.exists(str(day)):
    os.makedirs(str(day))
    print("Created directory successfully!\n")
else:
    print("Directory already exists. Attempting to put files inside.\n")

print("Putting input file inside")
f = open("%d/input" % day, "w")
f.write(input.decode("utf-8"))
print("Wrote input to file!\n")

if not os.path.exists("%d/%da.cc" % (day, day)) or os.path.exists("%d/%db.cc" % (day, day)):
    if os.path.exists("template.cc"):
        print("Copying template file into directory")
        fTemplate = open("template.cc")
        fDest = open("%d/%da.cc" % (day, day), "w")
        fDest.write(fTemplate.read())

        fTemplate = open("template.cc")
        fDest = open("%d/%db.cc" % (day, day), "w")
        fDest.write(fTemplate.read())
        print("Copied template file to directory successfully.")
    else:
        print("Template file \"template.cc\" does not exist.\n")
else:
    print("C++ files already exist for this day. Not overriding them.")
