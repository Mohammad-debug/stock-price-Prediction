import sys

class c:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

if sys.argv[1] == sys.argv[2]:
  print(c.OKGREEN, 'Testcase', sys.argv[3], 'passed', c.ENDC)
else:
  print(c.FAIL, 'Testcase', sys.argv[3], 'failed \n actual: ', sys.argv[1], '\n', 'expected: ', sys.argv[2], c.ENDC)
  