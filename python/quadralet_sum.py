a=[1,0,-1,0,-2,2]

def quadraletSum(a):
    """
    Find's the quadraltes whose sum is equal to zero
    """
    t=0
    if len(a)==0:
        return
    fo=[]
    a.sort()
    n=len(a)
    for i in range(n):
        t3=t-a[i]
        for j in range(i+1,n):
            t2=t3-a[j]
            f=j+1
            b=n-1
            while f<b:
                ts=a[f]+a[b]
                if ts<t2:
                    f+=1
                elif ts>t2:
                    b-=1
                elif ts==t2:
                    rt1=[a[i],a[j],a[f],a[b]]
                    fo.append(rt1)
                    while f<b and a[f]==rt1[2]:
                        f+=1
                    while f<b and a[b]==rt1[3]:
                        b-=1
            while j+1<n and a[j]==a[j+1]:
                j+=1
        while i+1<n and a[i]==a[i+1]:
            i+=1
    return fo


z=quadraletSum(a)
for i in z:
    print(i)