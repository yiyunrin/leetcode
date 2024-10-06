class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        s1 = sentence1.split(' ')
        s2 = sentence2.split(' ')
        if len(s1) > len(s2):
            tmp = s1
            s1 = s2
            s2 = tmp
        n1 = len(s1); n2 = len(s2)
        front = 0; back = 0
        while(front < n1 and s1[front] == s2[front]):
            front += 1
        while(back < n1 and s1[n1 - back - 1] == s2[n2 - back - 1]):
            back += 1
        return front + back >= n1
