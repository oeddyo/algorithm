#!/usr/bin/python
# -*- coding: utf-8 -*-



class Predictor():
    def __init__(self):
        self.text = raw_input().lower()
        self.sentences = self.text.split('.')

    
    def count_word_in_sent(self, word, sentence):
        words_list = ['his', 'her', 'he', 'she']
        cnt = 0
        for w in words_list:
            if sentence.find(w)!=-1:
                cnt += 1
        return cnt

    def query(self, name):
        person = 0
        place = 0
        for n, sentence in enumerate(self.sentences):
            if sentence.find(name)!=-1:
                if n+1<len(self.sentences):
                    next_sent_cnt = self.count_word_in_sent(name, self.sentences[n+1])
                    if next_sent_cnt >=1:
                        person += 1
                if sentence.find('in', 0, sentence.find(name)-1)!=-1:
                    place += 2
        print place, person
        if person < place :
            print 'place'
        else:
            print 'person'
    
p = Predictor()
N = int(raw_input())
for i in range(N):
    p.query(raw_input().lower())


