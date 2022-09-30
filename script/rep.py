import sys

IDENT="s"

s = sys.stdin.read()

def escape(string):
  esc = []
  result = ""
  for c in string:
    if c == '"' or c == '\n' or c == '%':
      esc.append(f'{ord(c)}')
      result += "%c"
    elif c == "$":
      esc.append(IDENT)
      result += "%s"
    elif c == '5':
      esc.append('i')
      result += "%d"
    else:
      result += c
  return (result, esc)

esc_str, esc_char = escape(s)

esc_char = ', '.join([IDENT, *esc_char])

bind_s = s.replace('$', esc_str.replace('`', esc_char))
bind_s = bind_s.replace('`', esc_char)
print(bind_s)
