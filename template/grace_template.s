section .text
  global _main
  extern _fprintf
  extern _fopen
  extern _err

%define STRING !
%define AS_STRING(&x) x

%macro DECL_FUNC 1
  %1:
    push rbp
    mov rbp, rsp
    lea rdi, [rel outfilename]
    lea rsi, [rel flag_write_only]
    call _fopen
    cmp rax, 0
    jne open_success
    mov edi, 1
    lea rsi, [rel fopen]
    call _err
  open_success:
    mov rdi, rax
    lea rsi, [rel msg]
    lea rdx, [rel metamsg]
    xor rax, rax
    call _fprintf
    xor rax, rax
    pop rbp
    ret
%endmacro

; ANYWAY IT WORKS.
DECL_FUNC _main

section .data
  msg db STRING, 0
  metamsg db AS_STRING(STRING), 0
  outfilename db "Grace_kid.s", 0
  flag_write_only db 'w', 0
  fopen db 'fopen', 0