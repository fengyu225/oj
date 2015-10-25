import urllib2
import html2text
import sys
import os
import argparse

URL_PREFIX = "http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode="

def parse_args():
    options = argparse.ArgumentParser("Script for Downloading ZOJ Problems")
    options.add_argument("-p","--path", action="store", dest="path", required=True,help="Set Path of files of problems list")
    options.add_argument("-r","--result_dir", action="store",dest="result_dir",required=True,help="Set dir for downloaded problems")
    args = options.parse_args()
    return args


args = parse_args()


def get_problem(n):
    url = URL_PREFIX+str(n)
    with open(os.path.join(args.result_dir, str(n)), "w") as result_file:
        s = urllib2.urlopen(url).read().decode("utf-8", "ignore")
        t = html2text.html2text(s).encode("ascii", "ignore")
        result_file.write(t)
        result_file.flush()
        result_file.close()


if __name__ == "__main__":
    with open(args.path, "r") as f:
        problems = [l.strip() for l in f]
        map(get_problem, problems)

