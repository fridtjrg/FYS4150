import matplotlib.pyplot as plt
from math import *
import numpy as np
import sys

n = sys.argv[1]

#defines x, u and v lists
x =[]
u =[]
v =[]



with open("xandu_values_n="+str(n)+".txt") as myfile: #opens file
    for line in myfile:					#reads each line of the file
        mydata = line.split(", ")		#splits each line with the seperator
        x.append(float(mydata[0]))		#Appends values to x list
        u.append(float(mydata[1]))		#Appends values to u list

myfile.close()	#closes file

with open("xandv_values_n="+str(n)+".txt") as myfile: #opens file
    for line in myfile:                 #reads each line of the file
        mydata = line.split(", ")       #splits each line with the seperator
        v.append(float(mydata[1]))      #Appends values to v kist

myfile.close()  #closes file

x = np.array(x)
u = np.array(u)
v = np.array(v)#/-10000

#plots function u(x) 

plt.plot(x,u, label ="u values")   
plt.plot(x,v, label ="v values")



plt.xlabel("x-values")
plt.ylabel("u and v values")
plt.title("Comparison between u and v values (n="+str(n)+")")
plt.legend()
plt.grid()     
plt.savefig('u_and_v_plotls(n='+str(n)+').pdf')
plt.show()      

log_abs_error = np.log10(abs(u-v))


plt.plot(x,log_abs_error, label ="$log_{10}(\Delta)$")
plt.xlabel("x-values")
plt.ylabel("$log_{10}(\Delta)$")
plt.title("Plot of the absolute error (n="+str(n)+")")
plt.legend()
plt.grid()     
plt.savefig('abs-error(n='+str(n)+').pdf')
plt.show()    


log_rel_error = np.log10(abs((u-v)/u))

"""
for i in range(0,len(u)):
    log_rel_error.append(abs((u[i]-v[i])/u[i]))
"""

plt.plot(x,log_abs_error, label ="$log_10(\epsilon)$")
plt.xlabel("x-values")
plt.ylabel("$log_{10}(\epsilon$)")
plt.title("Plot of the realtive error (n="+str(n)+")")
plt.legend()
plt.grid()     
plt.savefig('rel-error(n='+str(n)+').pdf')
plt.show()    

