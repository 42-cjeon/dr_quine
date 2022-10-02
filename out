NL = chr(10)

s = "NL = chr(10)%c%cs = %r%c%c# OUTSIDE!!%cdef ft():%c  print(s %% (NL, NL, s, NL, NL, NL, NL, NL, NL, NL, NL, NL, NL, NL), end='')%c%cdef main():%c  # INSIDE!!%c  ft()%c%cif __name__ == '__main__':%c  main()"

# OUTSIDE!!
def ft():
  print(s % (NL, NL, s, NL, NL, NL, NL, NL, NL, NL, NL, NL, NL, NL), end='')

def main():
  # INSIDE!!
  ft()

if __name__ == '__main__':
  main()