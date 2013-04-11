import urllib2
import time
import re

def isTerminated(base_url, x, y):
    url = formURL(base_url, x,y)
    print 'cur_url is ', url
    text = getPageText(url)
    if text.startswith('end:true'):
        return True

def parseNextSteps( s):
    slash_pos = s.find("/")
    s = s[slash_pos+1:]
    pattern = "\(.*?\)"
    res = re.findall(pattern, s)
    to_return = []
    for r in res:
        t = r[1:-1].split(',')
        to_return.append( (int(t[0]), int (t[1])) )
    return to_return

def formURL(base_url, x, y):
    return base_url+"x="+str(x)+"&y="+str(y)

def getInitial(url):
    response = urllib2.urlopen(url)
    res_url = response.url
    base_url_pos = res_url.find("x=")
    base_url = res_url[:base_url_pos]
    return base_url, response.read()

def getPageText(url):
    response = urllib2.urlopen(url)
    return response.read()

def getNext(base_url, x, y):
    url = formURL(base_url, x , y)
    text = getPageText(url)
    return parseNextSteps(text)

def main():
    MAXN = 100

    #open the url given to start a maze journey! 
    base_url, text = getInitial('http://challenge.flipboard.com/m') #the id of the task change every time.keep track of this base id as a base_url
    print 'base is ', base_url
    initial_step = parseNextSteps(text)   #initial
    visited =[ [0 for i in range(MAXN)] for j in range(MAXN) ]
    queue = []
    queue.append( (0,0) )
    while( len(queue)!=0 ):
        cur = queue.pop()
        visited[cur[0]][cur[1]] = True
        time.sleep(0.00001)
        if(isTerminated(base_url, cur[0], cur[1])):
            print 'answer is ',cur[0], cur[1]
            break
        next_steps = getNext(base_url, cur[0], cur[1])
        print 'cur at ',cur, 'next would be', next_steps
        for ns in next_steps:
            if visited[ns[0]][ns[1]] == False:
                queue.append( ns )

main()


