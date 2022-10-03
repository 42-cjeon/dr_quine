NL = chr(10)
DQ = chr(34)

s = "NL = chr(10)%cDQ = chr(34)%c%cs = %c%s%c%c%cdef decl_func(name, body):%c  exec(f'def {name}():{NL}  {body}', globals())%c%cdecl_func(%cwrite_file%c, %copen('Grace_kid.py', 'w').write(s %% (NL, NL, NL, DQ, s, DQ, NL, NL, NL, NL, NL, DQ, DQ, DQ, DQ, NL, DQ, DQ, DQ, DQ, NL, NL, NL, NL))%c)%cdecl_func(%cmain%c, %cwrite_file()%c)%c%c# ANYWAY IT WORKS!%cif __name__ == '__main__':%c  main()"

def decl_func(name, body):
  exec(f'def {name}():{NL}  {body}', globals())

decl_func("write_file", "open('Grace_kid.py', 'w').write(s % (NL, NL, NL, DQ, s, DQ, NL, NL, NL, NL, NL, DQ, DQ, DQ, DQ, NL, DQ, DQ, DQ, DQ, NL, NL, NL, NL))")
decl_func("main", "write_file()")

# ANYWAY IT WORKS!
if __name__ == '__main__':
  main()