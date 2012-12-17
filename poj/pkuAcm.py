#!/usr/bin/python

import urllib
import urllib2
import cookielib
import re
import os
import time
import sys

def filter_tags(htmlstr):
    re_cdata=re.compile('//<!\[CDATA\[[^>]*//\]\]>',re.I)
    re_script=re.compile('<\s*script[^>]*>[^<]*<\s*/\s*script\s*>',re.I)#Script
    re_style=re.compile('<\s*style[^>]*>[^<]*<\s*/\s*style\s*>',re.I)#style
    re_br=re.compile('<br\s*?/?>')
    re_td=re.compile('<td\s*?/?>')
    re_h=re.compile('</?\w+[^>]*>')
    re_comment=re.compile('<!--[^>]*-->')
    s=re_cdata.sub('',htmlstr)
    s=re_script.sub('',s)
    s=re_style.sub('',s)
    s=re_br.sub('\n',s)
    s=re_td.sub(' ',s)
    s=re_h.sub('',s)
    s=re_comment.sub('',s)
    blank_line=re.compile('\n+')
    s=blank_line.sub('\n',s)
    s=replaceCharEntity(s)
    return s

def replaceCharEntity(htmlstr):
    CHAR_ENTITIES={'nbsp':' ','160':' ',
                'lt':'<','60':'<',
                'gt':'>','62':'>',
                'amp':'&','38':'&',
                'quot':'"','34':'"',}

    re_charEntity=re.compile(r'&#?(?P<name>\w+);')
    sz=re_charEntity.search(htmlstr)
    while sz:
        entity=sz.group()
        key=sz.group('name')
        try:
            htmlstr=re_charEntity.sub(CHAR_ENTITIES[key],htmlstr,1)
            sz=re_charEntity.search(htmlstr)
        except KeyError:
            htmlstr=re_charEntity.sub('',htmlstr,1)
            sz=re_charEntity.search(htmlstr)
    return htmlstr

def repalce(s,re_exp,repl_string):
    return re_exp.sub(repl_string,s)

if __name__ == '__main__':
    sourceFile = file(sys.argv[1])
    source = sourceFile.read()
    problemId = sys.argv[1][:-4]
    print "problem id "+problemId
    try:
        #url = 'http://acm.pku.edu.cn/JudgeOnline/login'
        url = 'http://poj.org'
        cookie = cookielib.CookieJar()
        opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cookie))
        urllib2.install_opener(opener)
        str = urllib.urlencode({
            'user_id1' : 'masque',
            'password1': '131415',
        })
        urllib2.urlopen(url,str)
        url = 'http://poj.org/submit?problem_id=' + problemId
        str=urllib.urlencode({
            'language' : '0',
            'problem_id' : problemId,
            'source' : source,
            'submit' : 'Submit',
        })
        urllib2.urlopen(url,str)
    #please wait for a minute, until the result comes out, i.e the result is not Compiling
        url = 'http://acm.pku.edu.cn/JudgeOnline/status'
        time.sleep(2)
        login_response = urllib2.urlopen(url)
        content = filter_tags(login_response.read())
        print content
    except:
        print '''If u are not in North Korea, there must be some problem with the Pku's ACM server!'''
