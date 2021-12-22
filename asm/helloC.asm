section .text
    global _start
    _start:
    ; 1 : syscall write()'s No
    mov rax, 1
    ; 1 : STDOUT's file descriptor
    mov rdi, 1              
    ; message to print out
    mov rsi, message        
    ; message's length
    mov rdx, [messageLen]       
    syscall
    
    ; 60: syscall exit()'s No
    mov rax, 60
    ; return 0
    mov rdi, 0
    syscall
    
section .data
    messageLen: dq message.end-message
    message: db 'Hello C!', 10
.end:
