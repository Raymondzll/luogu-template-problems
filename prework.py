import re
with open("origin.txt",'r',encoding='utf-8') as f:
    g=open("modified.txt",'w',encoding='utf-8')
    g.write('暂无评定 入门 普及- 普及/提高- 普及+/提高 提高+/省选- 省选/NOI- NOI/NOI+/CTSC\n')
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
