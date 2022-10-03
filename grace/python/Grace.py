NL = chr(10)
DQ = chr(34)

s = "NL = chr(10)%cDQ = chr(34)%c%cs = %c%s%c%c%cdef decl_main(body):%c  exec(f'def main():{NL}  {body}', globals())%c%cdecl_main(%cprint(s %% (NL, NL, NL, DQ, s, DQ, NL, NL, NL, NL, NL, DQ, DQ, NL, NL, NL, NL), end='')%c)%c%c# ANYWAY IT WORKS!%cif __name__ == '__main__':%c  main()"

def decl_main(body):
  exec(f'def main():{NL}  {body}', globals())

decl_main("print(s % (NL, NL, NL, DQ, s, DQ, NL, NL, NL, NL, NL, DQ, DQ, NL, NL, NL, NL), end='')")

# ANYWAY IT WORKS!
if __name__ == '__main__':
  main()