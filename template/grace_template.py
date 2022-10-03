NL = chr(10)
DQ = chr(34)

s = "$STR$"

def decl_func(name, body):
  exec(f'def {name}():{NL}  {body}', globals())

decl_func("write_file", "open('Grace_kid.py', 'w').write($ARG$)")
decl_func("main", "write_file()")

# ANYWAY IT WORKS!
if __name__ == '__main__':
  main()