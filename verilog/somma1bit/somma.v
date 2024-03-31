module somma(
    input [0:0] in1,
    input [0:0] in2,
    output reg [0:0] out
);

/* 
Riscrivere il sommatore ad 1 bit descritto a gate level utilizzando gli
assegnamenti continui
*/
    assign xor(out, in1, in2);
    
endmodule