height = float(input())
weight = float(input())


BMI = str(format(weight / (height*height), '.5f'))
BMI = BMI[:BMI.find(".")+4]

if(int(BMI[-1])<5):
    BMI = float(BMI[:-1])
elif((int(BMI[-2])%2==0 and int(BMI[-1])==5)):
    BMI = float(BMI[:-1])
else:
    BMI = float(BMI[:-1])+0.01


print(format(BMI, '.2f'))


