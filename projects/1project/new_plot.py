import matplotlib.pyplot as plt
from math import *
import numpy as np
import sys


#defines x, u and v lists
x =[]
u =[]
v =[]

#--------------Task 7 comparing u anv v-----------------

with open("xandu_values_n=100000.txt") as myfile: #opens file
    for line in myfile:                 #reads each line of the file
        mydata = line.split(", ")       #splits each line with the seperator
        x.append(float(mydata[0]))      #Appends values to x list
        u.append(float(mydata[1]))      #Appends values to u list
myfile.close()

plt.plot(x,u, label ="u values (n=100000)")   

x=[]

for i in range(1,5):
    n= 10**i

    with open("xandv_values_n="+str(n)+".txt") as myfile: #opens file
        for line in myfile:                 #reads each line of the file
            mydata = line.split(", ")       #splits each line with the seperator
            x.append(float(mydata[0]))
            v.append(float(mydata[1]))      

    myfile.close()  #closes file


    x = np.array(x)
    v = np.array(v)


    plt.plot(x,v, label ="v values (n="+str(n)+")")

    #empties lists for next itteration
    x=[]
    v=[]

plt.xlabel("x-values")
plt.ylabel("u and v values")
plt.title("Comparison between u and v values")
plt.legend()
plt.grid()     
plt.savefig('u_and_v_plotls.pdf')
#plt.show()    


x =[]
u =[]
v =[] 

#-------------- Task 8: plots the log(abs) error--------------


for i in range(1,5):
    n= 10**i


    with open("xandu_values_n="+str(n)+".txt") as myfile: #opens file
        for line in myfile:                 #reads each line of the file
            mydata = line.split(", ")       #splits each line with the seperator
            x.append(float(mydata[0]))      #Appends values to x list
            u.append(float(mydata[1]))      #Appends values to u list
    myfile.close() 


    with open("xandv_values_n="+str(n)+".txt") as myfile: #opens file
        for line in myfile:                 #reads each line of the file
            mydata = line.split(", ")       #splits each line with the seperator
            v.append(float(mydata[0]))

    myfile.close()  #closes file

    #converts to arrays
    x = np.array(x)
    v = np.array(v)
    u = np.array(u)

    #calculates the absolute error
    log_abs_error = np.log10(abs(u-v))

    #plots function u(x) 
    plt.plot(x,log_abs_error, label ="$log_{10}(\Delta)$(n="+str(n)+")")

    x=[]
    v=[]
    u=[]



plt.xlabel("x-values")
plt.ylabel("$log_{10}(\Delta)$")
plt.title("Plot of the absolute error")
plt.legend()
plt.grid()     
plt.savefig('abs-error.pdf')
#plt.show()    



#-------------Task 8: plots the realtive error--------------



for i in range(1,5):
    n= 10**i


    with open("xandu_values_n="+str(n)+".txt") as myfile: #opens file
        for line in myfile:                 #reads each line of the file
            mydata = line.split(", ")       #splits each line with the seperator
            x.append(float(mydata[0]))      #Appends values to x list
            u.append(float(mydata[1]))      #Appends values to u list
    myfile.close() 


    with open("xandv_values_n="+str(n)+".txt") as myfile: #opens file
        for line in myfile:                 #reads each line of the file
            mydata = line.split(", ")       #splits each line with the seperator
            v.append(float(mydata[0]))

    myfile.close()  #closes file

    """Encountered divide by zero problem"""
    x = np.array(x[1:-1])
    v = np.array(v[1:-1])
    u = np.array(u[1:-1])



    log_rel_error = np.log10(abs((u-v)/u))

    print("The biggest relative error for n="+ str(n)+", is "+str(np.max(log_rel_error)))

    plt.plot(x,log_rel_error, label ="$log_{10}(\epsilon)$(n="+str(n)+")")

    x=[]
    v=[]
    u=[]




plt.xlabel("x-values")
plt.ylabel("$log_{10}(\epsilon$)")
plt.title("Plot of the realtive error")
plt.legend()
plt.grid()     
plt.savefig('rel-error.pdf')
#plt.show()    

