void main(){
    int first = 0, second = 0, third = 0, fourth = 0, fifth = 0, score = 0, firstBase = 0, secondBase = 0, thirdBase = 0, out = 0;
    int hit,pointComputeResult;

    scanf("%d",&hit);
    if(hit == 0){
        out += 1;
        first = -100;
    }
    first += hit;
    getchar();
    pointComputeResult = computePoint(first);
    if(pointComputeResult == 1){
        score+=1;
        first = -100;
    }

    scanf("%d",&hit);
    if(hit == 0){
        out += 1;
        second = -100;
    }
    first += hit;
    second += hit;
    getchar();
    pointComputeResult = computePoint(first);
    if(pointComputeResult == 1){
        score+=1;
        first = -100;
    }
    pointComputeResult = computePoint(second);
    if(pointComputeResult == 1){
        score+=1;
        second = -100;
    }

    scanf("%d",&hit);
    if(hit == 0){
        out += 1;
        third = -100;
    }
    if(out==3){
        first = -100;
        second = -100;
        third = -100;
        out = 0;
    }
    first += hit;
    second += hit;
    third += hit;
    pointComputeResult = computePoint(first);
    if(pointComputeResult == 1){
        score+=1;
        first = -100;
    }
    pointComputeResult = computePoint(second);
    if(pointComputeResult == 1){
        score+=1;
        second = -100;
    }
    pointComputeResult = computePoint(third);
    if(pointComputeResult == 1){
        score+=1;
        third = -100;
    }
    getchar();

    scanf("%d",&hit);
    if(hit == 0){
        out += 1;
        fourth = -100;
    }
    if(out==3){
        first = -100;
        second = -100;
        third = -100;
        fourth = -100;
        out = 0;
    }
    first += hit;
    second += hit;
    third += hit;
    fourth += hit;
    getchar();
    pointComputeResult = computePoint(first);
    if(pointComputeResult == 1){
        score+=1;
        first = -100;
    }
    pointComputeResult = computePoint(second);
    if(pointComputeResult == 1){
        score+=1;
        second = -100;
    }
    pointComputeResult = computePoint(third);
    if(pointComputeResult == 1){
        score+=1;
        third = -100;
    }
    pointComputeResult = computePoint(fourth);
    if(pointComputeResult == 1){
        score+=1;
        fourth = -100;
    }

    scanf("%d",&hit);
    if(hit == 0){
        out += 1;
        fifth = -100;
    }
    if(out==3){
        first = -100;
        second = -100;
        third = -100;
        fourth = -100;
        fifth = -100;
        out = 0;
    }
    first += hit;
    second += hit;
    third += hit;
    fourth += hit;
    fifth += hit;
    pointComputeResult = computePoint(first);
    if(pointComputeResult == 1){
        score+=1;
        first = -100;
    }
    pointComputeResult = computePoint(second);
    if(pointComputeResult == 1){
        score+=1;
        second = -100;
    }
    pointComputeResult = computePoint(third);
    if(pointComputeResult == 1){
        score+=1;
        third = -100;
    }
    pointComputeResult = computePoint(fourth);
    if(pointComputeResult == 1){
        score+=1;
        fourth = -100;
    }
    pointComputeResult = computePoint(fifth);
    if(pointComputeResult == 1){
        score+=1;
        fifth = -100;
    }
    if(first==1 || second==1 || third==1 || fourth==1 || fifth==1){
        firstBase = 1;
    }
    if(first==2 || second==2 || third==2 || fourth==2 || fifth==2){
        secondBase = 1;
    }
    if(first==3 || second==3 || third==3 || fourth==3 || fifth==3){
        thirdBase = 1;
    }
    printf("%d",score);
    printf("\n%d %d %d",firstBase,secondBase,thirdBase);
}

int computePoint(int position){
    if(position >= 4){
        position = -100;
        return 1;
    }
    return 0;
}
