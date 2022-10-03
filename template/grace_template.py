NL = chr(10)
DQ = chr(34)

s = "$STR$"

def decl_main(body):
  exec(f'def main():{NL}  {body}', globals())

decl_main("print($ARG$, end='')")

# ANYWAY IT WORKS!
if __name__ == '__main__':
  main()