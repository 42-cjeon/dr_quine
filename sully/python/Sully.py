import os

NL = chr(10)
DQ = chr(34)

s = "import os%c%cNL = chr(10)%cDQ = chr(34)%c%cs = %c%s%c%c%ci = %d%c%cdef main():%c  global i%c  if i <= 0:%c    return%c  if os.path.basename(__file__) != 'Sully.py':%c    i -= 1%c  with open(f'Sully_{i}.py', 'w') as f:%c    f.write(s %% (NL, NL, NL, NL, NL, DQ, s, DQ, NL, NL, i, NL, NL, NL, NL, NL, NL, NL, NL, NL, NL, NL, NL, NL))%c  os.execlp(f'python3', 'python3', f'./Sully_{i}.py')%c%cif __name__ == '__main__':%c  main()"

i = 5

def main():
  global i
  if i <= 0:
    return
  if os.path.basename(__file__) != 'Sully.py':
    i -= 1
  with open(f'Sully_{i}.py', 'w') as f:
    f.write(s % (NL, NL, NL, NL, NL, DQ, s, DQ, NL, NL, i, NL, NL, NL, NL, NL, NL, NL, NL, NL, NL, NL, NL, NL))
  os.execlp(f'python3', 'python3', f'./Sully_{i}.py')

if __name__ == '__main__':
  main()