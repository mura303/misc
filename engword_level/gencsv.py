import sys

dic = {}

for line in open('gakujiro-u.txt'):
	(a,b) = line.split('///')
	dic[a.rstrip()] = '\r\n'.join( b.split('\\')[:11] )

infile = open('svl-03.txt')

for i in range(10):
	outfile = open( "out-%02d.csv" % i, 'w' )
	for j in range(100):
		word = infile.readline().split(',')[1].rstrip()
		outfile.write( '%s,"%s"\n' % (word,dic[word]) )
