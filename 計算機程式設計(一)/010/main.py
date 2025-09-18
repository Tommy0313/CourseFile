total = 0

nineone = int(input())
total += nineone
ninetwo = 0
if(nineone != 10):
    ninetwo = int(input())
    total += ninetwo
tenone = int(input())
total += tenone
tentwo = 0
if(tenone != 10):
    tentwo = int(input())
    total += tentwo
if((tenone + tentwo) == 10):
    extraone = int(input())
    total += extraone
if(tenone == 10):
    extratwo = int(input())
    total += extratwo

if(nineone == 10):
    total += (tenone+tentwo)
elif((nineone+ninetwo) == 10):
    total += tenone

print(total)
