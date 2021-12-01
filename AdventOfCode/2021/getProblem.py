#!/bin/python

# Usage: './getProblem.py 1' to get the input for day 1
import urllib
import typing
import os
import sys
import http.client

year = 2021

def getCookie() -> str:
    try:
        cookieFile = open(".cookie", "r")
        cookie = cookieFile.read().rstrip()
        return cookie
    except:
        sys.exit("Something went wrong while trying to get cookie. Do you have a \".cookie\" file with you session cookie in it?")

def fetch(url: str, method='GET', headers={}) -> bytes:
    connection = http.client.HTTPSConnection('adventofcode.com')
    connection.request(method, url, headers=headers)
    resp = connection.getresponse()
    if resp.status == 404:
        sys.exit("Got status code 404, is the problem available yet?\nExiting...")
    elif resp.status != 200:
        sys.exit("Got status code %d, something went wrong.\nExiting..." % resp.status)
    return resp.read()

def getInput(day: int) -> str:
    return fetch("/%d/day/%d/input" % (year, day), "GET", {'Cookie': "session=%s" % getCookie()})

if __name__ == '__main__':
    if len(sys.argv) != 2:
        sys.exit("Please provide exactly one command line argument: The day for which you want the input\nUsage example: ./getProblem 1")

    try:
        day = int(sys.argv[1])
    except:
        sys.exit("%s is not a number.\nPlease provide the day for which you want the input file!" % sys.argv[1])

    print("Trying to import problem number %d" % day)
    input = getInput(day)

    print("Trying to creating folder...")
    if not os.path.exists(str(day)):
        os.makedirs(str(day))
        print("Created directory %d successfully!" % day)
    else:
        print("Directory %d already exists. Attempting to put input file inside." % day)
    f = open("%d/input" % day, "w")
    f.write(input.decode("utf-8"))
    print("Wrote input to \"%d/input\"!" % day)
    sys.exit(0)
