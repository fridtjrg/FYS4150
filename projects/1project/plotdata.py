import matplotlib.pyplot as plt
from math import *
import numpy as np

#defines x, u and v lists
x =[]
u =[]
v =[]

with open('xanduvalues.txt') as myfile: #opens file
    for line in myfile:					#reads each line of the file
        mydata = line.split(", ")		#splits each line with the seperator
        x.append(float(mydata[0]))		#Appends values to x list
        u.append(float(mydata[1]))		#Appends values to u list

myfile.close()	#closes file

with open('xandv_values.txt') as myfile: #opens file
    for line in myfile:                 #reads each line of the file
        mydata = line.split(", ")       #splits each line with the seperator
        v.append(float(mydata[1]))      #Appends values to v kist

myfile.close()  #closes file

x = np.array(x)
u = np.array(u)
v = np.array(v)

#plots function u(x) 
plt.plot(x,u, label ="u values")   
plt.plot(x,v, label ="v values")

plt.xlabel("x-values")
plt.ylabel("u and v values")
plt.title("Comparison between u and v values")
plt.legend()
plt.grid()     
plt.savefig('u_and_v_plotls.pdf')
plt.show()      

log_abs_error = np.log10(abs(u-v))


plt.plot(x,log_abs_error, label ="log_10(delta)")
plt.xlabel("x-values")
plt.ylabel("log(delta)")
plt.title("Plot of the absolute error")
plt.legend()
plt.grid()     
plt.savefig('abs-error.pdf')
plt.show()    

log_rel_error = np.log10(abs(u-v)/u)
plt.plot(x,log_abs_error, label ="log_10(epsylon)")
plt.xlabel("x-values")
plt.ylabel("log(epsylon)")
plt.title("Plot of the realtive error")
plt.legend()
plt.grid()     
plt.savefig('rel-error.pdf')
plt.show()    