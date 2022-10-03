import sys

STR_IDENT = 's'

ESCAPE_MAP = {
  '%': ('%c', str(ord('%'))),
  '\n': ('%c', 'NL'),
  '"': ('%c', 'DQ'),
  '5': ('%d', 'i'),
  '$STR$': ('%s', STR_IDENT)
}

def get_var_token(string):
  var_ident = ''
  
  while string and string[0] != '$':
    var_ident += string[0]
    string = string[1:]
  
  if not string:
    raise ValueError("not closed variable declaration detected")
  
  return (f'${var_ident}$', string[1:])

def get_token(string):
  token = string[0]
  if token == '$':
    return get_var_token(string[1:])
  string = string[1:]
  return (token, string)

def escape(string):

  escaped_string = ''
  escape_values = []

  while string:
    token, remain = get_token(string)

    escape_info = ESCAPE_MAP.get(token)

    if escape_info:
      escape_format, escape_value = escape_info
      escape_values.append(escape_value)
      escaped_string += escape_format
    else:
      escaped_string += token
    
    string = remain

  return (escaped_string, escape_values)

def transform(original_string, escaped_string, escape_values):
  escape_values_as_string = f'{STR_IDENT} %% ({", ".join(escape_values)})'
  escaped_string = escaped_string.replace('$ARG$', escape_values_as_string)
  return original_string.replace('$STR$', escaped_string).replace('$ARG$', escape_values_as_string.replace('%%', '%'))

infile = sys.stdin.read()
string, values = escape(infile)
print(transform(infile, string, values), end='')
