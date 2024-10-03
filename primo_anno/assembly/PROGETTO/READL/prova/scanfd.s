# l'indirizzo della stringa da convertire deve essere 
# stato caricato nel registro EAX
.section .text
.global scanfd

.type scanfd, @function 

scanfd:			
    leal num_str, %esi 		# metto indirizzo della stringa in esi 


    xorl %eax,%eax			# Azzero registri General Purpose
    xorl %ebx,%ebx           
    xorl %ecx,%ecx           
    xorl %edx,%edx
  

ripeti:
    movb (%ecx,%esi,1), %bl

    cmp $10, %bl             # vedo se e' stato letto il carattere '\n'
    je fine_atoi

    subb $48, %bl            # converte il codice ASCII della cifra nel numero corrisp.
    movl $10, %edx
    mulb %dl                # EBX = EBX * 10
    addl %ebx, %eax

    inc %ecx
    jmp ripeti

fine_atoi: 

    # risultato in %eax
    ret

