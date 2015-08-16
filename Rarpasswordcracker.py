    import os
    import sys
    import time
     
    # Written by Jelmer de Hen - h.ackack.net
     
    def bfcrackrar(wlistlocation,rarfile):
    	wlist=open(wlistlocation,"r")
    	print "Going to crack "+rarfile+" with wordlist "+wlistlocation
    	tries=0
    	start=time.time()
    	for word in wlist:
    		if(word[-1]=="\n"):
    			word=word[:-1]
    		if word=="":
    			word="NULL"
     
    		if word[0]=="#":
    			print "Passing "+word
    			word="NULL"
    		if word!="NULL":
    			print "Trying "+word
    			a=os.popen("unrar t -y -p"+word+" "+rarfile+" 2>&1 | grep 'All OK'")
    			tries+=1
    			for i in a.readlines():
    				if i=="All OK\n":
    					print "Found password "+repr(word)
    					print "Amount of passwords tried: "+str(tries)
    					print "It took: "+str(time.time()-start)+" seconds"
    					sys.exit(1)
    if(len(sys.argv)==3):
    	bfcrackrar(sys.argv[1],sys.argv[2])
    else:
    	print sys.argv[0]+" wlist rarfile"
    	print "Example: "+sys.argv[0]+" /usr/share/john/password.lst test.rar"