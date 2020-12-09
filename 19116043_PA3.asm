//19116043
.main:
	movu r0, 145
	mov r1, 0
	mov r2, 0
	mov r3, 1
	mov r4, 1
	call .factorion

.factorion:
    mov r5, 1                
mov r6, r0  
mov r7, 1    
mov r8, 0  
mov r9, 1 
mov r10,0
mov r11 ,1          
  .loop1:
          
       cmp r9, r6         
       bgt .breakee
       mod r7,r6,10 
	   add r10 ,r10 ,r7    
       .loop2:
		cmp r4, r7
		bgt .break
		mul r3, r3, r4
		add r4, r4, 1
		b .loop2  
	.break:	
	    mov r4,1
       add r8,r8,r3 
       div r6,r6,10
	   mov r3,1
        b .loop1

	.breakee:
	   mul r11,r10,r10
	   mul r11,r11,r10
	   b end 
	   b endl

end:
cmp r8,r0
beq return

b final

return:mov r1,1

final:.print r1

endl:
cmp r11,r0
beq returnl

b finall

returnl:mov r2,1


  finall:.print r2  
	
