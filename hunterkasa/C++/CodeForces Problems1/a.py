n,m,k = map(int,input().split())

x = pow((1 << n) + (1 << m),k)

cnt = bin(x).count('1')
print(cnt)