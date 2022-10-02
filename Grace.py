def decl_main(body):
  exec(f'  def main():\n  {body}')
  return main

decl_main('print("hello")')()
