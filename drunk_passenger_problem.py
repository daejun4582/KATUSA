import random as rd
import time
import datetime


def trial():
    seat = [False]*100
    seat_remain = [i for i in range(1,101)]
    
    for i in range(0,99) :
        if i != 0 and seat[i] == False:
            seat[i] = True
            seat_remain.remove(i+1)
        else:
            choice = rd.choice(seat_remain)
            seat[choice-1] = True
            seat_remain.remove(choice)  
    
    if(seat[99]):
        return False
    return True
            
def run(iter_num):
    
    success_cnt = 0
    
    
    
    for i in range(iter_num):
        if trial() :
            success_cnt +=1
    
    
    
    success_rate = success_cnt / iter_num 
    success_percent = success_rate * 100
    
    
    
    print("%7d 번 실행한 결과, 성공 확률은  %.1f%%(%f)입니다." % (iter_num,success_percent,success_rate))



iter_num = 1

start = time.time()

for i in range(7):    
    run(iter_num)
    iter_num *= 10
    
end = time.time()

sec = end - start
result = datetime.timedelta(seconds=sec)

print(result,end = "")
print(" 초 소요되었습니다.")


     
    