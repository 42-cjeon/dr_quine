section .text
  global _main
  extern _printf

;OUTSIDE.

%define STRING !
%define AS_STRING(&x) x

_main:
  ;INSIDE.
  xor rax, rax
  lea rdi, [rel msg]
  mov rsi, 37
  lea rdx, [rel metamsg]
  mov rcx, 37
  call _printf
  xor rax, rax
  ret

section .data
  msg db STRING, 0
  metamsg db AS_STRING(STRING), 0
