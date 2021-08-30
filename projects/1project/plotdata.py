import matplotlib.pyplot as plt

#defines x and u arrays
x =[]
u =[]

with open('xanduvalues.txt') as myfile: #opens file
    for line in myfile:					#reads each line of the file
        mydata = line.split(", ")		#splits each line with the seperator
        x.append(float(mydata[0]))		#Appends values to x array
        u.append(float(mydata[1]))		#Appends values to u array

myfile.close()	#closes file

#plots function u(x)
plt.plot(x,u)   
plt.grid()     
plt.show()      