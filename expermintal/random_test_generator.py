import sys
import random
import math


if (len(sys.argv) != 3 and len(sys.argv) != 4): sys.exit(-1)
m, n = sys.argv[1], sys. argv[2]

testStr = ''
if len(sys.argv) == 4:
  testStr += sys.argv[3] + '\n'

testStr = testStr + m + ' ' + n + '\n'

for i in range(int(m)):
  v = []
  for i in range(int(n)):
    v.append(str(math.floor(random.random() * 100)))
  testStr += ' '.join(v) + '\n'

f = open("./input.txt", "w")
f.write(testStr)
f.close()
print('Done')