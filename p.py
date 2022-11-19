import re
with open("a.txt") as f:
	g=open("b.txt",'w')
	st=f.read()
	s=re.split("\t|\n",st)
	tot=0
	for i in s:
		if i=='':
			continue
		tot+=1
		if tot%3==1:
			g.write(i)
		elif tot%3==2:
			for j in i[4:]:
				if j==' ':
					continue
				if j=='|':
					g.write('/')
				elif j=='(':
					g.write('（')
				elif j==')':
					g.write('）')
				elif j=='_':
					g.write('\_')
				elif j=='&':
					g.write('\&')
				else:
					g.write(j)
		elif tot%3==0:
			g.write(i)
		g.write('\n')
	g.close()
