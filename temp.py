#! /usr/bin/python3

a = \
'''
NL = ord(10)

s = ''

# OUTSIDE!!
def ft():
  print()

def main():
  # INSIDE!!
  ft()

if __name__ == '__main__':
  main()
'''

a = a.strip().replace('\n', '{NL}')
print(a)