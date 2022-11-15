import sys
sys.stdin = open('input.txt', 'r')

ranked_no=int(input())
ranked=list(map(int,input().split()))
player_no=int(input())
player=list(map(int,input().split()))
# 
v = list(set(ranked))
v.sort()

# print("ranked ",ranked)
print("set ranked",v)

def l(ranked_no,v,player_no,player):
    jd=0
    x =0 
    for i in range(player_no):
        h=player[i]
        for j in range(x, len(v)):
            r = v[j]
            if h>v[len(v)-1]:
                print(1)
                break
            elif h>r:
                print ("2 ",len(v)-v.index(r))
                if player[i] != player[i+1]:
                    x = v.index(r) +1
                break
            elif h==r:
                print("1 ",len(v)-v.index(r))
                if player[i] != player[i+1] -1:
                    x = v.index(r) +1
                break
            
        
        
l(ranked_no,v,player_no,player)