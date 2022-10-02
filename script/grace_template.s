section .text
  global _main
  extern _printf

%define STRING !
%define AS_STRING(&x) x

%macro DECL_FUNC 1
  %1:
    push rbp
    mov rbp, rsp
    sub rsp, 4
    mov byte [rsp], 37
    xor rax, rax
    lea rdi, [rel msg]
    mov rsi, 37
    lea rdx, [rel metamsg]
    mov rcx, 37
    mov r8, 37
    mov r9, 37
    call _printf
    xor rax, rax
    mov rsp, rbp,
    pop rbp
    ret
%endmacro

; ANYWAY IT WORKS.
DECL_FUNC _main

section .data
  msg db STRING, 0
  metamsg db AS_STRING(STRING), 0
