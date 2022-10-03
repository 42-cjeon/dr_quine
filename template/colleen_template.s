section .text
  global _main
  extern _printf

;OUTSIDE.

%define STRING !
%define AS_STRING(&x) x

_main:
  ;INSIDE.
  call _ft
  xor rax, rax
  ret

_ft:
  xor rax, rax
  lea rdi, [rel msg]
  lea rsi, [rel metamsg]
  call _printf
  ret

section .data
  msg db STRING, 0
  metamsg db AS_STRING(STRING), 0
