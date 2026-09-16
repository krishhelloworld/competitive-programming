import sys
"""
its not python if it cant sysssssssssss!!!!!!
"""
from collections import deque

b=-1
n="n"
s="n"


xarr=deque()
oarr=deque()
win = [
    [0,1,2],
    [3,4,5],
    [6,7,8],
    [0,4,8],
    [2,4,6],
    [1,3,6],
    [1,4,7],
    [2,5,8]
]


theboard={0:' ', 1:' ', 2:' ',
          3:' ', 4:' ', 5:' ', 
          6:' ', 7:' ', 8:' '}

theNboard={0:'0', 1:'1', 2:'2',
          3:'3', 4:'4', 5:'5', 
          6:'6', 7:'7', 8:'8'}

def printboard(board):
    print()
    print(board[0]+'|'+board[1]+'|'+board[2])
    print('-+-+-')
    print(board[3]+'|'+board[4]+'|'+board[5])
    print('-+-+-')
    print(board[6]+'|'+board[7]+'|'+board[8])
    print()



def startgame():
    print('please ignore the grammar like your x does')
    print('do you want boards with number or only the board')
    print('type n for number board')
    print('type anything else gap board')

def check(arr):
    found =False
    for rows in win:
        count=0
        for x in rows:
            for pos in arr:
                if x == pos:
                    count+=1
                    found=True
                
                if count==3:
                    return True
            if found==False:
                break


def add(arr,pos,xoarr,xo,s):
    while pos in xoarr or pos in  arr:
        print('already occupied')
        pos=int(input())
    poparray(arr,xoarr)
    arr.append(pos)
    theNboard[pos]=xo
    theboard[pos]=xo
    if s==n:
        printboard(theNboard)
    else:
        printboard(theboard)

def poparray(arr,xoarr):
    if len(arr)>=3:
        theNboard[arr[0]]=' '
        theboard[arr[0]]=' '
        arr.popleft()


def process(arr,xo,ox):
    if check(arr):
        print(ox,'wins')
        sys.exit()
    else:
        print(xo,' chance')


if __name__=="__main__":
    startgame()
    s=str(input())
    if s==n:
        printboard(theNboard)
    else:
        printboard(theboard)

    print('x chance' )

    for line in  sys.stdin.buffer:
        for token in line.split():
            pos = int(token)
            b+=1
            if b%2==0:
                add(xarr,pos,oarr,'X',s)
                process(xarr,'O','X')
            else:
                add(oarr,pos,xarr,'O',s)
                process(oarr,'X','O')


"""
it will not verify the number of pos its your authority while playing to give the right input ,to win or you will lose
only things is the pos <9 in process of while loop
because we human who write code
input=sys.stdin.readline() cause an error to me 
whlile doing the s=str(input()) i still cnat understand that thats teh logic of s is poor in this code
"""
