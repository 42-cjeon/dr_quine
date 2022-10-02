section .text
  global _main

  ; stdio.h
  extern _sprintf
  extern _fprintf
  extern _dprintf
  extern _fopen
  extern _fclose

  ; unistd.h
  extern _system
  extern _execlp

  ; err.h
  extern _err

  ; stdlib.h
  extern _exit

%define STRING !
%define AS_STRING(&x) x

_main:
  push rbp
  mov rbp, rsp
  sub rsp, 16

  mov dword [rsp], 5
  cmp dword [rsp], 0
  je _main_end
  sub dword [rsp], 1
  
  lea rdi, [rel out_source_name],
  lea rsi, [rel out_source_template]
  mov edx, [rsp]
  xor rax, rax
  call _sprintf

  lea rdi, [rel out_object_name],
  lea rsi, [rel out_object_template]
  mov edx, [rsp]
  xor rax, rax
  call _sprintf

  lea rdi, [rel out_binary_name],
  lea rsi, [rel out_binary_template]
  mov edx, [rsp]
  xor rax, rax
  call _sprintf

  lea rdi, [rel out_source_name]
  lea rsi, [rel flag_write_only]
  call _fopen

  cmp rax, 0
  jne open_success
  mov rdi, 1
  lea rsi, [rel fopen]
  call _err

open_success:
  mov [rsp + 8], rax
  mov rdi, rax
  lea rsi, [rel msg]
  lea rdx, [rel metamsg]
  mov ecx, [rsp]
  call _fprintf

  mov rdi, [rsp + 8]
  call _fclose

  lea rdi, [rel compile_cmd]
  lea rsi, [rel compile_cmd_template]
  lea rdx, [rel out_source_name]
  lea rcx, [rel out_binary_name]
  lea r8, [rel out_object_name]
  lea r9, [rel out_object_name]
  call _sprintf

  lea rdi, [rel compile_cmd]
  call _system

  cmp eax, 0
  jb system_error
  jne non_zero_error
  jmp system_success
system_error:
  mov edi, 2
  lea rsi, [rel system]
  call _err
non_zero_error:
  mov edi, 2
  lea rsi, [rel shell_non_zero]
  mov edx, eax
  mov ecx, 10
  call _dprintf
  mov edi, 3
  call _exit
system_success:
  lea rdi, [rel out_binary_name]
  mov rsi, 0
  call _execlp
  mov edi, 4,
  lea rsi, [rel exec]
  lea rdx, [rel out_binary_name]
  call _err

_main_end:
  mov rsp, rbp
  pop rbp
  xor rax, rax
  ret

section .bss
  out_source_name db 0x40 dup ?
  out_object_name db 0x40 dup ?
  out_binary_name db 0x40 dup ?
  compile_cmd db 0x400 dup ?

section .data
  out_source_template db './Sully_%d.s', 0
  out_object_template db './Sully_%d.o', 0
  out_binary_template db './Sully_%d', 0
  flag_write_only db 'w', 0
  fopen db 'fopen', 0
  system db 'system', 0
  shell_non_zero db 'system: shell exited with non-zero-value: %d\n', 0
  exec db 'exec: `%s`', 0
  compile_cmd_template db 'nasm -f macho64 %s && clang -Wall -Wextra -Werror -o %s %s && rm %s', 0

  msg db STRING, 0
  metamsg db AS_STRING(STRING), 0