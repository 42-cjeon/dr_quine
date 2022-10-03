import os

NL = chr(10)
DQ = chr(34)

s = "import os%c%cNL = chr(10)%cDQ = chr(34)%c%cs = %c%s%c%c%ci = %d%c%cdef main():%c  if i <= 0:%c    return%c  with open(f'Sully_{i - 1}.py', 'w') as f:%c    f.write(s %% (NL, NL, NL, NL, NL, DQ, s, DQ, NL, NL, i - 1, NL, NL, NL, NL, NL, NL, NL, NL, NL, NL))%c  os.execlp(f'python3', 'python3', f'./Sully_{i - 1}.py')%c%cif __name__ == '__main__':%c  main()"

i = 5

def main():
  if i <= 0:
    return
  with open(f'Sully_{i - 1}.py', 'w') as f:
    f.write(s % (NL, NL, NL, NL, NL, DQ, s, DQ, NL, NL, i - 1, NL, NL, NL, NL, NL, NL, NL, NL, NL, NL))
  os.execlp(f'python3', 'python3', f'./Sully_{i - 1}.py')

if __name__ == '__main__':
  main()