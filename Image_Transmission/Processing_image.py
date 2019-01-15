#open a text file in read mode
f = open("aaa.txt", "r")
 
#pull all the data out of the file into a variable
t = list(f.read())
#print(t)
c=int(t.index('\n'))
r=int(len(t)/(t.index('\n')+1))

for i in range(r):
    t.remove('\n')
#print(t)

t=[int(i) for i in t]
print(str(r)+ " "+str(c))
for i in range(len(t)):
    print(t[i],end=" ")


