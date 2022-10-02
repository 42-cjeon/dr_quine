import sys

s = sys.stdin.read()

escaped = s.replace('%', '%%')
escaped = escaped.replace('5', '%d')
escaped = escaped.replace('!', '%s')
escaped = ','.join(map(lambda x: str(ord(x)), escaped))

print(s.replace('!', escaped), end='')