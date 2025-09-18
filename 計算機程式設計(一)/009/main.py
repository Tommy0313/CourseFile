ax1 = int(input())
ax2 = int(input())
bx1 = int(input())
bx2 = int(input())
cx1 = int(input())
cx2 = int(input())

print(len(set([x for x in range(ax1,ax2)] + [x for x in range(bx1,bx2)] + [x for x in range(cx1,cx2)])))