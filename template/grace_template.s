section .text
  global _main
  extern _printf

%define STRING !
%define AS_STRING(&x) x

%macro DECL_FUNC 1
  %1:
    push rbx
    xor rax, rax
    lea rdi, [rel msg]
    lea rsi, [rel metamsg]
    call _printf
    xor rax, rax
    pop rbx
    ret
%endmacro

; ANYWAY IT WORKS.
DECL_FUNC _main

section .data
  msg db STRING, 0
  metamsg db AS_STRING(STRING), 0
